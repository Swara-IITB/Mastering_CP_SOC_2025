#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto x : nums){
            if(q.size()<k) q.push(x);
            else if(q.top()<x){
                q.pop();
                q.push(x);
            }
        }
        return q.top();
    }
};