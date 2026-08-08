// Link: https://leetcode.com/problems/relative-sort-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> rank;
        for (int i = 0; i < (int)arr2.size(); i++) rank[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            bool inA = rank.count(a), inB = rank.count(b);
            if (inA && inB) return rank[a] < rank[b];
            if (inA) return true;
            if (inB) return false;
            return a < b;
        });
        return arr1;
    }
};
