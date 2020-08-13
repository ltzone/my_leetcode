#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int len = s.length();
        int map[256] = {0};
        // for (int i=0;i<256;++i)
            // map[i] = -1;
        for (int i = 0 ,j = 0; j < len; ++j){
            if (map[s[j]] > i) {
                i = map[s[j]];
            }
            if (ans < j - i + 1) {
                ans = j - i + 1;
            }
            map[s[j]] = j + 1;
            // cout << i << " " << j << endl;
        }
        return ans;        
    }
};