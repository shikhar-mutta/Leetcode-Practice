// Link: https://leetcode.com/problems/decode-the-slanted-ciphertext/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 0) return "";
        int cols = n / rows;
        string res;
        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                int idx = r * cols + c + r;
                if (idx >= n) break;
                res += encodedText[idx];
            }
        }
        while (!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }
};
