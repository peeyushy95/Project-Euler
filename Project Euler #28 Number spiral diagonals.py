# AUTHOR  : Peeyush Yadav
# Problem : Project Euler #28: Number spiral diagonals

T = int(raw_input())

while T > 0 :
        
        n = int(raw_input())
        ans = (4*n*n*n + 3*n*n + 8*n - 9) / 6
        print(ans%1000000007)
        T = T - 1
