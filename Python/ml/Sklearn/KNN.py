# coding:utf-8
import numpy as np
from sklearn import datasets
#from sklearn.corss_validation import train_test_split <0.18
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier

iris = datasets.load_iris()
iris_X = iris.data
iris_y = iris.target

print(iris_X.shape) #前面的冒号是代表第几行到第几行，后面的冒号是第几列到第几列
print(iris_y.shape) #shape为[150,]和[150,1]的区别在于前者为向量，后者为矩阵

X_train, X_test, y_train, y_test = train_test_split(iris_X, iris_y, test_size=0.3)

knn = KNeighborsClassifier()
knn.fit(X_train,y_train)
print y_test == knn.predict(X_test)
