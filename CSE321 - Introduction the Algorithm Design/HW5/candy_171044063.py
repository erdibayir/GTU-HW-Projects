def candyDynamicProgramming(specialLength, lengthArr, priceArr):
    length = len(priceArr)
    currentCandies = [[0 for x in range(specialLength + 1)]
                      for x in range(length + 1)]
    for i in range(length + 1):
        for current in range(specialLength + 1):
            if i == 0 or current == 0:
                currentCandies[i][current] = 0
            elif lengthArr[i-1] <= current:
                currentCandies[i][current] = max(priceArr[i-1] + currentCandies[i-1][current-lengthArr[i-1]], currentCandies[i-1][current])
            else:
                currentCandies[i][current] = currentCandies[i-1][current]

    return currentCandies[length][specialLength]


priceArr = [1, 5, 8, 9, 10, 17, 17, 20]
lengthArr = [1, 2, 3, 4, 5, 6, 7, 8]
specialLength = 8
print("Maximum obtainable value is:", candyDynamicProgramming(
    specialLength, lengthArr, priceArr))
