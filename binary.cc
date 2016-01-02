
#include"../CC/header.h"

int main(){

	int x = 2;
	int y = x & (-x);

	cout << x << '\t'  << y << endl;
	cout <<std::bitset<8>(x) << '\n'<<std::bitset<8>(-x) << '\n' << std::bitset<8>(y)<< endl;
	return 0;
}