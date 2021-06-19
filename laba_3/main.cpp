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

using namespace std;

void readFile(string fileName, map<char, int> &letters){
//    cout<<"ID потока = "<< this_thread::get_id()<<" readFile "<<endl;
//    this_thread::sleep_for(chrono::milliseconds(500));
    string str;
    ifstream fin;
    fin.open(fileName);
    if (fin.is_open()){
        fin >> str;  // fixme  как читает?
        cout<<"Read file "<<endl;
        for (char i: str){
            if (letters.contains(i)){
                letters[i]++;
            }
            else
                letters[i]=1;
        }
    } else {
        cout<<"Do not read file"<<endl;
    }
    fin.close();
}

int main() {
    thread T1, T2;

    string files[4] {"../first.txt", "../second.txt", "../third.txt", "../fourth.txt"};
    map<char, int> letters;
//    for (auto fileName: files)
//        readFile(fileName, letters);
    T1 = thread(readFile, "../first.txt", ref(letters) );
    T1.join();
//    output map
    for (auto i:letters)
        cout<<i.first<<" -> "<<i.second<<endl;


//    cout<<letters.contains('v')<<endl;


//    std::thread *threadReader = new std::thread[2];
    int answer = 3;
    while (answer){
        std::cout<<"Выбирите действие"<<std::endl;
        std::cout<<"0 - завершить работу"<<std::endl;
        std::cout<<"1 - вывести на экран 5 самых распространённых на данный момент букв"<<std::endl;
        std::cout<<"2 - вывести на экран вероятность появление буквы, введенной пользователем"<<std::endl;
        std::cout<<"3 - выдать три самые редкие буквы"<<std::endl;
        std::cin>>answer;
        switch (answer) {
            case 1: std::cout<<"function five"<<std::endl; break;
            case 2: std::cout<<"function letter"<<std::endl; break;
            case 3: std::cout<<"function three"<<std::endl; break;
        }
    }

    return 0;
}
