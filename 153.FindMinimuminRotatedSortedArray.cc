//153.FindMinimuminRotatedSortedArray.cc
#include"../CC/header.h"

int FindMin(int arr[], int sz){
	if(sz==0){
		cout << "emtpy!\n";return -1;
	}
	int min_val;
	int lo=0, hi=sz-1, mid;
	int count =0;
	while(lo<hi){
		while(lo<hi && arr[lo]==arr[lo+1])lo++;
        while(lo<hi && arr[hi]==arr[hi-1])hi--;
		mid = (lo+hi)/2;
		cout << arr[lo]<<'\t'<< arr[mid] <<'\t'<< arr[hi]<< endl;
		//+1 for the floor op
		if(arr[mid]>arr[hi])lo=mid+1;
		else hi=mid;
		if(count++>10)break;
	}
	return arr[lo];
}


int main(){
	//int arr[] = {4, 5, 6, 7, 0, 1, 2};
	int arr[] = {2, 2, 2, 0, 2};
	int sz = sizeof(arr)/sizeof(int);
	//cout << sz << endl;
	cout << FindMin(arr,sz)<<endl;
	return 0;
}