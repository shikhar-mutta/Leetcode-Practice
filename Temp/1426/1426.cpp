// Link: https://leetcode.com/problems/counting-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> vals(arr.begin(), arr.end());
        int count = 0;
        for (int x : arr) {
            if (vals.count(x + 1)) count++;
        }
        return count;
    }
};
