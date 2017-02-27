import argparse

def trans(arg):
    string = ''
    while arg > 0:
        a = arg % 2
        string +=  str(a)
        arg /= 2
    return string

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('num1', type=int)
    parser.add_argument('num2', type=int)
    args = parser.parse_args()

    num1 = args.num1
    num2 = args.num2
    str1 = trans(num1)
    str2 = trans(num2)
    len1 = len(str1)
    len2 = len(str2)
    result = 0
    if len1 > len2:
        for i in range(len2):
            if str1[i] != str2[i]:
                result += 1
        for i in range(len2, len1):
            if str1[i] == 1:
                result += 1
    else:
        for i in range(len1):
            if str1[i] != str2[i]:
                result += 1
        for i in range(len1, len2):
            if str2[i] == 1:
                result += 1
    print result

if __name__ == '__main__':
    main()
