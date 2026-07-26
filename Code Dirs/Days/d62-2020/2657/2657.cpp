// Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1) (fixed-size counters, values bounded by 1..n<=50)
// Approach: maintain a per-value seen-count across both prefixes so far. When
// A[i] or B[i] pushes a value's count to exactly 2, that value is now common
// to both prefixes, so bump the running common-count once per such event.
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        std::array<int, 51> counters{};
        int currentCount = 0;

        vector<int> ans(A.size());
        for(int i = 0; i < A.size(); i++) {
                counters[A[i]]++;
                if (counters[A[i]] == 2) {
                    currentCount++;
                }

                counters[B[i]]++;
                if (counters[B[i]] == 2) {
                    currentCount++;
                }

            ans[i] = currentCount;
        }

        return ans;
    }
};
