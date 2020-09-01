#include<vector>
using namespace std;

class GreedySolution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size()-1;
        for (int i=nums.size()-1;i>=0;--i){
            if (i+nums[i]>=lastPos){
                lastPos=i;
            }
        }
        return lastPos == 0;
        
    }
    
};

class DPBottomSolution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(),0);
        memo[nums.size()-1] = 1;
        
        for (int i=nums.size()-2;i>=0;i--){
            int furJump = min(i+nums[i],nums.size()-1);
            for (int j=i+1;j<=furJump;j++){
                if (memo[j] == 1){
                    memo[i] = 1;
                    break;
                }
            }
        }
        
        
        return memo[0]==1;
    }    
        
    int min (const int & a, const int & b) {
      return !(b<a)?a:b;
    }
};


class DPTopSolution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(),0);
        memo[nums.size()-1] = 1;
        return canJumpFrom(0,nums,memo);
    }
    
    int min (const int & a, const int & b) {
      return !(b<a)?a:b;
    }
    
    bool canJumpFrom(int pos, vector<int>& nums, vector<int> & memo){
        if (memo[pos] != 0){
            return memo[pos]==1?true:false;
        }
        
        
        int furJump = min(pos+nums[pos],nums.size()-1);
        for (int i=pos+1;i<=furJump;i++){
            if (canJumpFrom(i,nums,memo)){
                memo[pos] = 1;
                return true;
            }
        }
        memo[pos] = 2;
        return false;
    }
};