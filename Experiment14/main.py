def select(list):
    for i in range(len(list)):
        min = i
        for j in range(i + 1, len(list)):
            if list[min] > list[j]:
                min = j
        list[i], list[min] = list[min], list[i]
    return list


# Enter the elements like the following
# Input: 1 2 3 4
hehe = list(map(int, input().strip().split()))
print(hehe)
print(select(hehe))
