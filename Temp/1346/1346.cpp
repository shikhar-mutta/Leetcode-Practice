// Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int x : arr) {
            if (seen.count(x * 2) || (x % 2 == 0 && seen.count(x / 2))) return true;
            seen.insert(x);
        }
        return false;
    }
};
