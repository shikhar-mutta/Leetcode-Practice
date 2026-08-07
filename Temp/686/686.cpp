// Link: https://leetcode.com/problems/repeated-string-match/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((|a|+|b|) * ceil(|b|/|a|)) SC: O(n)
// Approach: repeat 'a' until its length >= |b|, check substring match; if not found, try one more repeat (covers wraparound cases).
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string s = a;
        while (s.size() < b.size()) { s += a; count++; }
        if (s.find(b) != string::npos) return count;
        s += a; count++;
        if (s.find(b) != string::npos) return count;
        return -1;
    }
};
