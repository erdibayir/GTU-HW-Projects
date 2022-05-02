def courseSelection(courseIds, starts, finish):

    length = len(courseIds)
    selected = [0]*(length - 1)
    selected[1] = courseIds[1]
    j = 1
    temp = 1
    for i in range(2, length):
        if(finish[j] <= starts[i]):
            temp = temp+1
            selected[temp] = courseIds[i]
            j = i
    selected[0] = temp
    courses = []
    for i in range(1, len(selected)):
        if(selected[i] == 0):
            courses.append("English")
        if(selected[i] == 1):
            courses.append("Mathematics")
        if(selected[i] == 2):
            courses.append("Physics")
        if(selected[i] == 3):
            courses.append("Chemistry")
        if(selected[i] == 4):
            courses.append("Biology")
        if(selected[i] == 5):
            courses.append("Geograpy")
    return courses


courseIds = [2, 0, 1, 3, 5, 4]
starts = [0, 1, 3, 5, 5, 8]
finish = [6, 2, 4, 7, 9, 9]
selectedCourses = courseSelection(courseIds, starts, finish)
print("Maximum set of courses:")
for i in selectedCourses:
    print(i)

#!!!!
    # In homework solution says  {English, Mathematics, Chemistry, Geography}
    # but i think its wrong because Chemistry start at 5 and end at 7 we can not take course Geograpy because it starts at 5 again
    # we can take Biology after  Chemistry because Biology starts at 8
    # So result is {English Mathematics Chemistry Biology}
#!!!!
