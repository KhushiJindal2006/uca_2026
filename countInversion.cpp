#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int>&arr,int l,int mid,int r){
	vector<int>temp;
	int i=l;
	int j=mid+1;

	int inv=0;
	while(i<=mid && j<=r){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
			temp.push_back(arr[j]);
			j++;
			inv+=(mid-i+1);
		}
	}

	while(i<=mid){
		temp.push_back(arr[i++]);
	}
	while(j<=r){
		temp.push_back(arr[j++]);
	}
	for(int k=l;k<=r;k++){
		arr[k]=temp[k-l];
	}
	return inv;
}
int mergeSort(vector<int>&arr,int l,int r){
	if(l>=r) return 0;
	int inversion=0;
	int mid=(l+r)/2;

	inversion+=mergeSort(arr,l,mid);
	inversion+=mergeSort(arr,mid+1,r);

	inversion+=merge(arr,l,mid,r);

	return inversion;
}
int inversionCount(vector<int>&arr){
	int n=arr.size();
	return mergeSort(arr,0,n-1);
}
int main(){
	int n;
	cin>>n;

	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<inversionCount(arr);
	return 0;
}
