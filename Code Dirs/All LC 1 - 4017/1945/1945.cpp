// Link: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string num;
        for (char c : s) num += to_string(c - 'a' + 1);

        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (char c : num) sum += c - '0';
            num = to_string(sum);
        }
        return stoi(num);
    }
};
