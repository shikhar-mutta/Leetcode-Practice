// Link: https://leetcode.com/problems/maximum-repeating-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string rep = word;
        while (sequence.find(rep) != string::npos) {
            k++;
            rep += word;
        }
        return k;
    }
};
