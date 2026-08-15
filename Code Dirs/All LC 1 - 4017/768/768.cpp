// Link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: maintain a stack of "max so far" values for chunks; for each new element, if it's >= stack top, push it as a new chunk's max; otherwise it must merge with previous chunks until the top is <= it, keeping the max as the new top.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> stk;
        for (int x : arr) {
            if (!stk.empty() && x < stk.back()) {
                int mx = stk.back();
                stk.pop_back();
                while (!stk.empty() && x < stk.back()) stk.pop_back();
                stk.push_back(mx);
            } else {
                stk.push_back(x);
            }
        }
        return stk.size();
    }
};
