# -*- coding: utf-8 -*-
import os
from sklearn.datasets.base import Bunch
import pickle
from sklearn import feature_extraction
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.svm import LinearSVC
import numpy as np
from sklearn import metrics
from sklearn import preprocessing

def readbunch(path):
    file_obj = open(path,'rb')
    bunch = pickle.load(file_obj)
    file_obj.close()
    return bunch

def metrics_result(actual,predict):
    print 'precise', metrics.precision_score(actual,predict,average='binary')
    print 'recall', metrics.recall_score(actual,predict,average='binary')
    print 'f1_score', metrics.f1_score(actual,predict,average='binary')

train_path = 'tfidfspace.dat'
train_set = readbunch(train_path)

test_path = 'testspace.dat'
test_set = readbunch(test_path)

print train_set.tdm
print '============================================'
print test_set.tdm

'''
clf = LinearSVC(penalty='l2',dual=False,tol=1e-2).fit(train_set.tdm,train_set.label)

predicted = clf.predict(test_set.tdm)
total = len(predicted)
rate = 0
for flabel,file_name,expct_cate in zip(test_set.label,test_set.filenames,predicted):
    #print file_name,":actual cate:",flabel,"-->predict cate:",expct_cate
    if flabel[0]!=expct_cate:
        rate += 1
print 'error rate:',float(rate)/float(total)

actual = [i[0] for i in test_set.label]
actual = [int(i) for i in actual]
predicted = [int(i) for i in predicted]
metrics_result(actual,predicted)
'''
