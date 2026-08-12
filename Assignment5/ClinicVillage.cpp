#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

double findMinMaxLoad(vector<int>&population,int k){
	int n=population.size();
	if(k<n) return -1;

	vector<int>clinic(n,1);

	priority_queue<pair<double,int>>pq;
	// {load,index}
	
	for(int i=0;i<n;i++){
		pq.push({(double)population[i],i});
	}

	k=k-n;
	while(k>0){
		double load=pq.top().first;
		int village=pq.top().second;

		pq.pop();

		clinic[village]++;

		double newload=(double)population[village]/clinic[village];

		pq.push({newload,village});

		k--;
	}
	return pq.top().first;
}

int main(){
	vector<int>population= {200,20,50};
	int k=5;
	double res=findMinMaxLoad(population,k);
	cout<<fixed<<setprecision(2)<<res<<endl;

	return 0;
}

