class Node:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.left = None

def insert(cursor, target, left, right):
    if cursor:
        if cursor.val == target:
            cursor.left = left
            cursor.right = right
            return
        insert(cursor.left, target, left, right)
        insert(cursor.right, target, left, right)

def preorder(cursor):
    if cursor:
        if cursor.val != ".":
            print(cursor.val, end='')
        preorder(cursor.left)
        preorder(cursor.right)

def inorder(cursor):
    if cursor:
        inorder(cursor.left)
        if cursor.val != ".":
            print(cursor.val, end='')
        inorder(cursor.right)

def postorder(cursor):
    if cursor:
        postorder(cursor.left)
        postorder(cursor.right)
        if cursor.val != ".":
            print(cursor.val, end='')

head = None
node_count = int(input())
for _ in range(node_count):
    now, left, right = input().split(" ")
    if not head:
        head = Node(now)
        head.left = Node(left)
        head.right = Node(right)
    else:
        cursor = head
        insert(cursor, now, Node(left), Node(right))

preorder(head)
print()
inorder(head)
print()
postorder(head)
