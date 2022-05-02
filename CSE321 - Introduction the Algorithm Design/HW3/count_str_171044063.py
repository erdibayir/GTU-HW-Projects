def count_str(str, length, first, last):
    count = 0
    for i in range(0, length):
        if str[i] == first:
            for j in range(i, length):
                if str[j] == last:
                    count += 1
    return count


str = 'TXZXXJZWX'
length = len(str)
first = 'X'
last = 'Z'
print('Counter =', count_str(str, length, first, last))