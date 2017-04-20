import os
from numpy import *
import numpy as np
def readfile(path):
    fp = open(path,'rb')
    content = fp.read()
    fp.close()
    return content

def distance(a,b):
    cosV12 = dot(a,b)/(linalg.norm(a)*linalg.norm(b))
    return cosV12

stppath = 'stpwords.txt'
stpwrdlst = readfile(stppath).splitlines()
wrdpath = 'word.txt'
wrd = readfile(wrdpath).split()

f = open('wrdvec.txt','r')
filenames = {}
for line in f.readlines():
    key, tmp = line.split(':')
    num = tmp.split()
    num = [int(i) for i in num]
    filenames[key] = num

length = 0
for key in filenames.keys():
    length = len(filenames[key])
    break
f.close()
#print filenames['0_25265644']
vec = []
for i in range(length):
    vec.append(0)
dist = {}
tdir = 'test/'
testfile = os.listdir(tdir)
err = 0
for n in range(len(testfile)):
    test = open(tdir+testfile[n],'r')
    content = test.read()
    content = content.replace('\r\n','').strip()
    tmp = content.split()
    for item in tmp:
        if item in wrd and item not in stpwrdlst:
            vec[wrd.index(item)] += 1
    test.close()

    for key in filenames.keys():
        dist[key] = distance(np.array(filenames[key]),np.array(vec))
        #print key,dist[key]
    result = sorted(dist.items(), key=lambda d: d[1])
    #print result[0]
    k = 5
    start = 20
    zero = 0
    one = 0
    for i in range(start,start+k):
        #print result[i]
        if result[i][0][0] == '0':
            zero += 1
        else:
            one += 1
    if zero > one:
        print 'predict: 0',
        print 'actual:', testfile[n][0]
        if testfile[n][0]!='0':
            err += 1
    else:
        print 'predict: 1',
        print 'actual:', testfile[n][0]
        if testfile[n][0]!='1':
            err += 1
print 'error', float(err)/float(len(testfile))
