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


def quick_sort(arr, l, r,):
    if (l < r):
        p = lomutoPartition(arr, l, r)
        quick_sort(arr, l, p - 1)
        quick_sort(arr, p + 1, r)


experiments = [6, 2, 9, 4, 3, 12]
length = len(experiments)
quick_sort(experiments, 0, length - 1)
worst = experiments[0]
best = experiments[length - 1]
print("The best results of experiments is ", best)
print("The worst results of experiments is ", worst)
