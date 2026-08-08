// Link: https://leetcode.com/problems/bitwise-ors-of-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result, cur, next;
        for (int x : arr) {
            next.clear();
            next.insert(x);
            for (int v : cur) next.insert(v | x);
            cur = next;
            for (int v : cur) result.insert(v);
        }
        return result.size();
    }
};
