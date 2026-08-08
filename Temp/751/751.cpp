// Link: https://leetcode.com/problems/ip-to-cidr/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(log n)
// Approach: convert IP to a 32-bit integer; repeatedly take the largest block size that both (a) is aligned to the current start address (lowest set bit of start, or 32 if start is 0) and (b) doesn't exceed the remaining count; emit that CIDR block, advance start, decrement remaining.
class Solution {
    unsigned int ipToInt(const string& ip) {
        unsigned int res = 0;
        stringstream ss(ip);
        string part;
        while (getline(ss, part, '.')) res = (res << 8) | stoi(part);
        return res;
    }
    string intToIp(unsigned int val) {
        return to_string((val >> 24) & 255) + "." + to_string((val >> 16) & 255) + "." +
               to_string((val >> 8) & 255) + "." + to_string(val & 255);
    }
public:
    vector<string> ipToCIDR(string ip, int n) {
        unsigned long long start = ipToInt(ip);
        vector<string> res;
        while (n > 0) {
            unsigned long long alignBlock = (start == 0) ? (1ULL << 32) : (start & (~start + 1)); // lowest set bit
            unsigned long long countBlock = 1;
            while (countBlock * 2 <= (unsigned long long)n) countBlock *= 2;
            unsigned long long blockSize = min(alignBlock, countBlock);
            int prefixBits = 32 - (int)round(log2(blockSize));
            res.push_back(intToIp((unsigned int)start) + "/" + to_string(prefixBits));
            start += blockSize;
            n -= blockSize;
        }
        return res;
    }
};
