#include<stdio.h>

int getByte(int x,int n){
	int shift=n<<3;
	return (x>>shift)&0xFF;
}

int main(){
	int x,n;
	scanf("%x %d",&x,&n);

	int ans=getByte(x,n);

	printf("0x%X\n",ans);

	return 0;

}
