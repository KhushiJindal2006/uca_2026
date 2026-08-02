#include<stdio.h>

int bang(int x){
	int neg=~x+1;
	int temp=x|neg;
	int sign=temp>>31;
	
	return sign+1;
}
int main(){
	int x;
	scanf("%d",&x);

	printf("%d",bang(x));

	return 0;
}
