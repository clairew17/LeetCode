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





class ZigzagIterator {
public:
    //use queue to round robin
    queue<vector<int>>vectors;
    
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty())vectors.push(v1);
        if(!v2.empty())vectors.push(v2);
    }

    int next() {
        auto v = vectors.front(); vectors.pop();
        int val = v[0];
        
        //erase fetched data
        v.erase(v.begin());
        //if vector is non empty, push it to the queue's tail
        if(!v.empty())vectors.push(v);
        return val;
    }

    bool hasNext() {
        return (!vectors.empty());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */



class ZigzagIterator {
private:
    int intPointer;
    vector<vector<int>>vectors;
    queue<int>q;
    map<int, int>m;//vector num and its start ind
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int i = 0;
        if(!v1.empty()){
            vectors.push_back(v1);
            q.push(i);
            m[i++] = 0;
        }
        if(!v2.empty()){
            vectors.push_back(v2);
            q.push(i);
            m[i++] = 0;
        }
    }

    int next() {

        if(hasNext()==false){
            cout << "\nEmpty vectors\t";
            return -1;
        }
        
        int which_vect = q.front(); q.pop();
        int ind = m[which_vect];
        int val = vectors[which_vect][ind++];
        m[which_vect] = ind;
        if(ind < vectors[which_vect].size()){
            q.push(which_vect);
        }
        return val;
    }

    bool hasNext() {
        return !(q.empty());
    }
};








