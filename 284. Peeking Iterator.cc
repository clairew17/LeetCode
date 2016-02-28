// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int buffer_peek = -1;
    bool buffered = false;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    if(buffered == true){
	        return buffer_peek;
	    }else{
            if(Iterator::hasNext()){
                buffered = true;
                buffer_peek = Iterator::next();
                return buffer_peek;
            }else return -1;
        }
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int next_val = -1;
	    if(buffered == true){
	        //reset the buffered flag because the next iterator is moved on
	        buffered = false;
	        next_val = buffer_peek;
	    }else if (Iterator::hasNext()){
	        next_val = Iterator::next();
	    }
	    return next_val;
	}

	bool hasNext() const {
	    if(buffered == true)return true;
	    else return Iterator::hasNext();
	}
};