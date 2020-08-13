#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max = 0;
        int leftPos = 0, rightPos = len-1;
        while (leftPos < rightPos) {
            if (height[leftPos] < height[rightPos]) {
                int curSize = (rightPos - leftPos) * height[leftPos];
                if (curSize > max)
                    max = curSize;
                leftPos ++;
            } else {
                int curSize = (rightPos - leftPos) * height[rightPos];
                if (curSize > max)
                    max = curSize;
                rightPos --;
            }
        }
        return max;
    }
};


class SkipIterSolution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max = 0;
        int nexti;
        for (int i=0;i<len;i = nexti){
            nexti = i + 1;
            bool nextflag = true;
            for (int j=i+1;j<len;++j){
                int curSize;
                if (height[j] >= height[i]) {
                    curSize =  (j - i) *height[i];
                    if (nextflag) {
                        nexti = j;
                        nextflag = false;
                    }
                } else {
                    curSize =  (j - i) * height[j];
                }
                if (curSize > max) {
                    max  = curSize;
                }
                // cout << i << " " << j << " " << nexti << endl;
            }
        }
        return max;
    }
};