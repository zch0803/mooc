

def main():
    n=int(raw_input())
    mylist = range(1, n+1)
    while len(mylist)>1:
        mylist.append(mylist[0])
        mylist.pop(0)
        mylist.append(mylist[0])
        mylist.pop(0)
        print mylist[0]
        mylist.pop(0)
        print mylist

if __name__ == '__main__':
    main()
