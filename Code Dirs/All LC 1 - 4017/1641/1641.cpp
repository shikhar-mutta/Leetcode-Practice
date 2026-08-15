// Link: https://leetcode.com/problems/count-sorted-vowel-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        long long res = 1;
        for (int i = 1; i <= 4; i++) {
            res = res * (n + i) / i;
        }
        return (int)res;
    }
};
