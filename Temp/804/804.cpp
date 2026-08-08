// Link: https://leetcode.com/problems/unique-morse-code-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*L) SC: O(n*L)
// Approach: translate each word to its morse code concatenation, count distinct results via a set.
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> codes;
        for (auto& w : words) {
            string code;
            for (char c : w) code += morse[c-'a'];
            codes.insert(code);
        }
        return codes.size();
    }
};
