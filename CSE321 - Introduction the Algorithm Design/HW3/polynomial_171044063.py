def polynomial(P, x):
    result = 0
    length = len(P)
    for i in range(length-1, -1, -1):
        power = 1
        for j in range(0, i):
            power = power * x

        result = result + P[i]*power
    return result


arr = [5, 3, 2, 1]  # -> P(x) = x^3 + 2x^2 + 3x + 5
result = polynomial(arr, 2)  # - > Result = 2^3 + 2(2^2) + 3*2 + 5 = 27
print("Polynomial Result:", result)
