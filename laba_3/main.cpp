// Частотный анализатор текстов. 2 “читающих” потока считывают данные из текста(-ов).
// Поток-интерфейс отвечает за взаимодействие с пользователем через командную строку.
// Пользователю доступны следующие команды: вывести на экран 5 самых распространённых на данный момент букв;
// вывести на экран вероятность появление буквы, введённой пользователем; выдать три самые редкие буквы.
// Внутренний поток обрабатывает запросы пользователя в соответствии с актуальной на данный момент информацией,
// собранной “читающими” потоками.

#include <iostream>
#include <fstream>
#include <thread>
#include <map>
#include <mutex>
#include <algorithm>

using namespace std;

void readFile(ifstream &fin, map<char, int> &letters, mutex &fileM, mutex &dictM, map<char, int> &maxi5,
              map<char, int> &mini3, int &count_chars) {
//    cout<<"ID потока = "<< this_thread::get_id()<<" readFile "<<endl;


    string str;
    if (fin.is_open()) {
        while (!fin.eof()) {
            {
                lock_guard<mutex> blockF(fileM);
                getline(fin, str);
            }  //TODO look
//            cout<<"Read file "<<endl; // TODO this test
            for (const char &i: str) {
                {
                    lock_guard<mutex> blockD(dictM);
                    letters[i]++;
                    count_chars ++;
                    // collection 5 max letter
                    if (maxi5.size() < 5 || maxi5.count(i)) {
                        maxi5[i] = letters[i];
                    } else {
                        auto temp = min_element(maxi5.begin(), maxi5.end(), [](const auto &a, const auto &b) -> bool {
                            return a.second < b.second;
                        });
                        if (temp->second < letters[i]) {
                            maxi5.erase(temp);
                            maxi5[i] = letters[i];
                        }
                    }
                    // 3 min letters TODO
                    mini3.clear();
                    for (auto &item: letters) {
                        if (mini3.size() < 3) {
                            mini3[item.first] = item.second;
                        } else {
                            auto temp = max_element(mini3.begin(), mini3.end(),
                                                    [](const auto &a, const auto &b) -> bool {
                                                        return a.second < b.second;
                                                    });
                            if (temp->second > item.second) {
                                mini3.erase(temp);
                                mini3[item.first] = item.second;
                            }
                        }
                    }
                }
//                this_thread::sleep_for(chrono::milliseconds(1500)); // TODO тест для проверки минимума и максимума
            }
        }
    } else {
        cout << "Do not read file" << endl;  //TODO this test
    }
    fin.close();
}

int main() {
    thread T1, T2;
    mutex fileM1, fileM2, dictM;
    string files[4]{"../first.txt", "../second.txt", "../third.txt", "../fourth.txt"};
    map<char, int> letters, maxi5, mini3;
    int count_chars = 0;
    ifstream file1("../first.txt");
    ifstream file2("../second.txt");
    T1 = thread(readFile, ref(file1), ref(letters), ref(fileM1), ref(dictM), ref(maxi5), ref(mini3), ref(count_chars));
    T2 = thread(readFile, ref(file2), ref(letters), ref(fileM2), ref(dictM), ref(maxi5), ref(mini3), ref(count_chars));


//    std::thread *threadReader = new std::thread[2];
    int answer = 5;
    while (answer) {
        std::cout << "Выбирите действие" << std::endl;
        std::cout << "0 - завершить работу" << std::endl;
        std::cout << "1 - вывести на экран 5 самых распространённых на данный момент букв" << std::endl;
        std::cout << "2 - вывести на экран вероятность появление буквы, введенной пользователем" << std::endl;
        std::cout << "3 - выдать три самые редкие буквы" << std::endl;
        std::cin >> answer;
        switch (answer) {
            case 1: {
                lock_guard<mutex> blockM(dictM);
                for (const auto &i:maxi5)
                    cout << i.first << " -> " << i.second << endl;
            };
                break;
            case 2: {
                std::cout << "Enter any letter " << std::endl;
                char letter;
                std::cin>>letter;
                double result = 0;
                {
                    lock_guard<mutex> blockM(dictM);
                    if (count_chars){
                        result = (letters[letter] * 1.0  / count_chars);
                    }
                }
                std::cout<<"Probability letter "<<letter<<" = "<<result<<std::endl;
            }
                break;
            case 3: {
                lock_guard<mutex> blockM(dictM);
                for (const auto &i:mini3)
                    cout << i.first << " -> " << i.second << endl;
            };
                break;
            case 4: {
                //  TODO  output map
                lock_guard<mutex> blockM(dictM);
                for (const auto &i:letters)
                    cout << i.first << " -> " << i.second << endl;
                    cout << "count letters " <<count_chars<< endl;
            }
        }
    }

    T1.join();
    T2.join();
    return 0;
}
