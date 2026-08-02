#include<stdio.h>

int logicalShift(int x,int n){
	int mask=~(((1<<31)>>n)<<1);
	return (x>>n) & mask;
}

int main(){
	int x,n;
	scanf("%x %d",&x,&n);

	int ans=logicalShift(x,n);
	printf("0x%08X\n",ans);

	return 0;
}
