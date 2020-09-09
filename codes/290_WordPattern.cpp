#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> split;
        int start = 0, len = 0;
        for (int i=0;i<str.size();++i){
            if (str[i]==' '){
                split.push_back(str.substr(start,len));
                start = i+1;len=0;
            } else {
                len++;
            }
        }
        split.push_back(str.substr(start,len));
        if (pattern.size()!=split.size())
            return false;
        
        map<char,string> mp;
        set<string> st;
        for (int i=0;i<split.size();++i){
            auto mpres = mp.find(pattern[i]);
            if (mpres == mp.end()){
                if (st.find(split[i])!=st.end()){
                    return false;
                }
                mp.insert(pair<char,string>(pattern[i],split[i]));
                st.insert(split[i]);
            } else if ((mpres->second).compare(split[i]) != 0){
                return false;
            }
        }
        return true;
    }
};