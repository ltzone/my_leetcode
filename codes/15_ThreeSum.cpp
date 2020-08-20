#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

typedef unordered_map<int,int> intmap;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        
        for (int i=0;i<len-2;++i){
            int target = -nums[i];
            int front = i+1;
            int back = len-1;
            while (front < back){
                if (nums[front]+nums[back]<target){
                    front++;
                } else if (nums[front]+nums[back]>target){
                    back--;
                } else {
                    vector<int> triplet({nums[i],nums[front],nums[back]});
                    result.push_back(triplet);
                    while (front < back && nums[front] == triplet[1]) front++;
                    while (front < back && nums[back] == triplet[2]) back--;
                }
            while (i + 1 < len && nums[i + 1] == nums[i]) 
                i++;
            }
        }
        
        return result;
    }
    
};

class SlowSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int i=0;i<nums.size();++i){
            vector<vector<int>> tmpRes = twoSum(nums,-nums[i],i+1);
            for(int j=0;j<tmpRes.size();++j){
              ans.push_back(tmpRes[j]);
            }
        }
        
        sort(ans.begin(),ans.end(),mycmp);
        vector<vector<int>>::iterator it;
        it = unique(ans.begin(), ans.end());
        ans.resize(distance(ans.begin(),it) );
        return ans;
    }
    
    static bool mycmp(const vector<int>& a, const vector<int>& b){
        if (a[0]<b[0])
            return true;
        if (a[0]>b[0])
            return false;
        if (a[1]<b[1])
            return true;
        if (a[1]>b[1])
            return false;
        return (a[2]<b[2]);
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target, int beginIdx) {
        intmap numMap;
        vector<vector<int>> ans;
        for (int i=beginIdx;i<nums.size();++i){
            intmap::iterator res = numMap.find(nums[i]);
            if (res != numMap.end()){
                vector<int> tmpans({nums[beginIdx-1], res->second, nums[i]});
                sort(tmpans.begin(),tmpans.end());
                ans.push_back(tmpans);
            }
            numMap.insert({target-nums[i],nums[i]});
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.threeSum(*(new vector<int>()));
    return 0;
}