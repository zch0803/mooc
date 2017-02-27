#!/usr/bin/env python
# -*- coding: utf-8 -*-

import xlrd, xlwt
import operator

data1 = xlrd.open_workbook('/Users/zch/Documents/训练作业/python/20160309/123A11-2013.xlsx')
table1 = data1.sheet_by_index(0)

data2 = xlrd.open_workbook('/Users/zch/Documents/训练作业/python/20160309/123A11-2014.xlsx')
table2 = data2.sheet_by_index(0)

data3 = xlrd.open_workbook('/Users/zch/Documents/训练作业/python/20160309/123A11-2014.xlsx')
table3 = data3.sheet_by_index(0)

table = []
title = table1.row_values(0)
for i in range(1, table1.nrows):
    table.append(table1.row_values(i))
for i in range(1, table2.nrows):
    table.append(table2.row_values(i))
for i in range(1, table3.nrows):
    table.append(table3.row_values(i))

table.sort(key=operator.itemgetter(1))

wbook = xlwt.Workbook()
wsheet = wbook.add_sheet('2013')
style = xlwt.easyxf('font: bold 1')
for i in range(len(title)):
    wsheet.write(0,i,title[i],style)

for r in range(len(table)):
    for c in range(len(table[r])):
        wsheet.write(r+1,c,table[r][c],style)
wbook.save('output.xls')
