#include<iostream>
#include<vector>
#include<queue>
#define max(a,b) ((a>b)?a:b)
using namespace std;
int pre[10010];
int dp[10010];
vector<int> n[10010];
int cost[10010];
queue<int> q;
int main(){
	int nv;
	scanf("%d",&nv);
	for(int i=1;i<=nv;i++){
		int c,kind;
		scanf("%d %d",&c,&kind);
		dp[i]=c;
		cost[i]=c;
		pre[i]=kind;
		for(int j=0;j<kind;j++){
			int k;
			scanf("%d",&k);
			n[k].push_back(i);
		}
		if(kind==0)
			q.push(i);
	}
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(int i=0;i<n[p].size();i++){
			pre[n[p][i]]--;
			dp[n[p][i]]=max(dp[n[p][i]],dp[p]+cost[n[p][i]]);
			if(pre[n[p][i]]==0){
				q.push(n[p][i]);
			}
		}
	}
	int maxval=0;
	for(int i=1;i<=nv;i++){
		maxval=max(maxval,dp[i]);
	}
	printf("%d",maxval);
} 
