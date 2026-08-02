#include<stdio.h>

int sign(int x){
	return (x>>31) | (!!x);
}

int main(){
	int n;
	scanf("%d",&n);

	int ans=sign(n);
	printf("%d",ans);

	return 0;
}
