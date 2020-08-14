#include<vector>
#include<string>
#include<iostream>
#include<queue>
using namespace std;

typedef struct work {
    string generated;
    int remainLeft;
    int allowRight;
    
    work (string g, int l, int r):generated(g),remainLeft(l),allowRight(r){};
} work;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<work> worklist;
        vector<string> result;
        work initWork("",n,0);
        worklist.push(initWork);
        
        while (!worklist.empty()){
            work curWork = worklist.front();
            worklist.pop();
            if (curWork.remainLeft == 0){
                curWork.generated.append(curWork.allowRight,')');
                result.push_back(curWork.generated);
            } else {
                string curGen1(curWork.generated);
                string curGen2(curWork.generated);
                if (curWork.allowRight > 0){
                    work rightWork(curGen1.append(")"), curWork.remainLeft, curWork.allowRight - 1);
                    worklist.push(rightWork);
                }                
                work leftWork(curGen2.append("("), curWork.remainLeft - 1, curWork.allowRight + 1);
                worklist.push(leftWork);
            }
        }
        return result;
    }
};

int main(){
  Solution s;
  vector<string> result = s.generateParenthesis(3);
  for (int i=0;i<result.size();++i){
      cout << result[i]<< endl;
  }
}