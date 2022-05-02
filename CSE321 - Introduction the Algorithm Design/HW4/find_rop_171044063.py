def merge(arr, l, r):
    i = 0
    j = 0
    count = 0
    while (i < len(l) or j < len(r)):
        if (i == len(l)):
            arr[i+j] = r[j]
            j += 1
        elif (j == len(r)):
            arr[i+j] = l[i]
            i += 1
        elif (l[i] <= r[j]):
            arr[i+j] = l[i]
            i += 1
        else:
            arr[i+j] = r[j]
            count += len(l)-i
            j += 1
    return count


def findRop(arr):
    length = len(arr)
    if(length < 2):
        return 0
    m = (length + 1) / 2
    l = arr[0:int(m)]
    r = arr[int(m):int(length)]
    return findRop(l) + findRop(r) + merge(arr, l, r)


informations = [3, 12, 2, 1, 7]
reverseOrdered = findRop(informations)
print("The number of reverse-ordered pairs is ", reverseOrdered)
