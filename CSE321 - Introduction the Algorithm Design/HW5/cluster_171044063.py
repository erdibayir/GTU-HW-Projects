def maxProfit(arr, size):
    maxAllContiguos = arr[0]
    currentMax = arr[0]
    for i in range(1, size):
        currentMax = max(arr[i], currentMax + branches[i])
        maxAllContiguos = max(maxAllContiguos, currentMax)

    return maxAllContiguos


branches = [3, -5, 2, 11, -8, 9, -5]
length = len(branches)
print("Maximum profit is", maxProfit(branches, length))
