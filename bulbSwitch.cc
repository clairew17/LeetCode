//bulbSwitch.cc
#include"header.h"

void bulbSwitch(vector<int> &res, int step) {
	for(int i=step-1;i<res.size();i += step){
		res[i] = 1-res[i];
	}
}

int main(){

	int n = 9999999;
	vector<int>res(n,0);
	//PrintVector(res);

	for(int step=1;step<=n;step++){
		for(int i=step-1;i<n;i += step){
			res[i] = 1-res[i];
		}
		//PrintVector(res);
	}

	int count =0;
	for(auto r:res){
		count += r;
	}
	
	cout << count << endl;
	return count;

}