import numpy as np

def main():
    n = int(raw_input())
    the_max = n * (n+1) / 2
    a = np.zeros((n, n), dtype=int)
    length = 0
    number = 1
    while number <= the_max :
        if number == the_max:
            a[length*2][length] = number
            break
        for i in range(0, n-1-length*3):
            a[i+length*2][length] = number
            number += 1
        if number > the_max:
            break
        for i in range(0, n-1-length*3):
            a[n-1-length][i+length] = number
            number += 1
        if number > the_max:
            break
        for i in range(0, n-1-length*3):
            a[n-1-length-i][n-1-length*2-i] = number
            number += 1
        length += 1
    for i in range(0, n):
        for j in range(0,i+1):
            if a[i][j] < 10:
                print "",
            print a[i][j],
        print "\n"

if __name__ == '__main__':
    main()
