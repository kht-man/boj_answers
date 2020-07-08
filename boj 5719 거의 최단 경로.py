import sys
import heapq
inf=sys.maxsize
link=[[inf]*500for _ in range(500)]
n,m=map(int,input().split())
while (n,m)!=(0,0):
    for i in range(n):
        for j in range(n):
            link[i][j]=inf
    st,fin=map(int,input().split())
    q=[]
    lenn=[inf]*n
    way=[[]for _ in range(n)]
    lenn[st]=0
    way[st].append([st])
    for i in range(m):
        s,f,c=map(int,input().split())
        link[s][f]=c
    heapq.heappush(q,(0,st))
    while q:
        cost,p=heapq.heappop(q)
        if cost!=lenn[p]:
            continue
        for i in range(n):
            if link[p][i]==inf:
                continue
            if lenn[i]>lenn[p]+link[p][i]:
                lenn[i]=lenn[p]+link[p][i]
                del way[i][:]
                for j in way[p]:
                    way[i].append(j+[i])
                heapq.heappush(q,(lenn[i],i))
            elif lenn[i]==lenn[p]+link[p][i]:
                for j in way[p]:
                    way[i].append(j+[i])
    if lenn[fin]==inf:
        print("-1")
        n,m=map(int,input().split())
        continue
    for i in way[fin]:
        lenf=len(i)
        for j in range(lenf-1):
            link[i[j]][i[j+1]]=inf
    lenn=[inf]*n
    q=[]
    lenn[st]=0
    heapq.heappush(q,(0,st))
    while q:
        cost,p=heapq.heappop(q)
        if lenn[p]!=cost:
            continue
        for i in range(n):
            if link[p][i]==inf:
                continue
            if lenn[i]>lenn[p]+link[p][i]:
                lenn[i]=lenn[p]+link[p][i]
                heapq.heappush(q,(lenn[i],i))
    if lenn[fin]==inf:
        print("-1")
    else:
        print(lenn[fin])
    n,m=map(int,input().split())
