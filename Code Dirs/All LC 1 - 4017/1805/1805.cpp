// Link: https://leetcode.com/problems/number-of-different-integers-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> nums;
        int n = word.size();
        int i = 0;
        while (i < n) {
            if (isdigit(word[i])) {
                int j = i;
                while (j < n && isdigit(word[j])) j++;
                int k = i;
                while (k < j - 1 && word[k] == '0') k++;
                nums.insert(word.substr(k, j - k));
                i = j;
            } else {
                i++;
            }
        }
        return nums.size();
    }
};
