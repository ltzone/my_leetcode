#include <string>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        string res;
        int wordCnt = 1;
        bool shiftCon = false; 
        char fstCon = '\0';
        bool isFst = true;
        int i;
        for (i=0;i<S.size();++i){
            if (isFst){
                switch (S[i]){
                    case 'a': case 'e': case 'i': case 'o': case 'u':
                    case 'A': case 'E': case 'I': case 'O': case 'U':
                        shiftCon = false;
                        res.push_back(S[i]);
                        break;
                    default:
                        shiftCon = true;
                        fstCon = S[i];
                }
                isFst = false;
            } else if (S[i] == ' ') {
                if (shiftCon)
                    res.push_back(fstCon);
                res.append("ma");
                string atmp(wordCnt,'a');
                res.append(atmp);
                res.push_back(' ');
                wordCnt++;
                isFst = true;
            } else {
                res.push_back(S[i]);
            }
        }
        
        if (S[i-1] != ' '){
            if (shiftCon)
                res.push_back(fstCon);
            res.append("ma");
            string atmp(wordCnt,'a');
            res.append(atmp);
            wordCnt++;
        }
        
        return res;
    }
};