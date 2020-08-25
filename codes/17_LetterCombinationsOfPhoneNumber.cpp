#include<string>
#include<vector>
#include<queue>
using namespace std;

typedef struct Work {
    string leftDigit;
    string gen;
    Work(string digits){
        for (int i=digits.length()-1;i>=0;--i){
            leftDigit.push_back(digits[i]);
        }
    }
    
    Work(string l, string g):
        leftDigit(l),gen(g){};
    
} work;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length()==0){
            return result;
        }
        
        queue<work> workList;
        Work initWork(digits);
        workList.push(initWork);

        
        while (!workList.empty()){
            work& curWork = workList.front();
            if (curWork.leftDigit.size() == 0)
                result.push_back(curWork.gen);
            else {
                int curDigit = curWork.leftDigit.back() - '2';
                curWork.leftDigit.pop_back();
                for (int j=0;j<map[curDigit].size();++j){
                    string newstr(curWork.gen);
                    newstr.push_back(map[curDigit][j]);
                    work newWork(curWork.leftDigit,newstr);
                    workList.push(newWork);
                }
            }
            workList.pop();
        }
        
        
        return result;
    }
    
    
    Solution(){
        map.push_back("abc");
        map.push_back("def");
        map.push_back("ghi");
        map.push_back("jkl");
        map.push_back("mno");
        map.push_back("pqrs");
        map.push_back("tuv");
        map.push_back("wxyz");
    }
    
private:    
    vector<string> map;
    
};