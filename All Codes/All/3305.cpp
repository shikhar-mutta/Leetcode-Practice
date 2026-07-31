// Link: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: countSubstring(word, k) counts substrings with consonants <= k
// once all 5 vowels are present in the window (sliding window shrinks only
// when both conditions hold, so windows still missing a vowel just keep
// growing and are implicitly excluded once left catches up past them). The
// exact-k answer is then countSubstring(k) - countSubstring(k-1).
class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
    int countSubstring(string word, int k) {
        int left = 0;
        int right = 0, consonants = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        while (right < word.length()) {
            if (isVowel(word[right])) {
                mp[word[right]]++;
            } else {
                consonants++;
            }
            while (mp.size() >= 5 && consonants > k) {
                if (isVowel(word[left])) {
                    mp[word[left]]--;
                    if (mp[word[left]] == 0) {
                        mp.erase(word[left]);
                    }
                } else {
                    consonants--;
                }
                left++;
            }
            cnt += right - left + 1;

            right++;
        }
        return cnt;
    }
    int countOfSubstrings(string word, int k) {
        return countSubstring(word, k) - countSubstring(word, k - 1);
    }
};
