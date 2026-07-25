// Link: https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), n = text.length()
// SC: O(1)
// Approach: inserting exactly one character optimally means either
// prepending pattern[0] or appending pattern[1] (inserting anywhere else
// is never better). Count subsequences "pattern[0]...pattern[1]" already in
// text as we scan left to right (running count0 tracks pattern[0]'s seen so
// far; whenever pattern[1] is seen, add count0 to the total), then the
// extra subsequences unlocked by one insertion equal the total count of
// whichever pattern char is more frequent (append pattern[1] to close out
// every existing pattern[0], or prepend pattern[0] to open one before every
// existing pattern[1]).
class Solution {
public:
    long long maximumSubsequenceCount(std::string text, std::string pattern) {
        long long totalSubsequences = 0;
        long long count0 = 0; // Occurrences of pattern[0]
        long long count1 = 0; // Occurrences of pattern[1]

        for (char c : text) {
            if (c == pattern[1]) {
                totalSubsequences += count0;
                count1++;
            }
            if (c == pattern[0]) {
                count0++;
            }
        }
        return totalSubsequences + std::max(count0, count1);
    }
};
