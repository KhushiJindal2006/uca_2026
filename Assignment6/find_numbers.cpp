#include<iostream>
#include<vector>

using namespace std;

int findNumber(vector<int>&arr){
	int ans=0;
	for(int i=0;i<32;i++){
		int cnt=0;
		for(int num : arr){
			if(((num>>i)&1)==1){
				cnt++;
			}
		}

		if(cnt%3==1){
			ans=ans|(1<<i);
		}
	}
	return ans;
}

int main(){
	vector<int>arr={1,2,3,4,1,2,4,1,2,3,4,3,3};

	cout<<findNumber(arr)<<endl;

	return 0;
}

