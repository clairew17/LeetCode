279. Perfect Squares.cc


class Solution {
public:
    int BFS(int n){
        //store the remainder
        queue<int>q;
        q.push(n);
        //cnt is the size of current level
        int cnt = q.size();
        int level = 0;
        while(cnt>0)
        {
            cnt--;
            auto x = q.front();q.pop();
            
            for(int i=sqrt(x);i>0;i--){
                q.push(x-i*i);
                if(x==i*i)return level+1;
            }
            if(cnt==0)//finish BFS of current level
            {
                cnt = q.size();//count size of next level
                level++;//update level
            }
        }
        return -1;
    }
    int numSquares(int n) {
        int res = BFS(n);
        return res;
    }
};



class Solution {
public:
    void DFS(int n, int level, int &res){
        
        if(n==0)//already found
        {
            if(res>level)//update
            {
                res=level;
            }
            return;
        }
        
        //search for next level
        level++;
        //pruning
        if(level>=res)return;
        
        //subtract square
        for(int i=sqrt(n);i>0;i--)
        {
            DFS(n-i*i,level,res);
        }

    }
    int numSquares(int n) {
        int res = INT_MAX;
        DFS(n,0,res);
        return res;
    }
};