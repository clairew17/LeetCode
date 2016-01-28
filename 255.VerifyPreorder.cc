//255.VerifyPreorder.cc
// Sequence in Binary Search Tree


class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int sz = preorder.size();
        if(sz<2)return true;
        stack<int>s;//use stack to DFS
        s.push(preorder[0]);
        int currp = INT_MIN;//predecessor
        for(int i=1;i<sz;i++){
            if(s.empty() || preorder[i] < s.top()){//left subtree
                if(preorder[i] < currp)return false;
                s.push(preorder[i]);
            }else{//visit the right tree
                while(!s.empty() && s.top() < preorder[i]){//pop left tree and preorder[i]'s root
                    currp = s.top();
                    s.pop();
                }
                s.push(preorder[i]);
            }
        }
        return true;
    }
};


class Solution {
public:
    bool verify(vector<int>& preorder, int ps, int pe, long min_val, long max_val){
        if(ps>pe)return true;
        if(preorder[ps]<=min_val || preorder[ps]>= max_val)return false;
        //if(preorder[ps] > preorder[pe])return false;
        
        int i = ps+1;
        while(i<=pe && preorder[i]<preorder[ps])i++;
        //i is the first of right tree
        return verify(preorder, ps+1, i-1, min_val, preorder[ps]) && verify(preorder, i, pe, preorder[ps], max_val);
    }
    bool verifyPreorder(vector<int>& preorder) {
        int sz = preorder.size();
        if(sz<2)return true;
        return verify(preorder, 0, sz-1, LONG_MIN, LONG_MAX);
    }
};