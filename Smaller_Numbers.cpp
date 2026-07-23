#include<iostream>
#include<vector>
using namespace std;

vector<int>ans;
vector<int>idx;

void merge(vector<int>&nums,int left,int mid,int right){
	vector<int>temp;
	int i=left;
	int j=mid+1;
	int count=0;

	while(i<=mid && j<=right){
		if(nums[idx[j]]<nums[idx[i]]){
			temp.push_back(idx[j]);
			count++;
			j++;
		}
		else{
			ans[idx[i]]+=count;
			temp.push_back(idx[i]);
			i++;
		}
	}

	while(i<=mid){
		ans[idx[i]]+=count;
		temp.push_back(idx[i]);
		i++;
	}
	while(j<=right){
		temp.push_back(idx[j]);
		j++;
	}
	for(int k=left;k<=right;k++){
		idx[k]=temp[k-left];
	}
}

void mergeSort(vector<int>&nums,int left,int right){
	if(left>=right) return;

	int mid=(left+right)/2;

	mergeSort(nums,left,mid);
	mergeSort(nums,mid+1,right);

	merge(nums,left,mid,right);
}

void countSmaller(vector<int>&nums){
	int n=nums.size();

	ans.assign(n,0);
	idx.resize(n);

	for(int i=0;i<n;i++){
		idx[i]=i;
	}

	mergeSort(nums,0,n-1);

	for(int x : ans){
		cout<<x<<" ";
	}
}

int main(){
	int n;
	cin>>n;

	vector<int>nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}

	countSmaller(nums);

	return 0;
}
