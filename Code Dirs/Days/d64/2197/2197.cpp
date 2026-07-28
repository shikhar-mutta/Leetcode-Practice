// Link: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log(maxProduct))  SC: O(n)
// Approach: process nums with a stack; push each num, then while top two
// have gcd>1, merge them into lcm and repeat (since merging can cascade
// further left). Final stack is the answer.
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;
        for (int num : nums) {
            long long cur = num;
            while (!st.empty()) {
                long long g = gcd(st.back(), cur);
                if (g == 1) break;
                cur = st.back() / g * cur;
                st.pop_back();
            }
            st.push_back(cur);
        }
        return vector<int>(st.begin(), st.end());
    }
};
