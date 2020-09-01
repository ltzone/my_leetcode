#include<vector>
#include<algorithm>
using namespace std;

bool intervalcmp (const vector<int> &t1, const vector<int> &t2){
    return (t1[0]<t2[0]);
}

int max (const int &t1, const int &t2){
    return t1>t2?t1:t2;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),intervalcmp);
        vector<vector<int>> result;
        if (intervals.size()==0)
            return result;
        
        int curbegin=intervals[0][0];
        int curend=intervals[0][1];
        for (int i=1;i<intervals.size();++i){
            if (intervals[i][0]<=curend){
                curend = max(curend,intervals[i][1]);
            } else {
                vector<int> tmp({curbegin,curend});
                result.push_back(tmp);
                curbegin = intervals[i][0];
                curend = intervals[i][1];
            }
        }
        vector<int> tmp({curbegin,curend});
        result.push_back(tmp);
        
        return result;
    }
};