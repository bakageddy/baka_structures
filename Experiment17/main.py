def search(list, elem):
    mid = len(list) // 2
    if (list == []):
        return -1
    if (list[mid] == elem):
        return mid
    elif (list[mid] >= elem):
        return search(list[:mid], elem)
    else:
        return search(list[mid + 1:], elem)


hehe = list(map(int, input().strip().split()))
elem = int(input("Enter the element: "))
if not sorted(hehe):
    print("Sort the input first! Baka!")
print("Element found at index: ", search(hehe, elem))
