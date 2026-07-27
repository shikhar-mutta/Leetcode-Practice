// Link: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Maintain a window [left, right] with exactly k consonants,
// shrinking from the left whenever consonants exceed k. Once the window has
// all 5 vowels and exactly k consonants, count how many further left
// positions (extraLeft) can be advanced while still leaving at least one
// copy of that vowel behind — each such position plus the current left
// itself gives a distinct valid substring ending at right.
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int hash[2][128] = {};
        hash[0]['a'] = hash[0]['e'] = hash[0]['i'] = hash[0]['o'] =
            hash[0]['u'] = 1;

        long long ans = 0;
        int currentK = 0, vowels = 0, extraLeft = 0, left = 0;

        for (int right = 0; right < word.length(); right++) {
            char rightChar = word[right];

            if (hash[0][rightChar]) {
                if (++hash[1][rightChar] == 1)
                    vowels++;
            } else {
                currentK++;
            }

            while (currentK > k) {
                char leftChar = word[left++];
                if (hash[0][leftChar]) {
                    if (--hash[1][leftChar] == 0)
                        vowels--;
                } else {
                    currentK--;
                }
                extraLeft = 0;
            }

            while (vowels == 5 && currentK == k && left < right &&
                   hash[0][word[left]] && hash[1][word[left]] > 1) {
                extraLeft++;
                hash[1][word[left++]]--;
            }

            if (currentK == k && vowels == 5) {
                ans += (1 + extraLeft);
            }
        }

        return ans;
    }
};
