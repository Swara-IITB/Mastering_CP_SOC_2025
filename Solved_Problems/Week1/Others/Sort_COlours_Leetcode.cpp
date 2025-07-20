#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,m=0,e=nums.size()-1;
        while(m<=e){
            if(nums[m]==0){
                swap(nums[m++],nums[s++]);
            } else if(nums[m]==1){
                m++;
            } else{
                swap(nums[m],nums[e--]);
            }
        }
    }
};