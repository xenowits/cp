n_str = input()
n = int(n_str)

if (n == 1):
    print(1.000000000000)
else:
    sum = 0.000000000000
    for i in range(1, n+1):
        sum += round((1.000000000000)/i, 12)
    print(sum)
