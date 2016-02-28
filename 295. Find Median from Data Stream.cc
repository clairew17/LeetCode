//295. Find Median from Data Stream.
#include"../CC/header.h"

class MedianFinder1 {
private:
    priority_queue<int> MaxQ; // max_heap for the first half; ALL num is less than its top
    priority_queue<int, std::vector<int>, std::greater<int> > MinQ; // min_heap for the second half
    //all num is greater than its top
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(MaxQ.empty() || (MaxQ.top()>num)){//if it belongs to the smaller half
            MaxQ.push(num); 
        }else{
            MinQ.push(num);
        }

        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(MaxQ.size() > (MinQ.size()+1))
        {
            MinQ.push(MaxQ.top());
            MaxQ.pop();
        }else if(MaxQ.size()+1<MinQ.size())
        {
            MaxQ.push(MinQ.top());
            MinQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(MaxQ.size() == MinQ.size()){
            if(MaxQ.empty())
                return 0;
            else 
                return (MaxQ.top()+MinQ.top())/2.0;
        }else{
            if(MaxQ.size() > MinQ.size())
                return MaxQ.top();
            else return MinQ.top();
        }
    }
};


class MedianFinder {
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
       
        
        //balance
        if(minHeap.size() > maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }else if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
    }

    // Returns the median of current data stream
    double findMedian() {

        if(maxHeap.size() == minHeap.size()){
            if(maxHeap.size()==0)//no valid number
                return -1;
            else 
                return double(minHeap.top() + maxHeap.top())/2;
        }else if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }else{
            return minHeap.top();
        }
        
    }
};

int main(){
    //priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    int arr[] ={4,4};//,2,1,6,9};
    int sz = sizeof(arr)/sizeof(int);

    MedianFinder MF;
    for(int i = 0;i< sz; i++){
        MF.addNum(arr[i]);
        cout <<MF.findMedian() << endl;
    }


    return 0;
}