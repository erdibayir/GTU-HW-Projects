import matplotlib.pyplot as plt
import numpy as np
import math


def actualDefectsPlot(totalDefects, allPredicted): # Draw Bar Plot for actual Cases
    labels = ['Company1', 'Company2', 'Company3', 'Company4', 'Company5', 'Company6', 'Company7', 'Company8',
              'Company9',
              'Company10', 'Company11', 'Company12', 'Company13', 'Company14']
    x = np.arange(len(labels))
    width = 0.35

    fig, ax = plt.subplots()
    rects1 = ax.bar(x - width / 2, totalDefects[0][1:15], width, label='Actual#0')  # matplotlib.pyplot library function to fill plot
    rects2 = ax.bar(x + width / 2, totalDefects[1][1:15], width, label='Actual#1')
    rects3 = ax.bar(x + width / 2, totalDefects[2][1:15], width, label='Actual#2')
    rects4 = ax.bar(x + width / 2, totalDefects[3][1:15], width, label='Actual#3')
    rects5 = ax.bar(x + width / 2, totalDefects[4][1:15], width, label='Actual#4')

    ax.set_ylabel('Defects')  # Title of Plot
    ax.set_title('Actual Defects by group for each country')  # Numbers name of plot
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.legend()

    ax.bar_label(rects1, padding=3)
    ax.bar_label(rects2, padding=3)
    ax.bar_label(rects3, padding=3)
    ax.bar_label(rects4, padding=3)
    ax.bar_label(rects5, padding=3)
    fig.tight_layout()
    plt.show()  # Show Plot


def predictedDefectsPlot(totalDefects, newPredicted): # Draw Bar Plot for Predicted Cases
    tempList = []
    labels = ['Company1', 'Company2', 'Company3', 'Company4', 'Company5', 'Company6', 'Company7', 'Company8',
              'Company9',
              'Company10', 'Company11', 'Company12', 'Company13', 'Company14']

    x = np.arange(len(labels))
    width = 0.35

    fig, ax = plt.subplots()
    rects1 = ax.bar(x - width / 2, newPredicted[0][0:14], width, label='0')
    rects2 = ax.bar(x + width / 2, newPredicted[1][0:14], width, label='1')
    rects3 = ax.bar(x + width / 2, newPredicted[2][0:14], width, label='2')
    rects4 = ax.bar(x + width / 2, newPredicted[3][0:14], width, label='3')
    rects5 = ax.bar(x + width / 2, newPredicted[4][0:14], width, label='4')

    ax.set_ylabel('Defects')  # Title of Plot
    ax.set_title('Predicted Defects by group for each country')  # Numbers name of plot
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.legend()

    ax.bar_label(rects1, padding=3)
    ax.bar_label(rects2, padding=3)
    ax.bar_label(rects3, padding=3)
    ax.bar_label(rects4, padding=3)
    ax.bar_label(rects5, padding=3)

    fig.tight_layout()
    plt.show()  # Show Plot
    return newPredicted

def totalPlot(totalDefects, allPredicted): # Draw Bar Plot for actual Cases
    actualTotal = []
    predictedTotal = []
    labels = ['0', '1', '2', '3', '4']

    x = np.arange(len(labels))
    for i in totalDefects:
        actualTotal.append(i[15])

    for i in allPredicted:
        predictedTotal.append(i[14])
    width = 0.35
    fig, ax = plt.subplots()
    rects1 = ax.bar(x - width / 2, actualTotal, width, label='Actual Defects')  # matplotlib.pyplot library function to fill plot
    rects2 = ax.bar(x + width / 2, predictedTotal, width, label='Predicted Defects')

    ax.set_ylabel('Defects')  # Title of Plot
    ax.set_title('Total Of Actual - Predicted Defects')  # Numbers name of plot
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.legend()

    ax.bar_label(rects1, padding=3)
    ax.bar_label(rects2, padding=3)
    fig.tight_layout()
    plt.show()  # Show Plot

def readFromFile():
    openFile = open("manufacturing_defects.txt", "r")  # Open file
    array = []
    for line in openFile:  # Fill 2d list from file
        line = line.rstrip('\n')
        row = line.split()  # split each line
        if len(row) != 0: # Pass free lines
            array.append(row)
    openFile.close()
    return array  # Return 2d list


def total_of_defect(allData): # Find Actual Cases
    w, h = 16, 5
    totalDefects = [[0 for x in range(w)] for y in range(h)]
    totalDefects[0][0] = 0
    totalDefects[1][0] = 1
    totalDefects[2][0] = 2
    totalDefects[3][0] = 3
    totalDefects[4][0] = 4
    k = 0
    for i in allData: # Find 0, 2, 3, 4 actual cases with nested loops
        if i != []:
            for j in range(2, 16):
                if int(i[j]) == 0:
                    totalDefects[0][j - 1] = totalDefects[0][j - 1] + 1  # ----------------------------
                if int(i[j]) == 1:
                    totalDefects[1][j - 1] = totalDefects[1][j - 1] + 1
                if int(i[j]) == 2:
                    totalDefects[2][j - 1] = totalDefects[2][j - 1] + 1 # In 0,1,2,3,4 if  find it while traverse the  list.
                if int(i[j]) == 3:
                    totalDefects[3][j - 1] = totalDefects[3][j - 1] + 1
                if int(i[j]) == 4:
                    totalDefects[4][j - 1] = totalDefects[4][j - 1] + 1  # ----------------------------
    total = 0
    k = 0
    for i in totalDefects:
        for j in range (1,16):
            total += i[j]
        totalDefects[k][15] = total
        total = 0
        k+=1

    return totalDefects # Return all actual cases

