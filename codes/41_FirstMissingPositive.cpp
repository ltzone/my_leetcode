#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // filter zero or negative integers
        int len = nums.size();
        for (int i=0;i<len;++i){
            while (nums[i] <= 0) {
                swap(nums, i, --len);
                if (i == len) {
                    break;
                }
            }
        }
        
        for (int i=0;i<len;++i){
            int idx = abs(nums[i]) - 1;
            if (idx < len){
                if (nums[idx] > 0) {
                    nums[idx] = -nums[idx];
                }
            }
        }
        
        int result = -1;
        for (int i=0;i<len;++i){
            if (nums[i]>0){
                result = i+1;
                break;
            }
        }
        if(result<0)
            result = len+1;
        // cout << len;
        return result;
    }
    
    void swap(vector<int>&nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};