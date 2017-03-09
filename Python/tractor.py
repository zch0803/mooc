# encoding:utf-8
# 扑克牌拖拉机游戏
# 两个玩家的初始牌[2 4 1 2 5 6] [3 1 3 5 6 4]

def isequal(arg, num):
    flag = -1
    index = 0
    for i in arg:
        if i == num:
            flag = index
            break
        index+=1
    return flag

def main():
    player1 = [2, 4, 1, 2, 5, 6]
    player2 = [3, 1, 3, 5, 6, 4]
    table = []
    while player1 and player2:
        index = isequal(table, player1[0])
        if index != -1:
            player1.append(player1[0])
            b = table[index:]
            b.reverse()
            player1.extend(b)
            table = table[0: index]
        else:
            table.append(player1[0])
        player1.pop(0)
        print "player1:", player1
        print "player2:", player2
        print "table:", table
        if player1 == [] or player2 == []:
            break
        index = isequal(table, player2[0])
        if  index != -1:
            player2.append(player2[0])
            b = table[index:]
            b.reverse()
            player2.extend(b)
            table = table[0: index]
        else:
            table.append(player2[0])
        player2.pop(0)
        print "player1:", player1
        print "player2:", player2
        print "table:", table
    print player1
    print player2
    print table
    if player1 :
        print "player1 win!"
    else :
        print "player2 win!"

if __name__ == '__main__':
    main()
