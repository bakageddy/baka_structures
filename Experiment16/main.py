def linear(list, elem):
    for i, j in enumerate(list):
        if j == elem:
            return i
    return -1


hehe = list(map(int, input().strip().split()))
elem = int(input("Enter element: "))
print("Element found at index: ", linear(hehe, elem))
