def string_to_array(s):
    if s:
        return s.split()
    return ['']


s1 = "Robin Singh"  # ["Robin", "Singh"]
s2 = ""  # [""])
s3 = "I love arrays they are my favorite"  # ["I", "love", "arrays", "they", "are", "my", "favorite"]
s4 = "lkj lkj ,.an.m iopup"

print(string_to_array(s2))