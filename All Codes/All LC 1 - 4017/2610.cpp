// Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) worst case (maxFreq rows, each scanning up to sz values)
// SC: O(n) for the frequency table + output
// Approach: any-valid-answer special judge — only requirement is no row has
// duplicates and the row count is minimal (== max frequency of any value).
// Repeatedly sweep 1..sz collecting one occurrence of every value that still
// has remaining count into the next row, decrementing as consumed, until no
// value remains; this always uses exactly maxFreq rows.
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int sz = nums.size();
        vector<int> freq(sz+1, 0);

        for (auto x : nums) {
            ++freq[x];
        }

        while (true) {
            vector<int> vec;
            for (int i = 1; i <= sz; ++i) {
                if (freq[i]) {
                    vec.push_back(i);
                    --freq[i];
                }
            }
            if (vec.empty()) {
                break;
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
