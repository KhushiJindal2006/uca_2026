#include<stdio.h>

int bitAnd(int x,int y){
	return ~(~x | ~y);
}
int main(){
	int x,y;

	scanf("%d %d",&x,&y);

	int ans=bitAnd(x,y);

	printf("%d",ans);

	return 0;
}
