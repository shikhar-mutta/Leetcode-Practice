// Link: https://leetcode.com/problems/merge-adjacent-equal-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: stack-based cascading merge — push each value, and while the
// top two stack elements are equal, pop both and push their double
// (repeating since a new merge can cascade further).
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> st;
        for (int x : nums) {
            st.push_back(x);
            while (st.size() >= 2 && st[st.size()-1] == st[st.size()-2]) {
                long long merged = st.back() * 2;
                st.pop_back();
                st.pop_back();
                st.push_back(merged);
            }
        }
        return st;
    }
};
