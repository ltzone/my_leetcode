#include<iostream>
#include<vector>
#include<string>
#include<limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int len = str.size();
        bool isPos = true;
        int i;
        for (i=0;i<len&&str[i]==' ';++i) {}
        if (str[i]=='+' || str[i]=='-'){
            isPos = (str[i]=='+');i++;
        }
        
        if (isPos) {
            while (str[i] <= '9' && str[i] >= '0') {
                if (result > INT_MAX/10 || (result == INT_MAX/10 && str[i]-'0' >= 7))
                    return INT_MAX;
                result *= 10;
                result += str[i] - '0';
                i++;
            }
        } else {
            while (str[i] <= '9' && str[i] >= '0') {
                if (result < INT_MIN/10 || (result == INT_MIN/10 && str[i]-'0' >= 8))
                    return INT_MIN;
                result *= 10;
                result -= str[i] - '0';
                i++;
            }
        }
        
        return result;
    }
};