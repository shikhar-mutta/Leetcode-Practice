// Link: https://leetcode.com/problems/fair-distribution-of-cookies/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k^n) worst case (n = cookies.size()), heavily pruned in practice by
// the running-best bound and the symmetric-empty-child skip
// Approach: backtracking - assign each cookie bag in turn to one of the k
// children, tracking each child's running total. Prune a branch as soon as
// some child's total reaches or exceeds the best complete assignment found
// so far (it can't possibly improve). Also skip trying additional empty
// children beyond the first empty one at each step, since assigning to any
// of several currently-empty children is symmetric.
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> children(k, 0);
        int best = INT_MAX;
        backtrack(cookies, 0, children, k, best);
        return best;
    }

private:
    void backtrack(vector<int>& cookies, int i, vector<int>& children, int k,
                   int& best) {
        if (i == cookies.size()) {
            best = min(best, *max_element(children.begin(), children.end()));
            return;
        }
        for (int c = 0; c < k; ++c) {
            children[c] += cookies[i];
            if (children[c] < best) // prune: no point if already worse
                backtrack(cookies, i + 1, children, k, best);
            children[c] -= cookies[i];

            if (children[c] == 0)
                break; // skip symmetric empty children
        }
    }
};
