# -*- coding: utf-8 -*-
import sys
import os
from sklearn.datasets.base import Bunch
import pickle
from sklearn import feature_extraction
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import TfidfVectorizer

def readbunch(path):
    file_obj = open(path,'rb')
    bunch = pickle.load(file_obj)
    file_obj.close()
    return bunch

def writebunch(path,bunchobj):
    file_obj = open(path,'wb')
    pickle.dump(bunchobj,file_obj)
    file_obj.close()

def readfile(path):
    fp = open(path,'rb')
    content = fp.read()
    fp.close()
    return content

stppath = 'stpwords.txt'
stpwrdlst = readfile(stppath).splitlines()

path = 'test_set.dat'
bunch = readbunch(path)

testspace = Bunch(target_name=bunch.target_name,label=bunch.label,filenames=bunch.filenames,tdm=[],vocabulary={})

trainbunch = readbunch('tfidfspace.dat')

vectorizer = TfidfVectorizer(stop_words=stpwrdlst, sublinear_tf=True, max_df=0.5, vocabulary=trainbunch.vocabulary)
transformer = TfidfTransformer()
testspace.tdm = vectorizer.fit_transform(bunch.contents)
testspace.vocabulary = trainbunch.vocabulary

space_path = 'testspace.dat'
writebunch(space_path,testspace)
