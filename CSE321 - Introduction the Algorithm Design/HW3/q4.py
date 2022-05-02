import math


def closest_pair(points, n):

    d = math.inf

    for i in range(1, n-1):
        for j in range(i+1, n):
            d = min(d, distance(points[i], points[j]))

    return d


def distance(point1, point2):
    x = point1[0] - point2[0]
    y = point1[1] - point2[1]
    return math.sqrt(x**2 + y**2)


points = [[141211, 2], [151231, 10], [82, 5123], [12, 6], [20, 21]]
n = len(points)
print('Closest pair points = ', closest_pair(points, n))
