// Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> cnt;
        for (auto& s : arr) cnt[s]++;
        for (auto& s : arr) {
            if (cnt[s] == 1) {
                if (--k == 0) return s;
            }
        }
        return "";
    }
};
