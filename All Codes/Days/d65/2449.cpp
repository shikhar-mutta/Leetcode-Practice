// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: parity is invariant under +2/-2 ops, so separate odds/evens, sort each group in
// both arrays, pair them up positionally; sum of positive (nums-target) differences / 2 = answer.
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> no, ne, to, te;
        for (int x : nums) (x % 2 ? no : ne).push_back(x);
        for (int x : target) (x % 2 ? to : te).push_back(x);
        sort(no.begin(), no.end()); sort(ne.begin(), ne.end());
        sort(to.begin(), to.end()); sort(te.begin(), te.end());

        long long ops = 0;
        for (size_t i = 0; i < no.size(); i++) if (no[i] > to[i]) ops += no[i] - to[i];
        for (size_t i = 0; i < ne.size(); i++) if (ne[i] > te[i]) ops += ne[i] - te[i];
        return ops / 2;
    }
};
