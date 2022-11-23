class Stack:
    def __init__(self):
        self.stack = list()

    def push(self, elem):
        self.stack.append(elem)

    def pop(self):
        return self.stack.pop()


s = Stack()
while True:
    print("1. Push")
    print("2. Pop")
    print("3. Display")
    print("4. Quit")
    opt = int(input("Enter your option: "))
    if (opt == 1):
        elem = int(input("Enter the element: "))
        s.push(elem)
    elif (opt == 2):
        elem = s.pop()
        print("Deleted: ", elem)
    elif (opt == 3):
        print(s.stack)
    elif (opt == 4):
        break
    else:
        print("Wrong Option!")
