// Link: https://leetcode.com/problems/sentence-screen-fitting/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(rows)  SC: O(len)
// Approach: concatenate sentence with trailing space into a circular buffer;
// for each row advance by cols, then either consume the space we landed on
// or back up to the previous word boundary
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (auto& w : sentence) s += w + " ";
        int len = s.size();

        long long pos = 0;
        for (int i = 0; i < rows; i++) {
            pos += cols;
            if (s[pos % len] == ' ') {
                pos++;
            } else {
                while (pos > 0 && s[(pos - 1) % len] != ' ') pos--;
            }
        }
        return pos / len;
    }
};
