import math
import functools

def tran(str):
    return str[0].upper()+str[1:].lower()

def prod(X):
    return reduce(add, X)

def cmp_ignore_case(s1, s2):
    u1 = s1.lower()
    u2 = s2.lower()
    if u1 < u2:
        return -1
    else:
        return 1
    return 0

def log(*text):
    def deracotor(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            if text:
                print '%s begin call %s:' % (text[0], func.__name__)
                func(*args, **kw)
                print '%s end call %s:' % (text[0], func.__name__)
            else:
                print 'begin call %s:' % func.__name__
                func(*args, **kw)
                print 'end call %s:' % func.__name__
        return wrapper
    return deracotor


@log()
def now():
    print 'now'

def add(x, y):
    return x + y

if __name__ == '__main__':

#    L = ['adam', 'LISA', 'barT']
#    X = sorted(L, cmp_ignore_case)
#    print X
#   print map(tran,L)
#   X = [1, 2, 3, 4, 5]
#   print prod(X)
    now()
#    d = {'x':'A', 'y':'B', 'z':'C'}
#    for k, v in d.iteritems():
#        print k, '=', v
