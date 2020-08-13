class Solution {
public:
    bool isHappy(int n) {
        int arr[99] = {0};
        int length = 0;
        while (n != 1) {
            n = iterator(n);
            for(int i=0;i<length;++i){
                if (arr[i] == n) {
                    return false;
                }
            }
            arr[length++] = n; 
        }
        return true;
    }
    
private:
    int iterator(int n){
        int sum = 0;
        while (n != 0) {
            sum += (n%10) * (n%10);
            n /= 10;            
        }
        return sum;
    }
};