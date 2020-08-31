#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end());
        vector<int> ufs(n+1);
        for (int i=0;i<ufs.size();++i){
            ufs[i]=i;
        }
        for (int &a : A) {
            for (int k = 2; k <= sqrt(a); k++) {
                if (a % k == 0) {
                    unionset(ufs, a, k);
                    unionset(ufs, a, a / k);
                }
            }
        }
        
        unordered_map<int, int> mp;
        int ans = 1;
        for (int &a : A) {
            ans = max(ans, ++mp[find(ufs,a)]);
        }
        return ans;
        
    }
    
    int find(vector<int> &ds,int i){
        if (ds[i]==i)
            return i;
        return ds[i] = find(ds,ds[i]);
    }
    
    void unionset(vector<int> &ds,int i, int j){
        ds[find(ds,i)] = ds[find(ds,j)];
    }

};


class FindUnionSolution {
public:
    int largestComponentSize(vector<int>& A) {
        int size = A.size();
        unordered_map<int,vector<int>> aux;
        
        for (int i=0;i<size;++i){
            int a = A[i];
            int j=2;
            while (a>1){
                if (a%j==0){
                    a = a/j;
                    unordered_map<int,vector<int>>::iterator iter = aux.find(j);
                    if (iter == aux.end()) {
                        vector<int> tmp(1,i);
                        aux.insert({j,tmp});
                    } else {
                        vector<int>&tmp = iter->second;
                        if (tmp.back() != i){
                            tmp.push_back(i);
                            aux.insert({j,tmp});
                        }
                    }
                } else {
                    ++j;
                }
            }    
        }
//         for (unordered_map<int,vector<int>>::iterator i=aux.begin();i!=aux.end();++i){
//             cout << i->first << ": ";
//             for (int j=0;j<i->second.size();++j){
//                 cout << i->second[j] << " ";
//             }
//             cout << endl;
//         }
                
//         return 0;
        vector<int> ds(size,-1);
        int result=0;
        for (unordered_map<int,vector<int>>::iterator i=aux.begin();i!=aux.end();++i){
            for (int j=0;j<i->second.size()-1;++j){
                int t1 = find(ds,i->second[j]);
                int t2 = find(ds,i->second[j+1]);
                int tmpres = unionset(ds,t1,t2);
                if (tmpres > result)
                    result = tmpres;
            }
            // for (int k=0;k<size;++k){
            //     cout << ds[k] << " ";
            // }
            // cout << endl;
        }
        return result;
    }
    
    int find(vector<int> &ds,int i){
        if (ds[i]<0)
            return i;
        return ds[i] = find(ds,ds[i]);
    }
    
    int unionset(vector<int> &ds, int i, int j){
        if (i == j)
            return (-ds[i]);
        if (ds[i] > ds[j]){
            ds[j] += ds[i];
            ds[i] = j;
            return (-ds[j]);
        } else {
            ds[i] += ds[j];
            ds[j] = i;
            return (-ds[i]);
        }
    }

};


class DFSSolution {
public:
    int largestComponentSize(vector<int>& A) {
        int size = A.size();
        
        vector<bool> visited(size, false);
        int result=0;
        for (int i=0;i<size;++i){
            if (!visited[i]){
                int retSize = dfs(A,visited,i,size);
                if (retSize>result)
                    result = retSize;
            }
        }
        return result;
    }
    
    int dfs(const vector<int> & A, vector<bool> & visited, int i, int size){        
        int sccSize = 1;
        visited[i] = true;
        for (int k=0;k<size;++k){
            if (!visited[k] && isConnected(A[i],A[k])){
                sccSize += dfs(A,visited,k,size);
            }
        }
        return sccSize;
    }
    
    bool isConnected(int a, int b){
        int tmp;
        while (b>0){
            tmp = a%b;
            a = b;
            b = tmp;
        }
        return a==1 ? false : true; 
    }
};
