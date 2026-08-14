// Link: https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int count = 0;
        for (int i = 0; i + k <= (int)s.size(); i++) {
            int val = stoi(s.substr(i, k));
            if (val != 0 && num % val == 0) count++;
        }
        return count;
    }
};
