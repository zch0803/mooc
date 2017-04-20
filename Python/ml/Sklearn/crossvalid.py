# coding:utf-8
import numpy as np
from sklearn import datasets
#from sklearn.corss_validation import train_test_split <0.18
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
from sklearn.neighbors import KNeighborsClassifier
import matplotlib.pyplot as plt

#------------------------------**基础验证法---------------------------------------
iris = datasets.load_iris()
iris_X = iris.data
iris_y = iris.target

X_train, X_test, y_train, y_test = train_test_split(iris_X, iris_y, test_size=0.3)

knn = KNeighborsClassifier()
knn.fit(X_train,y_train)
print (knn.score(X_test,y_test))

#-----------------------------**交叉验证-----------------------------------------

scores = cross_val_score(knn, iris_X, iris_y, cv=5, scoring='accuracy')
print(scores)
print(scores.mean())
#-----------------------------**交叉验证准确率------------------------------------

k_range = range(1,31)
k_scores = []
for k in k_range:
    knn = KNeighborsClassifier(n_neighbors=k)
    scores = cross_val_score(knn,iris_X,iris_y,cv=10,scoring='accuracy')
    k_scores.append(scores.mean())

plt.plot(k_range,k_scores)
plt.xlabel('Value of K for KNN')
plt.ylabel('Cross-Validated Accuracy')
plt.show()

#-----------------------------**交叉验证平方均差-----------------------------------
k_range = range(1,31)
k_scores = []
for k in k_range:
    knn = KNeighborsClassifier(n_neighbors=k)
    loss = cross_val_score(knn,iris_X,iris_y,cv=10,scoring='neg_mean_squared_error')## mean_squared_error <0.18
    k_scores.append(loss.mean())

plt.plot(k_range,k_scores)
plt.xlabel('Value of K for KNN')
plt.ylabel('Cross-Validated MSE')
plt.show()
