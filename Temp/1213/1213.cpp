// Link: https://leetcode.com/problems/intersection-of-three-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        unordered_map<int,int> cnt;
        for (int x : arr1) cnt[x]++;
        for (int x : arr2) cnt[x]++;
        for (int x : arr3) cnt[x]++;
        vector<int> res;
        for (int x : arr1) if (cnt[x] == 3) res.push_back(x);
        return res;
    }
};
