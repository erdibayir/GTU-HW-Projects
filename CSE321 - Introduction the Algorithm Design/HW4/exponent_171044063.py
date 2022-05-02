def exponentiationBruteForce(base, exponent):
    result = 1
    for i in range(exponent):
        result *= base
    return result


def exponentiationDivideAndConquer(base, exponent):
    if (exponent == 0):
        return 1
    else:
        result = exponentiationDivideAndConquer(base, int(exponent / 2))
        if (exponent % 2 == 0):
            return result * result
        else:
            return base * result * result


base = 5
exponent = 3
print("Brute Force exponention result for", base, "^", exponent,
      "is: ", exponentiationBruteForce(base, exponent))
print("Divide and conquer exponention result for", base, "^",
      exponent, "is: ", exponentiationDivideAndConquer(base, exponent))
