import matplotlib.pyplot as plt
import csv
import collections


class Node:

    def __init__(self, data, index):
        self.left = None
        self.right = None
        self.data = data
        self.index = index

    def insert(self, data, index):
        if self.data:
            if self.left:
                if self.right is None:
                    self.right = Node(data,index)
                else:
                    self.right.insert(data,index)
            else:
                if self.left is None:
                    self.left = Node(data,index)
                else:
                    self.left.insert(data,index)
        else:
            self.data = data
            self.index=index

def height(node):
    if node is None:
        return 0
    else:
        # Compute the height of each subtree
        lheight = height(node.left)
        rheight = height(node.right)

        # Use the larger one
        if lheight > rheight:
            return lheight + 1
        else:
            return rheight + 1

def printLevelOrder(root):
    def printCurrentLevel(root, level):
        if root is None:
            return
        if level == 1:
            print(root.index, root.data, sep=",", end="\n")
        elif level > 1:
            printCurrentLevel(root.left, level - 1)
            printCurrentLevel(root.right, level - 1)
    h = height(root)
    for i in range(1, h + 1):
        printCurrentLevel(root, i)

def shift(root ,shift):
        def shiftCurrentLevel(root, level, shift):
            if root is None:
                return
            if level == 1:
                root.index = root.index - shift
            elif level > 1:
                shiftCurrentLevel(root.left, level - 1, shift)
                shiftCurrentLevel(root.right, level - 1, shift)
        h = height(root)
        for i in range(1, h + 1):
            shiftCurrentLevel(root, i, shift)


def scale(root, scale):
        def scaleCurrentLevel(root, level, scale):
            if root is None:
                return
            if level == 1:
                root.data = root.data/scale
            elif level > 1:
                scaleCurrentLevel(root.left, level - 1, scale)
                scaleCurrentLevel(root.right, level - 1, scale)
        h = height(root)
        for i in range(1, h + 1):
            scaleCurrentLevel(root, i, scale)



def values(root):
    ans = []

    # Return Null if the tree is empty
    if root is None:
        return ans

    # Initialize queue
    queue = collections.deque()
    queue.append(root)

    # Iterate over the queue until it's empty
    while queue:
        # Check the length of queue
        currSize = len(queue)
        currList = []

        while currSize > 0:
            # Dequeue element
            currNode = queue.popleft()
            currList.append(currNode.data)
            currSize -= 1

            # Check for left child
            if currNode.left is not None:
                queue.append(currNode.left)
            # Check for right child
            if currNode.right is not None:
                queue.append(currNode.right)

        # Append the currList to answer after each iteration
        for i in currList:
            ans.append(i)

    # Return answer list
    return ans

def index(root):
    ans = []

    # Return Null if the tree is empty
    if root is None:
        return ans

    # Initialize queue
    queue = collections.deque()
    queue.append(root)

    # Iterate over the queue until it's empty
    while queue:
        # Check the length of queue
        currSize = len(queue)
        currList = []

        while currSize > 0:
            # Dequeue element
            currNode = queue.popleft()
            currList.append(currNode.index)
            currSize -= 1

            # Check for left child
            if currNode.left is not None:
                queue.append(currNode.left)
            # Check for right child
            if currNode.right is not None:
                queue.append(currNode.right)

        # Append the currList to answer after each iteration
        for i in currList:
            ans.append(i)

    # Return answer list
    return ans

def plot(root):
    y = values(rooti)
    x = index(rooti)
    plt.rcParams["figure.figsize"] = [7.50, 3.50]
    plt.rcParams["figure.autolayout"] = True
    markerline, stemlines, baseline = plt.stem(x, y, linefmt='grey', markerfmt='*')
    markerline.set_markerfacecolor('red')
    plt.show()

rooti = Node(0,0)
inpt = str(input("Enter the signal: "))
with open(inpt, "r") as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for lines in csv_reader:
        rooti.insert(float(lines[1]),float(lines[0]))

printLevelOrder(rooti)
plot(rooti)
sft = float(input('\nEnter the shifting factor: '))
scle = float(input('\nEnter the scaling factor: '))
shift(rooti,sft)
scale(rooti,scle)

printLevelOrder(rooti)
plot(rooti)