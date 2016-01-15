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

int row, col;
vector<pair<int,int>>dir={{0,-1},{0,1},{-1,0},{1,0}};

void helper(vector<vector<char>>& image, int x, int y, rectangle *rec){
	//cout << "("<<x<<','<<y<<")"<<endl;
	if(x<0 || x >= row || y <0 || y>= col || image[x][y]== '0')return;
	
	image[x][y] = '0';

	rec->min_x = min(x, rec->min_x);
	rec->min_y = min(y, rec->min_y);
	rec->max_x = max(x, rec->max_x);
	rec->max_y = max(y, rec->max_y);

	for(auto d:dir){
		helper(image,x+d.first, y+d.second, rec);
	}

}
int minArea(vector<vector<char>>& image, int x, int y) {
	row= image.size(), col = image[0].size();
	//cout << m << n <<endl;
	rectangle *rec = new rectangle(row, col, -1, -1);
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
			//cout << image[i][j]<<',';
		}
		//cout << endl;
	}
	
	cout <<endl<< minArea(image, 3, 34) <<endl;
	return 0;
}