#include<vector>
#include<string>
#include<iostream>
using namespace std;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength):
        chars(characters),
        index(combinationLength,0) {
        charLen = characters.size();
        limit = charLen - combinationLength;
        hasnext = true;
    }
    
    string next() {
        string result;
        int charIndex = -1;
        for(int i=0;i<index.size();++i){
            charIndex += 1 + index[i];
            result.push_back(chars[charIndex]);
        }
        // for (int i =0; i<index.size();++i)
        //     cout << index[i] << " ";
        // cout << endl;
        
        do {
            this->incr();
        } while (this -> indexSum() > limit);
        return result;
    }
    
    bool hasNext() {
        return hasnext;
    }
    
private:
    int charLen;
    int combLen;
    int limit;
    vector<int> index;
    bool hasnext;
    string chars;
    
    int incr() {
        bool fail = false;
        index[index.size()-1]++;
        int i;
        for (int i = index.size() - 1;i>=0 && index[i]>=charLen ;i--){
            index[i] = 0;
            if(i>0)
                index[i-1] += 1;
            else
                fail = true;
        }
        if (fail){
            hasnext = false;
            return 0;
        }
        return 1;
    }
    
    int indexSum(){
        int sum=0;
        for (int i=0;i<index.size();++i){
            sum+=index[i];
        }
        return sum;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(){
  CombinationIterator t("abc",2);
  cout << t.next() << endl;
  cout << t.hasNext() << endl;
  cout << t.next() << endl;
  cout << t.hasNext() << endl;
  cout << t.next() << endl;
  cout << t.hasNext() << endl;
}