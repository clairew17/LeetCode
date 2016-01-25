170. Two Sum III.cc
class TwoSum {
public:
	unordered_map<int, int>m;
    // Add the number to an internal data structure.
	void add(int number) {
	    m[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	   for(auto mm:m){
	       int i = mm.first;
	       int j = value - i;
	       if(j == i){//if value = 2*i
	           if(mm.second > 1)return true;
	       }else{
	            if(m.find(j) != m.end())return true;
	       }
	   }
	   return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);