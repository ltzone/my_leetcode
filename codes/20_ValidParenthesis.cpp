#include<stack>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> leftP;
        for (int i=0; i<s.size();++i){
            switch (s[i]){
                case '(':
                case '[':
                case '{':
                    leftP.push(s[i]);
                    break;
                case ')':
                    if (leftP.empty() || leftP.top() != '(')
                        return false;
                    leftP.pop();break;
                case ']':
                    if (leftP.empty() || leftP.top() != '[')
                        return false;
                    leftP.pop();break;
                case '}':
                    if (leftP.empty() || leftP.top() != '{')
                        return false;
                    leftP.pop();break;
                default:
                    break;
            }
        }
        if (leftP.empty())
            return true;
        else
            return false;
    }
};


int main(){
  Solution t;
  cout << t.isValid("()") << endl;
}