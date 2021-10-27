def check_polindrome(st):
    s2 = st[::-1]
    if st == s2:
        return True
    return False


s = input('-> ')
print(check_polindrome(s))

# s2 = s[::-1]
# if s == s2:
#     print('Ok')
# else:
#     print('No')