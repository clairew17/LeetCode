//215. Kth Largest Element in an Array.cc
#include"../CC/header.h"


//using multiset
int findKthLargest1(vector<int>& nums, int k) {
    multiset<int>ms;
    for(int i=0;i<nums.size();i++){
        ms.insert(nums[i]);
        if(ms.size()>k)ms.erase(ms.begin());//remove the smallest 
    }
    return *ms.begin();
}


//method1: using priority queue
int findKthLargest2(vector<int>& nums, int k){
	//front: largest
	priority_queue<int>pq(nums.begin(), nums.end());
	for(int i=0;i<k-1;i++){
		pq.pop();
	}
	return pq.top();
}

class Solution {
public:
struct compare
{
    bool operator()(int x, int y){return x>y;}//decending order
};
    int findKthLargest(vector<int>& nums, int k) {
        if(k>nums.size())return -1;
        priority_queue<int, vector<int>, compare>pq;//front:smallest
        for(auto n:nums)
        {
            if(pq.size()<k || pq.top()<n)pq.push(n);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};
//comparator of ascending order
struct compare{
	bool operator()(int x, int y){
		return x>y;//ascending order
	}
};
//using priority queue with size k
int findKthLargest3(vector<int>& nums, int k){
	//front: smallest
	priority_queue<int,vector<int>, compare>pq;
	for(auto n:nums){
		if(pq.size()<k || n > pq.top()){
			pq.push(n);
		}
		if(pq.size()>k)pq.pop();
	}
	return pq.top();
}


	int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            else if (nums[l] >= pivot) l++; 
            else if (nums[r] <= pivot) r--;
        }
        //cout << l << ',' << r <<endl;
        //r is the last element greater than pivot 
        swap(nums[left], nums[r]);
        return r;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
        	//put pos in its position
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }




int main(){
	vector<int>nums={3,2,1,5,6,4};
	int k = 2;
	cout << "The "<<k<<"th largest is: "<< findKthLargest(nums, k)<<endl;
	return 0;
}