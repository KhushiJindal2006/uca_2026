#include<iostream>
using namespace std;

//O(n)
int bruteforce(int num){
	int sum=0;
	int first=1;
	int second=1;

	while(first<=num){
		if(first%2==0){
			sum+=first;
		}

		int next=first+second;
		first=second;
		second=next;
	}
	return sum;
}

//O(logn)
int optimised(int num){
	int sum=0;
	int first=2;
	int second=8;

	while(first<=num){
		sum+=first;
		int next=4*second+first;
		first=second;
		second=next;
	}
	return sum;
}


int main(){
	int num;
	cin>>num;

	cout<<"Sum of even numbers in Fibonacci Series (Brute Force): "<<bruteforce(num)<<endl;
	cout<<"Sum of even numbers in Fibonacci Series (Optimised): "<<optimised(num)<<endl;

	return 0;
}
