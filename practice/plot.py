import numpy as np
import matplotlib.pyplot as plt

fileOpen = open("points.txt","r")
str = fileOpen.read()
str1 = str.split("\n");
print(str1)
n = ['A','B','C','D','E','F','G','H','I','J']
for t in str1:
    a1 = []
    a2 = []
    a = t.split(" ");
    print(a)
    for i in range(0,20,2):
        # if (len(x) > 0):
        #     t = x.split(' ')
        #     a1.append(int(t[0]))
        #     a2.append(int(t[1]))
        print(a[i],a[i+1])
        if (a[i] is not '' and a[i+1] is not ''):
            a1.append(int(a[i]))
            a2.append(int(a[i+1]))
    print(len(a1),len(a2))
    plt.plot(a1,a2,'ro', alpha=0.7)
    for i,txt in enumerate(n):
        plt.annotate(txt,(a1[i],a2[i]))
    plt.show()
