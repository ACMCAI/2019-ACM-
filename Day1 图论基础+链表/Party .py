N=2000+5
n=int(input())
d=[]
step=[]
vis=[]
def findt(u):
    lent=1
    vis[u]=1
    while d[u]!=-1:
        u=d[u]
        if(vis[u]==1):
            return lent+step[u]
        lent+=1
    return lent

for i in range(0,n+1):
    d.append(-1)
    vis.append(0)
    step.append(0)
for i in range(1,n+1):
    v= int(input())
    d[i]=v
maxlen=0
for i in range(1,n+1):
    if vis[i] == 0:
        step[i]=findt(i)
    maxlen=max(maxlen,step[i])
print(maxlen)