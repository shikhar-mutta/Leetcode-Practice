// Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<long long> prefixes;
        for (int x : arr1) {
            long long v = x;
            while (v > 0) {
                prefixes.insert(v);
                v /= 10;
            }
        }
        int ans = 0;
        for (int x : arr2) {
            long long v = x;
            while (v > 0) {
                if (prefixes.count(v)) {
                    ans = max(ans, (int)to_string(v).size());
                    break;
                }
                v /= 10;
            }
        }
        return ans;
    }
};
