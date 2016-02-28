class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int max_l = 0, max_r = 0, res = 0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>max_l){
                    max_l = height[l];
                }else{
                    res += (max_l - height[l]);
                }
                l++;
            }else{
                if(height[r]>max_r){
                    max_r = height[r];
                }else{
                    res += (max_r - height[r]);
                }
                r--;
            }
        }
        return res;
    }
};


class Solution {
public:

int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    //level: safe level of max left/right height
    while (l < r) {
        int lower;
        if(height[l] <= height[r])
            lower = height[l++];
        else lower = height[r--];
        //update the max height
        level = max(level, lower);
        water += (level - lower);//discard the lower water
    }
    return water;
}

};