class cheeses:
    def __init__(self, weight, price, index):
        self.weight = weight
        self.price = price
        self.index = index
        self.ratio = price // weight

    def __lt__(self, other):
        return self.ratio < other.ratio


def maxPriceGreedy(weight, price, capacity):
    allPrice = []
    for i in range(len(weight)):
        allPrice.append(cheeses(weight[i], price[i], i))

    allPrice.sort(reverse=True)
    maxPrice = 0
    for i in allPrice:
        currentWeight = int(i.weight)
        currentPrice = int(i.price)
        if capacity - currentWeight >= 0:
            capacity -= currentWeight
            maxPrice += currentPrice
        else:
            f = capacity / currentWeight
            maxPrice += currentPrice * f
            capacity = int(capacity - (currentWeight * f))
            break
    return maxPrice


prices = [280, 100, 120, 120]
weight = [40, 10, 20, 24]
capacity = 60

maxPrice = maxPriceGreedy(weight, prices, capacity)
print("Maximum price for", capacity, "capacity :", int(maxPrice))
