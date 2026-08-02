#include<stdio.h>

int isPower2(int x){
	int nonZero=!!x;

	int pos=!(x>>31);

	int oneBit=!(x&(x+~0));

	return nonZero&pos&oneBit;

}

int main(){
	int x;
	scanf("%d",&x);

	printf("%d",isPower2(x));

	return 0;

}
