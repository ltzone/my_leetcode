#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cntMap('z'-'A'+1,0);
        for(int i=0;i<s.size();++i){
            cntMap[s[i]-'A']++;
        }
        int result = 0;
        bool hasOdd = false;
        for(int i=0;i<cntMap.size();++i){
            if (cntMap[i]%2==0){
                result += cntMap[i];
            } else {
                result += cntMap[i]-1;
                hasOdd = true;
            }
        }
        return (result+hasOdd);
    }
};

int main(){
  Solution s;
  string a = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
  cout << s.longestPalindrome(a) << endl;
  cout << a.length() << endl;
  return 0;

}