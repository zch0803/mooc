#!/usr/bin/env python
# -*- coding: utf-8 -*-

import string
import sys

def caculate(a, b, cac):
    if cac == '+':
        return int(a) + int(b)
    elif cac == '-':
        return int(a) - int(b)
    elif cac == '*':
        return int(a) * int(b)
    elif cac == '/':
        return int(a) / int(b)
    else:
        raise TypeError('bad oprand type')

def analystr(L):
    if L.find('+') != -1:
        cac = L.find('+')
    elif L.find('-') != -1:
        cac = L.find('-')
    elif L.find('*') != -1:
        cac = L.find('*')
    elif L.find('/') != -1:
        cac = L.find('/')
    else:
        print 'this is not a caculator'
        return

    X = L.split(L[cac])
    print caculate(X[0], X[1], L[cac])

if __name__ == '__main__':
    print u'''欢迎使用程序，请输入你的操作
    1. 屏幕计算
    2. 文件计算
    0. 退出'''

    a = raw_input()
    if a == '1':
        print u"请输入您的等式："
        L = raw_input()
        analystr(L)
    elif a == '2':
        print u"请输入您的文件名："
        filename = raw_input()
        with open(filename,'r') as f:
            for line in f.readlines():
                #print line
                analystr(line)
    else:
        print u"退出成功！"
        exit
