import os

def readfile(path):
    fp = open(path,'rb')
    content = fp.read()
    fp.close()
    return content

stppath = 'stpwords.txt'
stpwrdlst = readfile(stppath).splitlines()
#print type(stpwrdlst)
wrd = []
num = []
train_path = 'train/'
cate_path = os.listdir(train_path)
for mydir in cate_path:
    class_path = train_path + mydir + '/'
    file_list = os.listdir(class_path)
    for file_ in file_list:
        content = readfile(class_path+file_)
        content = content.replace('\r\n','').strip()
        tmp = content.split()
        for item in tmp:
            if item not in wrd and item not in stpwrdlst:
                wrd.append(item)
                num.append(0)
fout = open('word.txt','w')
for i in range(len(wrd)):
    fout.write(wrd[i]+' ')
fout.close()
'''
fout = open('wrdvec.txt','w')
for mydir in cate_path:
    class_path = train_path + mydir + '/'
    file_list = os.listdir(class_path)
    for file_ in file_list:
        content = readfile(class_path+file_)
        content = content.replace('\r\n','').strip()
        tmp = content.split()
        #print filenames[file_]
        for j in range(len(num)):
            num[j] = 0
        for item in tmp:
            if item in wrd and item not in stpwrdlst:
                num[wrd.index(item)] += 1
        #print filenames[file_]
        fout.write(file_+':')
        for j in range(len(num)):
            fout.write(str(num[j])+' ')
        fout.write('\n')
fout.close()
'''
