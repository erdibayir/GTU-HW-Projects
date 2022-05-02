def lomutoPartition(arr, l, r):
    pivot = arr[r]
    s = l
    for j in range(l, r):
        if arr[j] <= pivot:
            arr[s], arr[j] = swap(arr[s], arr[j])
            s += 1

    arr[s], arr[r] = swap(arr[s], arr[r])
    return s


def swap(n1, n2):
    return n2, n1


def meaningful(arr, l, r, k):
    if (k > 0 and k <= (r - l + 1)):
        s = lomutoPartition(arr, l, r)
        if (s == l + k - 1):
            return arr[s]
        if (l + k - 1 < s):
            return meaningful(arr, l, s - 1, k)
        else:
            return meaningful(arr, s + 1, r, k - s + l - 1)


experiments = [6, 2, 9, 4, 3, 12]
length = len(experiments)
k = 4
print("The success rate of the first meaningful", k,
      "th experiment is", meaningful(experiments, 0, length-1, k))
