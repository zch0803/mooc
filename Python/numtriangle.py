num = int(raw_input("please input a num 1-10: "))

a = []
Sum = num*(num+1)/2
tmp = 1
for i in range(num):
    a.append([])
    for j in range(i+1):
        a[i].append(0)

border = num
i = 0
j = 0
while tmp <= Sum:
    while i < border and a[i][j]==0:
        a[i][j]=tmp
        tmp += 1
        i += 1
    j += 1
    i -= 1
    if tmp > Sum:
        break
    while j < border and a[i][j]==0:
        a[i][j]=tmp
        tmp += 1
        j += 1
    j -= 1
    i -= 1
    j -= 1
    if tmp > Sum:
        break
    while a[i][j]==0:
        a[i][j]=tmp
        i -= 1
        j -= 1
        tmp += 1
    j += 1
    i += 2
    border -= 1
for k in range(len(a)):
    for l in range(len(a[k])):
        print a[k][l],
    print ""
