// Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) in the worst case because substr/comparison can cost O(n)
// SC: O(n) for the answer/current substring
// Approach: use a sliding window to keep exactly k ones. When a window has
// exactly k ones, trim leading zeroes to make it shortest, then update the
// answer by smaller length or lexicographically smaller value on a tie.
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (k <= 0) return "";

        string ans;
        int ones = 0;
        int left = 0;

        for (int right = 0; right < (int)s.size(); ++right) {
            ones += s[right] == '1';

            while (ones > k) {
                ones -= s[left] == '1';
                ++left;
            }

            while (ones == k && s[left] == '0') {
                ++left;
            }

            if (ones == k) {
                string curr = s.substr(left, right - left + 1);
                if (ans.empty() || curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};
