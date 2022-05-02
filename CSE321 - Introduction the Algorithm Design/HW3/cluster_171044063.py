
#
# PART A
#
def max_clusters(branches, length):
    max_profit = 0
    clusters = [0, 0]
    for i in range(0,length):
        profit = 0
        for j in range(i,length):
            profit = profit + branches[j]
            if profit >= max_profit:
                max_profit = profit
                clusters[0] = i
                clusters[1] = j

    return clusters


branches = [3, -5, 2, 11, -8, 9, -5]
length = len(branches)
result = max_clusters(branches, length)
print('The Most Profit Cluster :', "Between",
      result[0], "and", result[1], " index clusters")



#
# PART B
#
def maxClusters(branches, low, middle, high):
    profit = 0
    left_sum = -9999999
    for i in range(middle, low-1, -1):
        profit = profit + branches[i]
 
        if (left_sum < profit):
            left_sum = profit
    profit = 0
    right_sum = -9999999
    for i in range(middle + 1, high + 1):
        profit = profit + branches[i]
        if (right_sum < profit):
            right_sum = profit

    maximum = max(left_sum + right_sum, left_sum, right_sum)
    return maximum

def findProfit(branches, low, high):
    if (low == high):
        return branches[low]
    middle = (low + high) // 2
    first = findProfit(branches, low, middle)
    second = findProfit(branches, middle+1, high)
    third = maxClusters(branches, low, middle, high)
    maximum = max(first,second,third)
    return maximum
 

branches = [3, -5, 2, 11, -8,9,-5]
length = len(branches)
 
maxProfit = findProfit(branches, 0, length-1)
print("Maximum Profit is ", maxProfit)