class Array:
    def __init__(self):
        self.items = list()
        self.MAX = 20

    def insert(self, index, obj):
        if len(self.items) <= self.MAX:
            self.items.insert(index, obj)
        else:
            print("OVERFLOW")

    def delete(self, index):
        if len(self.items) != 0:
            self.items.pop(index)
        else:
            print("UNDERFLOW")

    def search(self, obj):
        return self.items.index(obj)

    def print(self):
        print(self.items)

    def insertAtEnd(self, elem):
        self.items.append(elem)

    def insertAtStart(self, elem):
        self.insert(0, elem)

    def deleteAtEnd(self):
        self.delete(-1)

    def deleteAtStart(self):
        self.delete(0)


array = Array()
while True:
    print("""1. Insert
2. Insert At End
3. Insert At Start
4. Delete
5. Delete At End
6. Delete At Start
7. Search
8. Display
9. Quit""")
    option = int(input("Enter your option: "))
    if option == 1:
        elem = int(input("Enter element: "))
        index = int(input("Enter the index: "))
        array.insert(index, elem)
    elif option == 2:
        elem = int(input("Enter your element: "))
        array.insertAtEnd(elem)
    elif option == 3:
        elem = int(input("Enter your element: "))
        array.insertAtStart(elem)
    elif option == 4:
        index = int(input("Enter the index: "))
        array.delete(index)
    elif option == 5:
        array.deleteAtEnd()
    elif option == 6:
        array.deleteAtStart()
    elif option == 7:
        elem = int(input("Enter the element: "))
        index = array.search(elem)
        print("Found the element at: ", index)
    elif option == 8:
        array.print()
    elif option == 9:
        break
    else:
        print("Wrong Option!")
        continue


