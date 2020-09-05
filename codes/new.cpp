#include<vector>
#include<string>
#include<map>
#include<iostream>

using namespace std;

class window {
public:    
    int fst;
    int last;
    window():fst(-1),last(-1){};
    window(int f,int l):fst(f),last(l){};
};

bool cmp(window w1, window w2){
    return (w1.fst < w2.fst);
}

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<window> rec(26);
        for (int i=0;i<S.size();++i){
            int idx = S[i] - 'a';
            if (rec[idx].fst == -1){
                rec[idx].fst=i;
            }
            rec[idx].last=i;
        }
        sort(rec.begin(),rec.end(),cmp);
        // for (int i=0;i<26;++i){
        //     cout << fst[i] << " ";
        // }
        // cout << endl;
        // for (int i=0;i<26;++i){
        //     cout << last[i] << " ";
        // }
        // cout << endl;
        
        map<int,int> intervals;
        for (char c='a';c<='z';++c){
            if (rec[c-'a'].fst==-1)
                continue;
            auto left = intervals.lower_bound(rec[c-'a'].fst);
            auto right = intervals.upper_bound(rec[c-'a'].last);
            if (left != right)
                intervals.erase(left,right);
            if (right == intervals.end()){
                intervals.insert(pair<int,int>(rec[c-'a'].last,0));
            }
            
            // for (auto i=intervals.begin();i!=intervals.end();++i){
            //     cout << i->first << " ";
            // }
            // cout << endl;
        }
        vector<int> result;
        int cnt=-1;
        for (auto i=intervals.begin();i!=intervals.end();++i){
            cout << i->first << " ";
            result.push_back(i->first-cnt);
            cnt = i->first;
        }
        return result;
    }
};

int main(){
    Solution s;
    s.partitionLabels("ababcbacadefegdehijhklij");

}