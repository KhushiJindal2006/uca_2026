#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class MedianFinder {
	private:
		priority_queue<int>maxHeap;
		priority_queue<int,vector<int>,greater<int>>minHeap;
	public:
		void insert(int num){
			if(minHeap.empty() || num<=minHeap.top()){
				minHeap.push(num);
			}
			else{
				maxHeap.push(num);
			}

			if(minHeap.size()>maxHeap.size()+1){
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}
			else if(maxHeap.size()>minHeap.size()+1){
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
		}

		float getMedian(){
			if(minHeap.size()==maxHeap.size()){
				return (minHeap.top()+maxHeap.top())/2.0;
			}

			if(minHeap.size()>maxHeap.size()) return minHeap.top();

			return maxHeap.top();
		}
};

int main(){
	MedianFinder m;
	m.insert(1);
	cout<<"After inserting 1: "<<m.getMedian()<<endl;
	
	m.insert(2);
        cout<<"After inserting 2: "<<m.getMedian()<<endl;

	m.insert(3);
        cout<<"After inserting 3: "<<m.getMedian()<<endl;

	m.insert(4);
        cout<<"After inserting 4: "<<m.getMedian()<<endl;

	m.insert(5);
        cout<<"After inserting 5: "<<m.getMedian()<<endl;

	return 0;
}
