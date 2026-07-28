// Link: https://leetcode.com/problems/find-array-given-subset-sums/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * 2^n)  SC: O(2^n)
// Approach: repeatedly peel off one array element. The gap between the two
// smallest sums equals some |element|. Greedily pair each sum x with x+diff
// to split the multiset into "subsets excluding this element" (group0) vs
// "including it". If group0 contains 0, the element is +diff and group0 is
// the next round's sums; otherwise the element is -diff and group0 (shifted
// by +diff) becomes the next round's sums.
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        vector<int> ans;
        for (int round = 0; round < n; round++) {
            int diff = sums[1] - sums[0];
            multiset<int> remaining(sums.begin(), sums.end());
            vector<int> group0;
            for (int x : sums) {
                auto it = remaining.find(x);
                if (it == remaining.end()) continue;
                remaining.erase(it);
                group0.push_back(x);
                auto it2 = remaining.find(x + diff);
                if (it2 != remaining.end()) remaining.erase(it2);
            }
            bool hasZero = find(group0.begin(), group0.end(), 0) != group0.end();
            if (hasZero) {
                ans.push_back(diff);
                sums = group0;
            } else {
                ans.push_back(-diff);
                for (int& x : group0) x += diff;
                sums = group0;
            }
        }
        return ans;
    }
};
