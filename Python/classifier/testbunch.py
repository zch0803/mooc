import os
import pickle
from sklearn.datasets.base import Bunch

def readfile(path):
    fp = open(path,'rb')
    content = fp.read()
    fp.close()
    return content

bunch = Bunch(target_name=[], label=[], filenames=[], contents=[])
wordbag_path = "test_set.dat"
seg_path = "test/"

catelist = os.listdir(seg_path)
bunch.target_name.extend(seg_path)
for myfile in catelist:
    full_name = seg_path + myfile
    bunch.label.append(myfile)
    bunch.filenames.append(full_name)
    bunch.contents.append(readfile(full_name).strip())

file_obj = open(wordbag_path, 'wb')
pickle.dump(bunch,file_obj)
file_obj.close()

print "bunch finished"
