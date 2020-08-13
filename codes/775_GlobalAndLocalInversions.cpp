#include<iostream>
#include<vector>
using namespace std;

// idea: merge-sort
// an easier solution: 
// for i in A.size(): if (abs(A[i] - i) > 1) return false;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int loc = countLocalInversion(A);
        int glb = globalSortAndInversion(A,0,A.size()-1);
        cout << loc << endl;
        cout << glb << endl;
        for (int i=0;i<A.size();++i)
            cout << A[i] << ' ';
        return loc == glb;
    }
    
    int countLocalInversion(vector<int>& A){
        int cnt=0;
        for (int i=0;i<A.size()-1;++i){
            if (A[i]>A[i+1])
                cnt+=1;
        }
        return cnt;
    }
    
    
    int globalSortAndInversion(vector<int>& A, int beginPos, int endPos){
        
        if (endPos - beginPos <= 0)
            return 0;
        
        int midPos = (beginPos + endPos)/2;
        int leftGlobalInversion = globalSortAndInversion(A,beginPos,midPos);
        int rightGlobalInversion = globalSortAndInversion(A,midPos+1,endPos);
        
        int mergeGlobalInversion = 0;
        vector<int> mergeResult = vector<int> (endPos - beginPos + 1);
        int leftPtr = beginPos;
        int rightPtr = midPos+1;
        int mergePtr = 0;
        while (leftPtr <= midPos && rightPtr <= endPos){
            if (A[leftPtr] <= A[rightPtr]){
                mergeResult[mergePtr++] = A[leftPtr++];
            }
            else {
                mergeResult[mergePtr++] = A[rightPtr++];
                mergeGlobalInversion += midPos - leftPtr + 1;
            }
        }
        while (leftPtr <= midPos){
            mergeResult[mergePtr++] = A[leftPtr++];
        }
        while (rightPtr <= endPos) {
                mergeResult[mergePtr++] = A[rightPtr++];
                // mergeGlobalInversion += midPos - leftPtr + 1;
        }
        for (int i=0;i<mergeResult.size();++i){
            A[beginPos+i] = mergeResult[i];
        }
    
        
        return leftGlobalInversion + rightGlobalInversion + mergeGlobalInversion;
        
    }
    
};