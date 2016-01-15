//295. Find Median from Data Stream.


class MedianFinder {
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