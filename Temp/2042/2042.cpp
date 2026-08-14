// Link: https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string word;
        long long last = -1;
        while (ss >> word) {
            if (isdigit(word[0])) {
                long long val = stoll(word);
                if (val <= last) return false;
                last = val;
            }
        }
        return true;
    }
};
