#encoding:utf8
import xlrd, xlwt
import sys
reload(sys)
sys.setdefaultencoding('utf-8')

def iscost(arg):
    #print arg.decode(utf-8)
    if arg == u'间接费用':
        return 1
    elif arg == u'设备费':
        return 1
    elif arg == u'材料费':
        return 1
    elif arg == u'燃料动力费':
        return 1
    elif cmp(arg, '出版、信息、产权事务费')==0:
        return 1
    elif arg == u'差旅费':
        return 1
    elif arg == u'测试化验加工费':
        return 1
    elif arg == u'劳务费':
        return 1
    elif arg == u'专家咨询费':
        return 1
    else :
        return 0

def main():
    rbook = xlrd.open_workbook('output.xls')
    rsheet = rbook.sheet_by_index(0)

    nrows = rsheet.nrows
    cost = 0
    cost2013 = 0
    cost2014 = 0
    cost2015 = 0
    for i in range(1, nrows):
        if rsheet.row_values(i)[6] == '':
            continue
        a = rsheet.row_values(i)[12]
        b = rsheet.row_values(i)[6]
        c = rsheet.row_values(i)[3][3]
        if iscost(a):
            cost += b
            if c == '3':
                cost2013 += b
            elif c == '4':
                cost2014 += b
            elif c == '5':
                cost2015 += b
    with open("cost.txt",'w') as f:
        f.write("total cost:"+ str(cost)+"\n")
        f.write("2013 cost:"+ str(cost2013)+"\n")
        f.write("2014 cost:"+ str(cost2014)+"\n")
        f.write("2015 cost:"+ str(cost2015))
    print "total cost:", cost
    print "2013 cost:", cost2013
    print "2014 cost:", cost2014
    print "2015 cost:", cost2015

if __name__ == '__main__':
    main()
