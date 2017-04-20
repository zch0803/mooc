import os
import pickle
from sklearn.datasets.base import Bunch

def readfile(path):
    fp = open(path,'rb')
    content = fp.read()
    fp.close()
    return content

bunch = Bunch(target_name=[], label=[], filenames=[], contents=[])
wordbag_path = "train_set.dat"
seg_path = "train/"

catelist = os.listdir(seg_path)
bunch.target_name.extend(catelist)
for mydir in catelist:
    class_path = seg_path+mydir+"/"
    file_list = os.listdir(class_path)
    for file_path in file_list:
        full_name = class_path + file_path
        bunch.label.append(mydir)
        bunch.filenames.append(full_name)
        bunch.contents.append(readfile(full_name).strip())

file_obj = open(wordbag_path, 'wb')
pickle.dump(bunch,file_obj)
file_obj.close()

print "bunch finished"
