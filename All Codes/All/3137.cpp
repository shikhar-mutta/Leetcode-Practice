// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n/k)
// Approach: Split word into n/k blocks of length k and count frequency of
// each distinct block. The best strategy is to overwrite every block with
// copies of the most frequent one, so the answer is total blocks minus the
// max frequency.
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        const int n = word.length(), total = n / k;
        unordered_map<string_view,int> freq;
        freq.reserve(total);
        int maxFreq = 0;
        for (int i = 0; i < n; i += k) {
            string_view sv(word.data() + i, k);
            maxFreq = max(maxFreq, ++freq[sv]);
        }
        return total - maxFreq;
    }
};
