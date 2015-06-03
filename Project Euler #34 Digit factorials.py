# AUTHOR  : Peeyush Yadav
# Problem : Project Euler #34: Digit factorials


a = [0]*10
a[0]=1

for i in range(1,10):
    a[i] = int(a[i-1] * i)

n = int(input())
ans = 0

for i in range(10,n+1):
    temp = int(i)
    sum = 0
    while temp > 0 :
        sum += a[int(temp%10)]
        temp//=10

    sum = int(sum)
    if sum % i == 0 :
        ans += i

print (int(ans))
