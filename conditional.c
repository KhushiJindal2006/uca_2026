#include<stdio.h>

int conditional(int x,int y,int z){
	int nonZero=!!x;
	int mask=~nonZero+1;

	int a=y&mask;
	int b=z& ~mask;

	return a|b;

}

int main(){
	int x,y,z;

	scanf("%d %d %d",&x,&y,&z);

	printf("%d\n",conditional(x,y,z));

	return 0;

}
