#include<iostream>
#include<vector>
#include<string>
using namespace std;


class SearchFromMiddleSolution2 {
public:
    int longestPalindrome(string s) {
        int maxsize = 0;
        int leftPtr = 0;
        int rightPtr = 0;
        while (rightPtr < s.length()-1){
            while (s[leftPtr] == s[rightPtr+1]){
                rightPtr++;
            }
            int nextLeft = rightPtr+1;
            while (leftPtr > 0 && rightPtr < s.length()-1 && s[leftPtr-1]==s[rightPtr+1]){
                leftPtr--;rightPtr++;
            }
            if (maxsize<rightPtr-leftPtr+1){
                maxsize=rightPtr-leftPtr+1;
            }
            leftPtr = nextLeft; rightPtr = nextLeft;
        }
        return maxsize;
    }
};


class SearchFromMiddleSolution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int max_len = 0;
        int start_idx = 0;
        int i = 0;
        while(i < s.size()) {
            int r_ptr = i; 
            int l_ptr = i;
            //find the middle of a palindrome
            while(r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr + 1]) r_ptr++;
            i = r_ptr+1;
            //expand from the middle out
            while(r_ptr < s.size()-1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) {
                r_ptr++;
                l_ptr--;
            }
            int new_len = r_ptr - l_ptr + 1;
            if(new_len > max_len) {
                start_idx = l_ptr;
                max_len = new_len;
            }
        }
        return s.substr(start_idx, max_len);
    }
};



class DPSolution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        int t = s.length();
        char* s2 = new char[t];
        for (int i=0;i<t;++i)
            s2[i] = s[t-i-1];
        int longest = 0;
        int record = 0;
        int** dyRes = new int* [t];
        for (int i=0;i<t;++i){
            dyRes[i] = new int[t];
        }
        
        for (int i=0;i<t;++i){
            for (int j=0;j<t;++j){
                if (s[i] == s2[j]){
                    if (i == 0 || j == 0) {
                        dyRes[i][j] = 1;
                        if (dyRes[i][j] > longest && i + j + 2 - dyRes[i][j] == t){
                            longest = dyRes[i][j];
                            record = i;
                        }
                    } else {
                        dyRes[i][j] = dyRes[i-1][j-1]+1;
                        if (dyRes[i][j] > longest && i + j + 2 - dyRes[i][j] == t){
                            longest = dyRes[i][j];
                            record = i;
                        }
                    }
                } else {
                    dyRes[i][j] = 0;
                }
            }
        }
        
        
        // for (int i=0;i<t;++i){
        //     for (int j=0;j<t;++j){
        //         cout << dyRes[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        
        delete [] s2;
        for (int i=0;i<t;++i)
            delete [] dyRes[i];
        delete [] dyRes;
        
        
        return s.substr(record-longest+1,longest);
    }
    
private:
    
    
};