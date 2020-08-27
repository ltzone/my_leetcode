#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class DFSSolution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};



typedef struct Work {
    int idx;
    vector<int> current;
    int remain;
    
    Work(int target):idx(0),current(),remain(target){};
    Work(const Work & original, int subidx, int sub):idx(subidx),current(original.current),remain(original.remain-sub){
        current.push_back(sub);
    };
    
} work;


class BFSSolution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int len = candidates.size();
        
        sort(candidates.begin(),candidates.end());
        queue<work> workList;
        Work init(target);
        workList.push(init);
        while (!workList.empty()){
            work & curWork  = workList.front();
            for (int i=curWork.idx; i<len&&candidates[i]<=curWork.remain; ++i){
                work newWork(curWork,i,candidates[i]);
                if (newWork.remain == 0)
                    result.push_back(newWork.current);
                else
                    workList.push(newWork);
            }
            workList.pop();
        }
        
        return result;
    }
};