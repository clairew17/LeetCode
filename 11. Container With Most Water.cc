class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        //start with the widest container, then reduce the width and find higher line
        int i = 0, j = height.size()-1;
        
        while(i<j){
            int h = min(height[i], height[j]);
            water = max(water, h*(j-i));
            
            //search until find higher lines
            while(i<j && height[i]<=h)i++;
            while(i<j && height[j]<=h)j--;
        }
        return water;
    }
};