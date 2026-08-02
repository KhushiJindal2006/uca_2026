#include<stdio.h>

int fitBits(int x,int n){
	int shift=32+(~n+1);
	int temp=x<<shift;
	temp=temp>>shift;

	return !(temp^x);

}

int main(){
	int x,n;

	scanf("%d %d",&x,&n);

	printf("%d",fitBits(x,n));

	return 0;
}
