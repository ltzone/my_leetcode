#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for (int i=1;i<n;++i){
            dp[i+1] = dp[i] + dp[i-1];
        }
        return dp[n];       
    }
};