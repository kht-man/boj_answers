#include<iostream>
int pow(int a,int b){
	int r=1;
	while(b){
		if(b%2){
			r*=a;
		}
		a*=a;
		b/=2;
	}
	return r;
}
void hanoi(int start,int end,int high){
	if(high==1){
		printf("%d %d\n",start,end);
	}	
	else{
		int i=6-start-end;
		hanoi(start,i,high-1);
		printf("%d %d\n",start,end);
		hanoi(i,end,high-1);
	}
}
int main(){
	int k;
	scanf("%d",&k);
	printf("%d\n",pow(2,k)-1);
	hanoi(1,3,k);
}
