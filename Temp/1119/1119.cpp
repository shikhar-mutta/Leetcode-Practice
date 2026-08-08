// Link: https://leetcode.com/problems/remove-vowels-from-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeVowels(string s) {
        string res;
        for (char c : s) {
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') continue;
            res += c;
        }
        return res;
    }
};
