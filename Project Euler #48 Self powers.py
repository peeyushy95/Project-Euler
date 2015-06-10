/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #48: Self powers
*/

n = int(raw_input())
mod = 10000000000
ans = 0
for i in range(1,n+1):
    ans = (ans + pow(i,i,mod))%mod
print ans