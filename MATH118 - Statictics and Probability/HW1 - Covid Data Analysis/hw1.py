import csv
import numpy as np


def read_file():
    with open('owid-covid-data.csv', 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        i = 0
        all_data = []

        for row in csv_reader:
            if i == 0:
                i += 1
            else:
                all_data.append(row)
        return all_data


def fill_the_list(covid_data):
    all_variables = []
    labels = ["Country", "q#3", "q#4", "q#5_min", "q#5_max", "q#5_avg", "q#5_var"
        , "q#6_min", "q#6_max", "q#6_avg", "q#6_var", "q#7_min", "q#7_max", "q#7_avg", "q#7_var"
        , "q#8_min", "q#8_max", "q#8_avg", "q#8_var", "q#9_min", "q#9_max", "q#9_avg", "q#9_var"
        , "q#10_min", "q#10_max", "q#10_avg", "q#10_var", "q#11", "q#12_min", "q#12_max", "q#12_avg", "q#12_var"
        , "q#13_min", "q#13_max", "q#13_avg", "q#13_var", "q#14", "q#15", "q#16", "population", "median_age"
        , "# of people aged 65 older", "# of people aged 70 older", "economic performance",
              "death rates due to heart disease"
        , "diabetes prevalence", "#of female smokers", "#of male smokers", "handwashing facilities",
              "hospital beds per thousand people"
        , "life expectancy", "human development index"]
    length = len(min_max_average_find(covid_data, 16))
    all_variables.append(labels)
    q3 = find_total(covid_data, 4)
    q4 = find_total(covid_data, 7)
    q5 = min_max_average_find(covid_data, 16)
    q6 = min_max_average_find(covid_data, 17)
    q7 = min_max_average_find(covid_data, 19)
    q8 = min_max_average_find(covid_data, 21)
    q9 = min_max_average_find(covid_data, 23)
    q10 = min_max_average_find(covid_data, 25)
    q11 = find_total(covid_data, 26)
    q12 = min_max_average_find(covid_data, 31)
    q13 = min_max_average_find(covid_data, 32)
    q14 = find_total(covid_data, 35)
    q15 = find_total(covid_data, 36)
    q16 = find_total(covid_data, 34)
    q17_1 = min_max_average_find(covid_data, 44)
    q17_2 = min_max_average_find(covid_data, 46)
    q17_3 = min_max_average_find(covid_data, 47)
    q17_4 = min_max_average_find(covid_data, 48)
    q17_5 = min_max_average_find(covid_data, 49)
    q17_6 = min_max_average_find(covid_data, 51)
    q17_7 = min_max_average_find(covid_data, 52)
    q17_8 = min_max_average_find(covid_data, 53)
    q17_9 = min_max_average_find(covid_data, 54)
    q17_10 = min_max_average_find(covid_data, 55)
    q17_11 = min_max_average_find(covid_data, 56)
    q17_12 = min_max_average_find(covid_data, 57)
    q17_13 = min_max_average_find(covid_data, 58)
    for i in range(length):
        all_variables.append([q3[i][0], q3[i][1], q4[i][1], q5[i][1], q5[i][2], q5[i][3], q5[i][4]
                                 , q6[i][1], q6[i][2], q6[i][3], q6[i][4], q7[i][1], q7[i][2], q7[i][3], q7[i][4]
                                 , q8[i][1], q8[i][2], q8[i][3], q8[i][4], q9[i][1], q9[i][2], q9[i][3], q9[i][4]
                                 , q10[i][1], q10[i][2], q10[i][3], q10[i][4], q11[i][1], q12[i][1], q12[i][2],
                              q12[i][3], q12[i][4]
                                 , q13[i][1], q13[i][2], q13[i][3], q13[i][4], q14[i][1], q15[i][1], q16[i][1]
                                 , q17_1[i][1], q17_2[i][1], q17_3[i][1], q17_4[i][1], q17_5[i][1], q17_6[i][1],
                              q17_7[i][1], q17_8[i][1], q17_9[i][1]
                                 , q17_10[i][1], q17_11[i][1], q17_12[i][1], q17_13[i][1]])
    return all_variables


def write_file(print_list):
    with open('output.csv', mode='w', newline='') as csv_file:
        output_writer = csv.writer(csv_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        output_writer.writerows(print_list)


def find_country_number(covid_data):
    country_name = ""
    number = 0

    for i in covid_data:
        if country_name != i[2]:
            number += 1
            country_name = i[2]
    return number


def find_earliest_data(covid_data):
    first_min = covid_data[0][3].split("-")
    min = int(first_min[0]) * 360 + int(first_min[1]) * 30 + int(first_min[2])
    min_date = ""
    for i in covid_data:
        if i == 0:
            i += 1
        else:
            date = i[3]
            if date != "":
                number = date.split("-")
                total_day = int(number[0]) * 360 + int(number[1]) * 30 + int(number[2])
                if total_day < min:
                    min = total_day
                    min_date = i[3]
                    country = " " + i[2]
    return min_date + country


def min_max_average_find(covid_data, k):
    all_rep_rates = []
    country_vars = []
    counter = 1
    country = covid_data[0][2]
    avg = 0.0
    min = 0.0
    max = 0.0
    if covid_data[0][k] != "":
        min = float(covid_data[0][k])
        max = float(covid_data[0][k])

    for i in covid_data:
        if i[2] == country:
            if i[k] != "":
                country_vars.append(float(i[k]))
                avg += float(i[k])
                counter += 1
                if min == 0:
                    min = float(i[k])
                if float(i[k]) < min:
                    min = float(i[k])
                if max == 0:
                    max = float(i[k])
                if float(i[k]) > max:
                    max = float(i[k])
            j = i
        else:
            temp = counter
            avg = avg / counter
            counter = 1
            if len(country_vars) == 0:
                country_vars.append(0.0)
            variation = np.var(country_vars)
            all_rep_rates.append([j[2], min, max, avg, variation])
            country_vars.clear()
            if i[16] != "":
                min = float(i[k])
                max = float(i[k])
                avg = float(i[k])
            else:
                min = 0.0
                max = 0.0
                avg = 0.0

            country = i[2]

    all_rep_rates.append([j[2], min, max, avg / temp, variation])
    return all_rep_rates


def find_total_cases(covid_data):
    all_total_case = []
    call_max = min_max_average_find(covid_data, 4)
    for i in call_max:
        all_total_case.append([i[0], i[2]])
    return all_total_case


def find_total(covid_data, k):
    all_total_case = []
    call_max = min_max_average_find(covid_data, k)
    for i in call_max:
        all_total_case.append([i[0], i[2]])
    return all_total_case


covid_data = read_file()
results = fill_the_list(covid_data)
write_file(results)
"""
print("Q1 : ", find_country_number(covid_data))
print("Q2: ", find_earliest_data(covid_data))
q3 = find_total(covid_data, 4)
q4 = find_total(covid_data, 7)
q5 = min_max_average_find(covid_data, 16)
q6 = min_max_average_find(covid_data, 17)
q7 = min_max_average_find(covid_data, 19)
q8 = min_max_average_find(covid_data, 21)
q9 = min_max_average_find(covid_data, 23)
q10 = min_max_average_find(covid_data, 25)
q11 = find_total(covid_data, 26)
q12 = min_max_average_find(covid_data, 31)
q13 = min_max_average_find(covid_data, 32)
q14 = find_total(covid_data, 35)
q15 = find_total(covid_data, 36)
q16 = find_total(covid_data, 34)
q17_1 = min_max_average_find(covid_data, 44)
q17_2 = min_max_average_find(covid_data, 46)
q17_3 = min_max_average_find(covid_data, 47)
q17_4 = min_max_average_find(covid_data, 48)
q17_5 = min_max_average_find(covid_data, 49)
q17_6 = min_max_average_find(covid_data, 51)
q17_7 = min_max_average_find(covid_data, 52)
q17_8 = min_max_average_find(covid_data, 53)
q17_9 = min_max_average_find(covid_data, 54)
q17_10 = min_max_average_find(covid_data, 55)
q17_11 = min_max_average_find(covid_data, 56)
q17_12 = min_max_average_find(covid_data, 57)
q17_13 = min_max_average_find(covid_data, 58)
"""