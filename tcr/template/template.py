
from decimal import *
getcontext().prec = 10
a, b = map(Decimal, input().split())
print(a * b)
