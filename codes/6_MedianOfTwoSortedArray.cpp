#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = m/2 , j = (m + n)/2 - i;
        
        while (true) {
            if (cmp(nums2,nums1,j,i-1)) {
                i = i/2; j = (m + n)/2 - i;
            } else if (cmp(nums1,nums2,i,j-1)) {
                i = (m+i)/2; j = (m + n)/2 - i;
            } else {
                break;
            }
        }
        
        if ((m+n)%2==0){
            return (max(nums1,nums2,i-1,j-1) + min(nums1,nums2,i,j))/2.0;
        } else {
            return min(nums1,nums2,i,j);
        }
    }
    
private:
    bool cmp(const vector<int>& nums1, const vector<int>& nums2, int i, int j){
        if (i < 0 || j >= nums2.size())
            return true;
        if (i >= nums1.size() || j < 0)
            return false;
        return (nums1[i] < nums2[j]);
    }
    
    int max(const vector<int>& nums1, const vector<int>& nums2, int i, int j){
        if (i<0) return nums2[j];
        if (j<0) return nums1[i];
        return (nums1[i]<nums2[j]? nums2[j] : nums1[i]);
    }
    
    int min(const vector<int>& nums1, const vector<int>& nums2, int i, int j){
        if (i>=nums1.size()) return nums2[j];
        if (j>=nums2.size()) return nums1[i];
        return (nums1[i]<nums2[j]? nums1[i] : nums2[j]);
    }

};

int main(){
    int foo1[] = {1,2,3,9};
    vector<int> test1(foo1, foo1+ sizeof(foo1) / sizeof(int));
    int foo2[] = {3,7,8};
    vector<int> test2(foo2, foo2+ sizeof(foo2) / sizeof(int));
    Solution s;
    cout << s.findMedianSortedArrays(test1,test2);
}


class LinerSolution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted(nums1.size()+nums2.size(),0);
        vector<int>::iterator ptr1 = nums1.begin(), ptr2= nums2.begin();
        vector<int>::iterator ptrres = sorted.begin();
        while (ptr1 != nums1.cend() && ptr2 != nums2.cend()){
            if (*ptr1 < *ptr2) {
                *ptrres = *ptr1;
                ptrres++;ptr1++;
            } else {
                *ptrres = *ptr2;
                ptrres++;ptr2++;
            }
        }
        while (ptr1 != nums1.cend()){
            *ptrres = *ptr1;
            ptrres++;ptr1++;
        }
        while (ptr2 != nums2.cend()){
            *ptrres = *ptr2;
            ptrres++;ptr2++;
        }
        int mid = sorted.size()/2;
        if (sorted.size()%2 == 0){
            return (sorted[mid] + sorted[mid-1])/2.0;
        } else {
            return sorted[mid];
        }
    }
};