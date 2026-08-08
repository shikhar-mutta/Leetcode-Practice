// Link: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right && s[left] == s[right]) {
            char c = s[left];
            while (left <= right && s[left] == c) left++;
            while (right >= left && s[right] == c) right--;
        }
        return right - left + 1;
    }
};
