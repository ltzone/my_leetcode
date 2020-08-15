#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string result;
        int period = numRows*2 - 2;
        for (int i=0; i<s.size();i+=period)
            result.push_back(s[i]);
        for (int row=1;row<numRows-1;++row){
            int i = row;
            int cnt = 0;
            while (i<s.size()){
                result.push_back(s[i]);
                cnt++;
                i = period * (cnt/2) + (cnt%2 == 0 ? row : period - row);
            }
        }
        for (int i=numRows-1; i<s.size();i+=period)
            result.push_back(s[i]);
        return result;
    }
};