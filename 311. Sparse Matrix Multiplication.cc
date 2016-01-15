311. Sparse Matrix Multiplication.cc

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    
    vector<vector<int>> dummy;
    if(A.empty() || B.empty()) return dummy;
    if(A.front().size()!=B.size()) return dummy;
    vector<vector<int>> res(A.size(),vector<int>(B.front().size(),0));
    unordered_map<int, unordered_map<int, int>> Amap;
    for(int i=0;i<(int)A.size();++i){
        for(int j=0;j<(int)A.front().size();++j){
            if(A[i][j]!=0){
                Amap[i][j]=A[i][j];
            }
        }
    }
    //Transposed hashmap B matrix 
    unordered_map<int, unordered_map<int, int>> BTmap;
    for(int i=0;i<(int)B.size();++i){
        for(int j=0;j<(int)B.front().size();++j){
            if(B[i][j]!=0){
                BTmap[j][i]=B[i][j];
            }
        }
    }

    //looping through the iterators should be fast if it is really sparse
    for(auto itA=Amap.begin();itA!=Amap.end();++itA){
        for(auto itBT=BTmap.begin();itBT!=BTmap.end();++itBT){
            int sum=0;
            for(auto itAj=itA->second.begin(); itAj!=itA->second.end();++itAj){
                auto itBTj=itBT->second.find(itAj->first);
                if(itBTj!=itBT->second.end()){
                    sum+=itAj->second*itBTj->second;
                }
            }
            res[itA->first][itBT->first]=sum;
        }
    }

    return res;
        
        
    }
    void MapMatrix(map<int,map<int,int>>&m, vector<vector<int>>A){
        for(int i=0;i<A.size();i++){
            for(int j=0; j<A[0].size();j++){
                if(A[i][j]!=0)
                    m[i][j]=A[i][j];
            }
        }
    }
};