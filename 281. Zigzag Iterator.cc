//281. Zigzag Iterator.cc

#include"../CC/header.h"


class ZigzagIterator {
private:
    int intPointer;
    vector<vector<int>>vect;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vect.push_back(v1);
        vect.push_back(v2);
        intPointer = 0;
    }

    int next() {

        if(hasNext()==false){
        	cout << "\nEmpty vectors\t";
        	return -1;
        }
        if(vect[intPointer].empty())intPointer = 1 - intPointer;

        int val = vect[intPointer].front();
        vect[intPointer].erase(vect[intPointer].begin());

        if(!vect[1-intPointer].empty())intPointer = 1 - intPointer;
        return val;
    }

    bool hasNext() {
        return !(vect[intPointer].empty() && vect[1-intPointer].empty());
    }
};

int main(){
	int len1 = 2, len2 = 4;
	vector<int> v1 = GenerateRandomVector(len1);
	vector<int> v2 = GenerateRandomVector(len2);
	PrintVector(v1);PrintVector(v2);

	ZigzagIterator iter(v1, v2);
	for(int i=0;i<len1+len2;i++){
		cout << iter.next() << ',';
	}
	cout <<endl;
	return 0;
}