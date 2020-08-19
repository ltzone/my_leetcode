#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool compareIntervals(const vector<int>& a, const vector<int>&b){
    if (a[0] < b[0])
        return true;
    else if (a[0] == b[0])
        return (a[1]<b[1]);
    else return false;
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),compareIntervals);
        int last = intervals[0][1];
        int discarded = 0;
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] >= last)
                last = intervals[i][1];
            else {
                if (intervals[i][1] <= last)
                    last = intervals[i][1];
                discarded++;
            }
        }
    return discarded;
    }

private:
};