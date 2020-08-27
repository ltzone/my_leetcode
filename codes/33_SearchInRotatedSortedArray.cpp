#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return target == nums[0] ? 0 : -1;

        int len = nums.size();
        int sMin = 0;
        int sMax = len-1;
        int start;
        while (sMin <= sMax){
            start = (sMin + sMax)/2;
            // cout << sMin << " " << sMax << " " << start << endl;
            if (nums[sMin]<=nums[sMax]){
                start = sMin; break;
            }
            if (nums[start] >= nums[sMin]){
                sMin = start + 1;
            } else {
                sMax = start;
            }

        }
        cout << start;
        sMin = 0;
        sMax = len-1;
        while (sMin <= sMax){
            int mid = (sMin + sMax)/2;
            int val = nums[(start+mid)%len];
            if (val == target)
                return (start+mid)%len;
            if (val < target)
                sMin = mid + 1;
            else
                sMax = mid - 1;
        }
        
        return -1;
    }
};