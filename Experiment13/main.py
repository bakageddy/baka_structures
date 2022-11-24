def bubble(list):
    for i in range(len(list)):
        for j in range(len(list) - 1):
            if (list[j] > list[j + 1]):
                list[j], list[j + 1] = list[j + 1], list[j]
    return list


# Enter the elements separated by spaces
# like this
# Input: 1 2 3 4 5
listOfElem = list(map(int, input().split()))
print(listOfElem)
print(bubble(listOfElem))
