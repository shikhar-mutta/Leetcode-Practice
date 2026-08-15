// Link: https://leetcode.com/problems/repeated-dna-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: sliding window of 10-char substrings, hash map counting occurrences, collect those seen exactly twice
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> count;
        vector<string> res;
        for (int i = 0; i + 10 <= (int)s.size(); i++) {
            string sub = s.substr(i, 10);
            if (++count[sub] == 2) res.push_back(sub);
        }
        return res;
    }
};
