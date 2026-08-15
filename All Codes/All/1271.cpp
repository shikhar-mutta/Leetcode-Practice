// Link: https://leetcode.com/problems/hexspeak/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toHexspeak(string num) {
        long long n = stoll(num);
        stringstream ss;
        ss << hex << uppercase << n;
        string hexStr = ss.str();
        string res;
        for (char c : hexStr) {
            if (c == '0') res += 'O';
            else if (c == '1') res += 'I';
            else if (c >= 'A' && c <= 'F') res += c;
            else return "ERROR";
        }
        return res;
    }
};
