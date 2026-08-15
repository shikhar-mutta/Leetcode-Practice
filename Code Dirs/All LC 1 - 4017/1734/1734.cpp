// Link: https://leetcode.com/problems/decode-xored-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int totalXor = 0;
        for (int i = 1; i <= n; i++) totalXor ^= i;
        int oddXor = 0;
        for (int i = 1; i < (int)encoded.size(); i += 2) oddXor ^= encoded[i];
        vector<int> perm(n);
        perm[0] = totalXor ^ oddXor;
        for (int i = 1; i < n; i++) perm[i] = perm[i-1] ^ encoded[i-1];
        return perm;
    }
};
