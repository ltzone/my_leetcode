#include<unordered_map>
#include<vector>

using namespace std;


typedef unordered_map<int,int> intmap;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        intmap numMap;
        for (int i=0;i<nums.size();++i){
            intmap::iterator res = numMap.find(nums[i]);
            if (res != numMap.end()){
                return *(new vector<int>({res->second,i}));
            }
            numMap.insert({target-nums[i],i});
        }
        return *(new vector<int>());
    }
};