//255.VerifyPreorder.cc
// Sequence in Binary Search Tree


bool verifyPreorder(vector<int>& preorder) {
        int sz = preorder.size();
        if(sz<2)return true;
        stack<int>s;
        s.push(preorder[0]);
        int currp = INT_MIN;//predecessor
        for(int i=1;i<sz;i++){
            if(s.empty() || preorder[i] < s.top()){//left subtree
                if(preorder[i] < currp)return false;
                s.push(preorder[i]);
            }else{//visit the right tree
                while(!s.empty() && s.top() < preorder[i]){//pop left tree
                    currp = s.top();
                    s.pop();
                }
                s.push(preorder[i]);
            }
        }
        return true;
}