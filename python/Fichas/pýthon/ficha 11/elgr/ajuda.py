
def fibonacci(n, t0=1, t1=0, c=0):
    if n <= 1:
        res = t1
        return res, c
    else:
        res = fibonacci(n-1, t1, t0+t1, c+1)
    return res
print(fibonacci(13))