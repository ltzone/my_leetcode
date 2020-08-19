#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dpresult;
        for (int i=0;i<=s.size();++i){
            vector<bool> tmp(p.size()+1,false);
            dpresult.push_back(tmp);
        }
        dpresult[s.size()][p.size()] = true;
        
        for (int j=p.size()-1;j>=0;--j){
            for (int i=s.size();i>=0;--i){
                bool simpleMatch = (i<s.size())&&(p[j] == s[i] || p[j] == '.');
                if (p.size() > j+1 && p[j+1] == '*'){
                    dpresult[i][j] = (simpleMatch && dpresult[i+1][j]) || dpresult[i][j+2];
                } else {
                    dpresult[i][j] = simpleMatch && dpresult[i+1][j+1];
                }
            }
        }
        return dpresult[0][0];
    }
};


class RecursionSolution {
public:
    bool isMatch(string s, string p) {
        return isMatchRec(s,p,0,0);
    }
    
private:
    bool isMatchRec(const string& s, const string& p, int i, int j){
        if (p.size() == j)
            return (s.size()==i);
        bool simpleMatch = (s.size()-i>0) && (p[j] == s[i] || p[j] == '.');
        if (p.size() > j+1 && p[j+1] == '*'){
            return ((simpleMatch && isMatchRec(s,p,i+1,j)) || isMatchRec(s,p,i,j+2));
        } else {
            return (simpleMatch && isMatchRec(s,p,i+1,j+1));
        }
    }
};


int main(){
  RecursionSolution s;
  cout << s.isMatch("abbbbbcdezf","ab*cde.f") << endl;
  return 0;
}