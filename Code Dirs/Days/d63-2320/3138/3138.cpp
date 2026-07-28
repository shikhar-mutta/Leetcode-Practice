// Link: https://leetcode.com/problems/minimum-length-of-anagram-concatenation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26) over all valid divisors k, SC: O(26)
// Approach: Try every divisor k of n as the candidate block length. A valid
// k requires each letter's total count divisible by n/k (occur), giving a
// per-block target frequency; then verify every consecutive block of size k
// has exactly that frequency distribution. Return the smallest such k.
class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i : s) {
            freq[i - 97]++;
        }
        if (freq[s[0] - 97] == n)
            return 1;

        for (int k = 2; k <= n / 2; k++) {
            if (n % k != 0)
                continue;
            vector<int> target(26, 0), curr(26, 0);
            bool is_ans = true;
            int occur = n / k;
            for (int i = 0; i < 26; i++) {
                if (freq[i] % occur != 0) {
                    is_ans = false;
                    break;
                }
                target[i] = freq[i] / occur;
            }
            if (is_ans) {
                for (int i = 0; i < n; i++) {
                    curr[s[i] - 97]++;
                    if ((i + 1) % k == 0) {
                        if (curr != target) {
                            is_ans = false;
                            break;
                        }
                        for (int i = 0; i < 26; i++)
                            curr[i] = 0;
                    }
                }
                if (is_ans)
                    return k;
            }
        }
        return n;
    }
};
