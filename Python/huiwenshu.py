#求100000以内的回文数
def ishuiwenshu(arg):
    length = len(arg)
    if length==1:
        return 1
    elif length==2 :
        if arg[0] == arg[1]:
            return 1
        else :
            return 0
    else:
        if arg[0] == arg[length-1]:
            return ishuiwenshu(arg[1:length-1])
        else :
            return 0


def main():
    for i in range(0, 100000):
        str_num = str(i)
        if ishuiwenshu(str_num):
            print i

if __name__ == '__main__':
    main()
