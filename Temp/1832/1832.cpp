// Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> seen(sentence.begin(), sentence.end());
        return seen.size() == 26;
    }
};
