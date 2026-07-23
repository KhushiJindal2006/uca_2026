#include<iostream>
#include<vector>
using namespace std;
int cnt;
void merge(vector<int>&arr,int l,int mid,int r){
	vector<int>temp;
	int i=l;
	int j=mid+1;

	while(i<=mid && j<=r){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
			temp.push_back(arr[j]);
			j++;
		}
	}

	while(i<=mid){
		temp.push_back(arr[i]);
		i++;
	}

	while(j<=r){
		temp.push_back(arr[j]);
		j++;
	}

	for(int k=l;k<=r;k++){
		arr[k]=temp[k-l];
	}
}

void countPairs(vector<int>&arr,int l,int mid,int r){
	int j=mid+1;
	for(int i=l;i<=mid;i++){
		while(j<=r && arr[i]>2LL*arr[j]){
			j++;
		}
		cnt+=(j-(mid+1));
	}
}

void mergeSort(vector<int>&arr,int l,int r){
	if(l>=r) return;

	int mid=(l+r)/2;

	mergeSort(arr,l,mid);
	mergeSort(arr,mid+1,r);
	countPairs(arr,l,mid,r);
	merge(arr,l,mid,r);

}
void reversePairs(vector<int>&arr){
	int n=arr.size();
	cnt=0;
	mergeSort(arr,0,n-1);

	cout<<cnt<<endl;
}
int main(){
	int n;
	cin>>n;

	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	reversePairs(arr);

	return 0;
}
