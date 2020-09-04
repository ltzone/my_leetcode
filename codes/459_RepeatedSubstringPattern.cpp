#include<string>
#include<map>
#include<vector>
using namespace std;


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0)
            return false;
        vector<int> period;
        char fst = s[0];
        for (int i=0;i<s.size();++i)
        {
            if (s[i] == fst)
                period.push_back(i);
        }
        
        for (int i=0;i<period.size();++i)
        {
            if (testPattern(s,i))
                return true;
        }

        return false;
    }

    bool testPattern (const string & s, int period){
        if (s.size()%period != 0)
            return false;
        for (int i=0;i<period;++i){
            char expect = s[i];
            int j = i+period;
            while (j<s.size())
            {
                if (s[j]!=expect)
                    return false;
                j += period;
            }
        }
        return true;
    }
};