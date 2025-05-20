#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k = 1, best = 1;
    string s;
    cin >> s;
    for(int i = 1; i< s.size(); i++){
        if(s[i] == s[i-1]) k++;
        else k = 1;
        best = max(k, best);

    }
    cout << best;
}