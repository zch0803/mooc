# -*- coding: utf-8 -*-
from sklearn.naive_bayes import MultinomialNB
import pickle
def readbunch(path):
    file_obj = open(path,'rb')
    bunch = pickle.load(file_obj)
    file_obj.close()
    return bunch

train_path = 'tfidfspace.dat'
train_set = readbunch(train_path)

test_path = 'testspace.dat'
test_set = readbunch(test_path)

clf = MultinomialNB(alpha = 0.001).fit(train_set.tdm, train_set.label)

predicted = clf.predict(test_set.tdm)
total = len(predicted)
rate = 0
for flabel,file_name,expct_cate in zip(test_set.label,test_set.filenames,predicted):
    print file_name,":actual cate:",flabel,"-->predict cate:",expct_cate
    if flabel[0]!=expct_cate:
        rate += 1
print 'error rate:',float(rate)/float(total)
