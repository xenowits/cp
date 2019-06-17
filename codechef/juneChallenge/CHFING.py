import math
import random

mod = 1000000007

if __name__ == '__main__':
    t = int(input())
    while t>0:
        n, k = [int(x) for x in input().split()]
        if (k<=n):
            print((k-1)%mod,'\n')
        else:
            if ((k-n)%(n-1) == 0):
                i = int((k-n)/(n-1))
            else:
                i = int( (k-n)/(n-1) )+1
            #print(i," is the i\n")
            print( int( ( (k-1) + (i+1)*k - int( (n*(i+1)*(i+2))/2 ) + int( (i*(i+1))/2 ) )%mod) , '\n')
        t-=1
