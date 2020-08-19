#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Work {
public:
    int remainDigit;
    int result;
    Work(int d,int r):remainDigit(d),result(r){}
};


class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result;
        if (N==1){
            for (int i=0;i<10;++i)
                result.push_back(i);
            return result;
        }
        queue<Work> worklist;
        for (int i=1;i<10;++i){
            Work w(N-1,i);
            worklist.push(w);
        }
        
        while(!worklist.empty()){
            Work cur = worklist.front();
            worklist.pop();
            if (cur.remainDigit == 0) {
                result.push_back(cur.result);
            } else {
                int lastDigit = cur.result%10;
                if (K == 0){
                    Work next(cur.remainDigit - 1, cur.result*10 + lastDigit);
                    worklist.push(next);
                }
                else {
                  if (lastDigit - K >= 0){
                      Work next(cur.remainDigit - 1,cur.result*10 + lastDigit - K);
                      worklist.push(next);
                  }
                  if (lastDigit + K <= 9) {
                      Work next(cur.remainDigit - 1,cur.result*10 + lastDigit + K);
                      worklist.push(next);
                  }
                }
            }
        }
        
        return result;
    }
};

int main() {
  Solution s;
  vector<int> result = s.numsSameConsecDiff(2,0);
  for (int i=0;i<result.size();++i){
    cout << result[i] << " ";
  }
  cout << endl;
}