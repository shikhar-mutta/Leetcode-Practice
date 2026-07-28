// Link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: monotonic stack of running-max values. For each element,
// pop all stack values greater than it (they now belong to the same
// chunk as this element, since it must merge with them to be sortable),
// then push back the max of the popped values (or the element itself).
// The final stack size is the number of chunks.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> stk;
        for (int x : arr) {
            if (stk.empty() || x >= stk.back()) {
                stk.push_back(x);
            } else {
                int mx = stk.back();
                stk.pop_back();
                while (!stk.empty() && stk.back() > x) stk.pop_back();
                stk.push_back(mx);
            }
        }
        return stk.size();
    }
};
