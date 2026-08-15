// Link: https://leetcode.com/problems/maximum-binary-string-after-change/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int zeros = count(binary.begin(), binary.end(), '0');
        if (zeros <= 1) return binary;
        int first0 = binary.find('0');
        string res(n, '1');
        res[first0 + zeros - 1] = '0';
        return res;
    }
};
