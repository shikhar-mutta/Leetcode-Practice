// Link: https://leetcode.com/problems/palindrome-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log10(x))  SC: O(1)
// Approach: negatives aren't palindromes; reverse the second half of the digits and compare to the first half
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return x == rev || x == rev / 10;
    }
};
