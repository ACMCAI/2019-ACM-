N=1e5+5
n,m = map(int,input().split(' '))
minn = max(0,n-m*2)
mind=N
for i in range(0,int(N)):
    if (i*(i-1)/2)>=m:
        mind=i
        break
maxx = max(0,n-mind)
print("%d %d"%(minn,maxx))