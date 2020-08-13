#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2,nums1);
        }
        int iMin = 0, iMax = m, halfLen = (m + n)/2;
        while (iMin <= iMax) {
            int i = (iMin+iMax+1)/2;
            int j = halfLen - i;
            if (i < m && j > 0 && nums2[j-1] > nums1[i]) {
                iMin = i + 1;
            } else if ( i > 0 && j < n && nums1[i-1] > nums2[j]) {
                iMax = i - 1;
            } else {
                int minRight = 0;
                if (i == m) minRight = nums2[j];
                else if (j == n) minRight = nums1[i];
                else minRight = fmin(nums2[j],nums1[i]);
                if ((m+n)%2==1){
                    return minRight;
                }
                int maxLeft = 0;
                if (i == 0) maxLeft = nums2[j-1];
                else if (j == 0) maxLeft = nums1[i-1];
                else maxLeft = fmax(nums2[j-1],nums1[i-1]);
                return (maxLeft + minRight)/2.0;

            }
        }
        return 0;
    }
};


class FailedSolution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = m/2 , j = (m + n)/2 - i;

        while (true) {
            bool t1 =  cmp(nums2,nums1,j,i-1), t2 =cmp(nums1,nums2,i,j-1);
            if (cmp(nums2,nums1,j,i-1)) {
                // i = i/2; j = (m + n)/2 - i;
                int new_j = (n+j)/2;
                int new_i = (m+n)/2 - new_j;
                if (new_j != j && new_i >= 0) {
                    j = new_j; i = new_i;
                } else {
                    j++;i--;
                }
            } else if (cmp(nums1,nums2,i,j-1)) {
                int new_i = (m+i)/2;
                int new_j = (m+n)/2 - new_i;
                if (new_i != i && new_j >= 0) {
                    i = new_i; j = new_j;
                } else {
                    i++;j--;
                }
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
        if (i >= nums1.size() || j < 0){
            return false;
        } else if (i < 0 || j >= nums2.size()){
            return true;
        } else
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

void test1(){
    int foo1[] = {1,2};
    vector<int> test1(foo1, foo1+ sizeof(foo1) / sizeof(int));
    int foo2[] = {3,4};
    vector<int> test2(foo2, foo2+ sizeof(foo2) / sizeof(int));
    Solution s;
    cout << "2.5=" << s.findMedianSortedArrays(test1,test2) << endl;
}

void test2(){
    int foo1[] = {1,2,3,4,6,7,8};
    vector<int> test1(foo1, foo1+ sizeof(foo1) / sizeof(int));
    int foo2[] = {5};
    vector<int> test2(foo2, foo2+ sizeof(foo2) / sizeof(int));
    Solution s;
    cout << "4.5=" << s.findMedianSortedArrays(test1,test2) << endl;
}

void test3(){
    int foo1[] = {3,4};
    vector<int> test1(foo1, foo1+ sizeof(foo1) / sizeof(int));
    int foo2[] = {1,2,5};
    vector<int> test2(foo2, foo2+ sizeof(foo2) / sizeof(int));
    Solution s;
    cout << "3=" << s.findMedianSortedArrays(test1,test2) << endl;
}

void test4(){
    int foo1[] = {2,3,4,5,6,7};
    vector<int> test1(foo1, foo1+ sizeof(foo1) / sizeof(int));
    int foo2[] = {1};
    vector<int> test2(foo2, foo2+ sizeof(foo2) / sizeof(int));
    Solution s;
    cout << "4=" << s.findMedianSortedArrays(test1,test2) << endl;
}

void test5(){
    int foo1[] = {4};
    int foo2[] = {1,2,3,5,6,9};
    vector<int> test1(foo1, foo1+ sizeof(foo1) / sizeof(int));
    vector<int> test2(foo2, foo2+ sizeof(foo2) / sizeof(int));
    Solution s;
    cout << "1=" << s.findMedianSortedArrays(test1,test2) << endl;
}


int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
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