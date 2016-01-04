#include<iostream>
#include<vector>
using namespace std;
struct rectangle
{
	int min_x;
	int min_y;
	int max_x;
	int max_y;
	rectangle(int a, int b, int c, int d):min_x(a),min_y(b),max_x(c),max_y(d){}
};
void helper(vector<vector<char>>& image, int x, int y, rectangle *rec){
	cout << "("<<x<<','<<y<<")"<<endl;
	if(x>=0 && x < image.size() && y >=0 &&y<image[0].size() && image[x][y]== '1'){
		image[x][y] = '0';

		rec->min_x = min(x, rec->min_x);
		rec->min_y = min(y, rec->min_y);
		rec->max_x = max(x, rec->max_x);
		rec->max_y = max(y, rec->max_y);

		//if(x>0 && image[x-1][y]== '1')
			helper(image,x-1, y, rec);
		//if(x<image.size()-1 && image[x+1][y]== '1')
			helper(image,x+1, y, rec);
		//if(y>0 && image[x][y-1]== '1')
			helper(image,x, y-1, rec);
		//if(y<image[0].size()-1 && image[x][y+1]== '1')
			helper(image,x, y+1, rec);

		//image[x][y] = '1';
	}else{
		return;
	}
}
int minArea(vector<vector<char>>& image, int x, int y) {
	int m = image.size(), n = image[0].size();
	//cout << m << n <<endl;
	rectangle *rec = new rectangle(m, n, -1, -1);
	int area = 0;
	helper(image,x, y, rec);
	//cout << rec->min_x <<','<<rec->max_x<<','<<rec->min_y<<','<<rec->max_y<<endl;
	if(rec->max_x<rec->min_x || rec->max_y < rec->min_y)return 0;
	area = abs(rec->max_x-rec->min_x+1)*abs(rec->max_y-rec->min_y+1);
	return area;
}
int main(){
	vector<vector<char>>image(5);
	string arr[] ={
	"0000000000000000000000001100111111110000000000000000000000000000000000000000000",
	"0000000000000000000000000111111111110000000000000000000000000000000000000000000",
	"0000000000000000000000000001111110110000000000000000000000000000000000000000000",
	"0000000000000000000000000011111110100000000000000000000000000000000000000000000",
	"0000000000000000000000001111111110000000000000000000000000000000000000000000000"};
	for(int i=0;i<5;i++){
		//cout << arr[i].size() <<endl;
		for(int j=0;j<arr[i].size();j++){
			image[i].push_back(arr[i][j]);
			cout << image[i][j]<<',';
		}
		cout << endl;
	}
	
	cout <<endl<< minArea(image, 3, 34) <<endl;
	return 0;
}