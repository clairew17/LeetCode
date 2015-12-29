//204.CountPrimes.cc

#include"../CC/header.h"

int countPrimes(int n) {
	//indicate if i is prime num
    vector<bool>Prime(n,true);
    vector<int>PrimeNum;
    Prime[0] = false;
    Prime[1] = false;
    if(n<=2)return 0;

    int count=1;
    Prime[2] = true;
    PrimeNum.push_back(2);
    //mark times of 2 to be non-prime
    int i=2;
    for(int j=i*i;j<=n;j+=i){
    	Prime[j] = false;
    }
    

    int upper = sqrt(n);
    for(int i=3;i<n;i+=2){
    	if(Prime[i]){
    		PrimeNum.push_back(i);
    		count++;
    		//avoid overflow
    		if (i>upper)continue;
    		for(int j=i*i;j<=n;j+=i){
    			Prime[j] = false;
    		}
    	}
    }

    PrintVector(PrimeNum);
    return count;
}


int main(int argc, char *argv[]){

	countPrimes(stoi(argv[1]));
	return 0;
}