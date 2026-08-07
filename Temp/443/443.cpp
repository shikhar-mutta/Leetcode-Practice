// Link: https://leetcode.com/problems/string-compression/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra
// Approach: two-pointer, write compressed output in place; for runs longer
// than 1, write each digit of the run length
class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0, read = 0, n = chars.size();
        while (read < n) {
            char c = chars[read];
            int count = 0;
            while (read < n && chars[read] == c) { read++; count++; }
            chars[write++] = c;
            if (count > 1) {
                for (char d : to_string(count)) chars[write++] = d;
            }
        }
        chars.resize(write);
        return write;
    }
};
