#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        int tmp=0;
        for (int i=0;i<version1.size();++i){
            if (version1[i]=='.'){
                v1.push_back(tmp);
                tmp=0;
            } else {
                tmp = tmp*10+(version1[i]-'0');    
            }
        }
        v1.push_back(tmp);tmp=0;
        for (int i=0;i<version2.size();++i){
            if (version2[i]=='.'){
                v2.push_back(tmp);
                tmp = 0;
            } else {
                tmp = tmp*10+(version2[i]-'0');
            }
        }
        v2.push_back(tmp);
        int i=0,j=0;
        while(i<v1.size()&&j<v2.size()){
            if (v1[i]<v2[j]){
                return -1;
            } else if (v1[i]>v2[j]){
                return 1;
            }
            i++;j++;
        }
        while(i<v1.size()){
            if (v1[i]!=0)
                return 1;
            ++i;
        }
        while(j<v2.size()){
            if (v2[j]!=0)
                return -1;
            ++j;
        }
        return 0;
    }
};