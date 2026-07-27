// Link: https://leetcode.com/problems/mirror-frequency-distance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: count frequency of each of the 36 possible characters
// (letters + digits), compute each present character's mirror, and sum
// |freq(c)-freq(mirror(c))| once per unmarked pair.
class Solution {
    char mirror(char c) {
        if (isdigit(c)) return '0' + ('9' - c);
        return 'a' + ('z' - c);
    }
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        int ans = 0;
        unordered_set<char> visited;
        for (auto& [c, f] : freq) {
            if (visited.count(c)) continue;
            char m = mirror(c);
            visited.insert(c);
            visited.insert(m);
            int fm = freq.count(m) ? freq[m] : 0;
            ans += abs(f - fm);
        }
        return ans;
    }
};
