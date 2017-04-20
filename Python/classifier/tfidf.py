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

path = 'train_set.dat'
bunch = readbunch(path)
#print bunch.label
#print bunch.filenames
tfidfspace = Bunch(target_name=bunch.target_name, label=bunch.label, filenames=bunch.filenames, tdm=[], vocabulary={})

vectorizer = TfidfVectorizer(stop_words=stpwrdlst, sublinear_tf=True, max_df=0.5)
transformer = TfidfTransformer()
tfidfspace.tdm = vectorizer.fit_transform(bunch.contents)
tfidfspace.vocabulary = vectorizer.vocabulary_

space_path = 'tfidfspace.dat'
writebunch(space_path,tfidfspace)