def findLambda(totalDefects):  # Find Lambda
    k = 1
    allLambda = []
    for i in range(0, 14): # Find lambda for each country with calculated 0,1,2,3,4 numbers
        temp = ((totalDefects[0][k] * 0) + (totalDefects[1][k] * 1) + (totalDefects[2][k] * 2) + (
                totalDefects[3][k] * 3) + (totalDefects[4][k] * 4)) / 20
        allLambda.append(temp)
        k += 1
    avarageL = 0
    for i in allLambda:
        avarageL += i
    avarageL = avarageL / 14
    allLambda.append(avarageL)
    return allLambda # Return lambdas


def predictedDefects(allLambda):  # Find Predicted Cases
    tempLambda = 0
    allPredicted = []
    newPredicted = []
    x = 0
    px = (pow(math.e, -tempLambda) * pow(tempLambda, x)) / math.factorial(x)  # Use p(x) formula for find predicted values
    k = 0
    for i in range(0, 14): # Calculate for each country and round it
        tempLambda = allLambda[k]
        zero = ((pow(math.e, -tempLambda) * pow(tempLambda, 0)) / math.factorial(0)) * 20
        one = ((pow(math.e, -tempLambda) * pow(tempLambda, 1)) / math.factorial(1)) * 20
        two = ((pow(math.e, -tempLambda) * pow(tempLambda, 2)) / math.factorial(2)) * 20
        three = ((pow(math.e, -tempLambda) * pow(tempLambda, 3)) / math.factorial(3)) * 20
        four = ((pow(math.e, -tempLambda) * pow(tempLambda, 4)) / math.factorial(4)) * 20
        zero = round(zero)
        one = round(one)
        two = round(two)
        three = round(three)
        four = round(four)
        allPredicted.append([zero, one, two, three, four])
        k += 1
    for i in range(0, 5): # Fill predicted cases
        tempList = []
        for j in range(0, 14):
            tempList.append(allPredicted[j][i])

        newPredicted.append(tempList)
    tempLambda = allLambda[14]

    zero = ((pow(math.e, -tempLambda) * pow(tempLambda, 0)) / math.factorial(0)) * 20*14
    one = ((pow(math.e, -tempLambda) * pow(tempLambda, 1)) / math.factorial(1)) * 20*14
    two = ((pow(math.e, -tempLambda) * pow(tempLambda, 2)) / math.factorial(2)) * 20*14
    three = ((pow(math.e, -tempLambda) * pow(tempLambda, 3)) / math.factorial(3)) * 20*14
    four = ((pow(math.e, -tempLambda) * pow(tempLambda, 4)) / math.factorial(4)) * 20*14
    newPredicted[0].append(zero)
    newPredicted[1].append(one)
    newPredicted[2].append(two)
    newPredicted[3].append(three)
    newPredicted[4].append(four)

    return newPredicted # Return Predicted Cases


def printTables(totalDefects, allpredicted):  # Print Tables to terminal
    print("\n\nTable 1: Actual Cases")
    print("\# of Defects \t\t # of cases in all company between the years(For each country)\t\t  Total Cases")
    for i in range(0, 5):
        print("%2d" % (totalDefects[i][0]), "\t\t\t\t\t", end=" ")
        for x in range(len(totalDefects[i]) - 1):
            print("%2d" % (totalDefects[i][x + 1]), " ", end=" ")
        print()

    print("\n\nTable 2: Actual Cases vs Predicted Cases")
    print("\# of Defects \t\t # of cases in all company between the years(For each country)\t\t  Total Cases\t\tPredicted \# of cases in all "
        "companies between the years\t\t     Total Cases")
    for i in range(0, 5):
        print("%2d" % (totalDefects[i][0]), "\t\t\t\t\t", end=" ")
        for x in range(len(totalDefects[i]) - 1):
            print("%2d" % (totalDefects[i][x + 1]), " ", end=" ")

        print("\t\t\t", end="")
        for x in range(len(allpredicted[i])):
            if x == 14:
                print("%2f" % (allpredicted[i][x]), " ", end=" ")
            else:
                print("%2d" % (allpredicted[i][x]), " ", end=" ")
        print()


def printLamdas(allLambda):
    print("Lambdas for each country: ",end= " ")
    for i in range(0,14):
        print(allLambda[i], end=" ")
    print()
    print("Lambda:", allLambda[14])


allData = readFromFile()
totalDefects = total_of_defect(allData)
allLambda = findLambda(totalDefects)
allPredicted = predictedDefects(allLambda)
actualDefectsPlot(totalDefects, allPredicted)
predictedDefectsPlot(totalDefects, allPredicted)
totalPlot(totalDefects,allPredicted)
printLamdas(allLambda)
printTables(totalDefects, allPredicted)
