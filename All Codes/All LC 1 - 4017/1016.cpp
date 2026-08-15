// Link: https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //TC: O(n * log(n)) where n is the input number.
    //SC: O(1) as we are using constant space.
    //Approach:
    // 1. We will iterate from n to 1 and for each number, we will convert it to binary representation and check if it is present in the string s.
    // 2. If any number is not present in the string s, we will return false.
    // 3. If all numbers are present in the string s, we will return true.
    bool queryString(string s, int n) {
        for (int i = n; i >= 1; i--) {
            string bin;
            for (int x = i; x > 0; x >>= 1) bin = char('0' + (x & 1)) + bin;
            if (s.find(bin) == string::npos) return false;
        }
        return true;
    }
};
