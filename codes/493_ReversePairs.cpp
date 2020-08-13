#include<iostream>
#include<vector>
using namespace std;

// idea: merge-sort + doublepointer


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return reversePairs_rec(nums,0,nums.size()-1);
    }
    
    int reversePairs_rec(vector<int>& nums, int beginPos, int endPos) {
        if (endPos-beginPos <= 0)
            return 0;

        int midPos = (beginPos + endPos) / 2;
        int leftPairsCnt = reversePairs_rec(nums, beginPos, midPos);
        int rightPairsCnt = reversePairs_rec(nums, midPos+1, endPos);
        
        int mergePtr = 0;
        int leftPtr = beginPos;
        int doubleLeftPtr = beginPos;
        int rightPtr = midPos + 1;
        int mergePairsCnt = 0;
        for (int i=beginPos,j=midPos+1; i<=midPos && j<=endPos; j++){
            while(i <= midPos && nums[i] / 2.0 <= nums[j]){
                i++;
            }
            mergePairsCnt += midPos - i + 1;
        }
        
        vector<int> mergeResult = vector<int> (endPos - beginPos + 1);
        while (leftPtr <= midPos && rightPtr <= endPos) {
            if (nums[leftPtr] < nums[rightPtr]) {
                mergeResult[mergePtr++] = nums[leftPtr++];
            } else {
                mergeResult[mergePtr++] = nums[rightPtr++];
            }
        }
        while (leftPtr <= midPos) {
            mergeResult[mergePtr++] = nums[leftPtr++];
        }
        while (rightPtr <= endPos) {
            mergeResult[mergePtr++] = nums[rightPtr++];
        }
        
        for (int i=0;i<mergeResult.size();i++){
            nums[beginPos+i] = mergeResult[i];
            // cout << mergeResult[i] << " ";
        }
        

        
        
        // cout << "[" << leftPairsCnt << " " << mergePairsCnt << " " << rightPairsCnt << "]" << endl;
        return leftPairsCnt + mergePairsCnt + rightPairsCnt;
    }
};