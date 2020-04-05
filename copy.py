import os
import shutil
from os import path

print(os.listdir('.'))

destination = "./someshit/"
cnt = 0

file = open("test.txt", "r")

#first sanitize the test file ---> 
#convert it into array of strings

arr = []

for each in file:
    each = each[:-1]
    arr.append(each)

for each in arr:
    temp = destination + str(cnt) + ".cpp"
    print(each, temp)
    fuck = shutil.copy(each, temp)
    cnt += 1
