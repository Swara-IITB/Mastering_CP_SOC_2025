#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int m=0,ans=0;
        if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u'){
            m++; 
            ans++;
        }
        for(int i =1; i< s.size(); i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                m++;
            } else m =0;
            ans = max(ans , m);
        }
        return min(ans,k);

    }
};