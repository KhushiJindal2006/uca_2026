#include<stdio.h>

int bitXor(int x,int y){
	int a=(~x & y);
	int b=(x & ~y);

	return ~(~a & ~b);
}

int main(){

	int x,y;
	scanf("%d %d",&x,&y);

	int res=bitXor(x,y);

	printf("%d",res);

	return 0;
}
