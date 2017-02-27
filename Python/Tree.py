class Tree(object):
    """docstring for Tree."""
    def __init__(self, left, right):
        self.left = left
        self.right = right

t = Tree(Tree("a","b"),Tree("a","b"))
print t.right.left
