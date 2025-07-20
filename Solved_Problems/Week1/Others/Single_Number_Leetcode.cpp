#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> a;
        for(int i =0; i< nums.size(); i++){
            a[nums[i]]++;
        }
        for(auto x : a){
            if(x.second == 1){
                return x.first;
            }
        }
        return -1;
    }
};