#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> Point;
vector <Point> v;
int map[9][9];
void updown_check(bool a[],int row){
	for(int i=0;i<9;i++){
		if(map[i][row]!=0){
			a[map[i][row]-1]=false;
		}
	}
}
void left_right_check(bool a[],int line){
	for(int i=0;i<9;i++){
		if(map[line][i]!=0){
			a[map[line][i]-1]=false;
		}
	}
}
void box_check(bool a[],int group){
	//printf("%d\n",group);
	int x=group%3;
	int y=group/3;
	for(int i=3*y;i<3*y+3;i++){
		for(int j=3*x;j<3*x+3;j++){
			if(map[i][j]!=0){
				a[map[i][j]-1]=false;
			}
		}
	}
}
bool solve(int i){
	if(i==v.size())
		return true;
	int y=v[i].first;
	int x=v[i].second;
	bool avail[9]={0};
	for(int j=0;j<9;j++){
		avail[j]=true;
	}
	updown_check(avail,x);
	left_right_check(avail,y);
	box_check(avail,(y/3)*3+(x/3));
	/*printf("%d %d:",x,y);
	for(int j=0;j<9;j++){
		printf("%d ",avail[j]);
	}
	printf("\n");*/
	for(int j=0;j<9;j++){
		if(avail[j]){
			map[y][x]=j+1;
			if(solve(i+1))
				return true;
		}
	}
	map[y][x]=0;
	return false;
}
int main(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			scanf("%d",&map[i][j]);
			if(!map[i][j]){
				v.push_back({i,j});
			}
		}
	}
	solve(0);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
}
