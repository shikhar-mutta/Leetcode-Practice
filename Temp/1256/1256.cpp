// Link: https://leetcode.com/problems/encode-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(int num) {
        num++;
        string bin;
        while (num) {
            bin += char('0' + (num & 1));
            num >>= 1;
        }
        reverse(bin.begin(), bin.end());
        return bin.substr(1);
    }
};
