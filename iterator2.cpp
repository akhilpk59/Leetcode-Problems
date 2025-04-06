#include<iostream>
#include<vector>
using std::vector;
//  * Below is the interface for Iterator, which is already defined for you.
//  * **DO NOT** modify the interface for Iterator.
//  *
class Iterator {
    struct Data;
 	Data* data;
public:
 	Iterator(const vector<int>& nums);
 	Iterator(const Iterator& iter);
 
// Returns the next element in the iteration.
	int next();
 
// Returns true if the iteration has more elements.
 	bool hasNext() const;
};
 

class PeekingIterator : public Iterator {
    bool hasPeeked;
    int peekValue;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    hasPeeked = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!hasPeeked){
            peekValue = Iterator::next();
            hasPeeked = true;
        }
        return peekValue;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (hasPeeked){
            return peekValue;
            hasPeeked = false;
        }
        else return Iterator::next();
	}
	
	bool hasNext() const {
	    return hasPeeked||Iterator::hasNext();
	}
};