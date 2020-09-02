using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int largestTime = -1;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                if (j!= i) {
                    for (int k=0;k<4;k++){
                        if (k!=i && k!= j){
                            int l = 6-i-j-k;
                            int result = largestTimeHelper(A[i],A[j],A[k],A[l]);
                            largestTime = max(result, largestTime);
                        }
                    }
                }
            }
        }

        if (largestTime == -1){
            return "";
        }
        int h = largestTime/60;
        int m = largestTime%60;
        string ans;
        if (h<10)
            ans.push_back('0');
        ans.append(to_string(h));
        ans.push_back(':');
        if (m<10)
            ans.push_back('0');
        ans.append(to_string(m));
        return ans;
    }

    int largestTimeHelper(int a, int b, int c, int d){
        int hours = a * 10 + b;
        int min = c * 10 + d;

        if (hours<24 && min< 60){
            return hours * 60 + min;
        }

        return -1;
    }
};