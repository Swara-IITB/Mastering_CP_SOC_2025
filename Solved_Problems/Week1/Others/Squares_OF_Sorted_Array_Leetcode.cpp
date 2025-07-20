#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int st = 0, end = n-1, pos = n-1;
        while(pos>=0){
            if(abs(nums[st])>=abs(nums[end])){
                ans[pos--] = nums[st]*nums[st];
                st++;
            } else {
                ans[pos--] = nums[end]*nums[end];
                end--;
            }
        }
        return ans;
    }
};