#encoding:utf-8
#输入一个数，求连续正整数加起来的和等于它
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('num', type=int)
args = parser.parse_args()

num = args.num
#暴力算法比较笨
'''
for i in range(1, num/2+1):
    Sum = 0
    for j in range(i, num):
        Sum = Sum + j
        if Sum >= num:
            break
    if Sum == num:
        print i, j
'''
#应用高斯公式，设初值为x，项数为n，则nx+n(n-1)/2=num x=(num-n(n-1)/2)/n只需判断x是否是整数即可
mid = num/2+1
for n in range(2,mid):
    x = (num - n*(n-1)/2)%n
    if x==0:
        x = (num - n*(n-1)/2)/n
        if x>0:
            print x, x+n-1
        else: break
