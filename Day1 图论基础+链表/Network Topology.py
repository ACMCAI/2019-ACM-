n, m = map(int, input().split())
d = [0]  (n + 1)
c = [0]  (n + 1)
for i in range(m)
    for x in list(map(int, input().split()))
        d[x] += 1
for x in d c[x] += 1
if c[2] == n print('ring topology')
elif c[1] == n - 1 and c[n - 1] == 1 print('star topology')
elif c[2] == n - 2 and c[1] == 2 print('bus topology')
else print('unknown topology')