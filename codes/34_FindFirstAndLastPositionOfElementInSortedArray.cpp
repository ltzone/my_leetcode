#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0)
            return {-1,-1};
        
        
        int len = nums.size();
        int sMin = 0;
        int sMax = len - 1;
        int mid;
        while (sMin <= sMax){
            mid = (sMin + sMax) / 2;
            if (nums[mid] == target){
                if (mid > 0 && nums[mid-1] == target){
                    sMax = mid - 1;
                } else {
                    break;
                }
            }
            else if (nums[mid] < target)
                sMin = mid + 1;
            else
                sMax = mid - 1;
        }
        if (nums[mid] != target)
            return {-1, -1};
        
        sMin = 0;
        sMax = len - 1;
        int mid2;
        while (sMin <= sMax){
            mid2 = (sMin + sMax) / 2;
            // cout << sMin << " "<< sMax <<" "<< mid2 << endl;
            if (nums[mid2] == target){
                if (mid2+1 < len && nums[mid2+1] == target){
                    sMin = mid2 + 1;
                } else {
                    break;
                }
            }
            else if (nums[mid2] < target)
                sMin = mid2 + 1;
            else
                sMax = mid2 - 1;
        }
        return {mid, mid2};
    }
};