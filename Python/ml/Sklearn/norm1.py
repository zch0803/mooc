# coding: utf-8
import numpy as np
from sklearn import preprocessing #标准化数据模块

a = np.array([[10,2.7,3.6],[-100,5,-2],[120,20,40]],dtype=np.float64)
print(preprocessing.scale(a))
