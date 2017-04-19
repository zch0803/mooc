# coding:utf-8
from __future__ import print_function
from sklearn import datasets
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

loaded_data = datasets.load_boston()
data_X = loaded_data.data
data_y = loaded_data.target

model = LinearRegression()
model.fit(data_X, data_y)

print (model.predict(data_X[:4,:]))
print (model.coef_) #斜率
print (model.intercept_) #截距
print (model.get_params()) #参数
print (model.score(data_X,data_y)) #评分
