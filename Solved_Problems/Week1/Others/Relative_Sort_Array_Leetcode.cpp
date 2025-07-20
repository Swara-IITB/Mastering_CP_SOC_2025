#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> a;
        for(int i =0; i < arr1.size(); i++){
            a[arr1[i]]++;
        }
        arr1.clear();
        for(int i=0; i < arr2.size(); i++){
            for(int j =0; j<a[arr2[i]];j++){
                arr1.push_back(arr2[i]);
            }
        }
        for(auto x : a){
            if(count(arr2.begin(),arr2.end(),x.first)==0){
                for(int j =0; j<x.second;j++){
                    arr1.push_back(x.first);
                }
            }
        }
        return arr1;
    }
};