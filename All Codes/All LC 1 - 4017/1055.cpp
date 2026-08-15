// Link: https://leetcode.com/problems/shortest-way-to-form-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_set<char> chars(source.begin(), source.end());
        for (char c : target) if (!chars.count(c)) return -1;

        int m = source.size(), n = target.size();
        int j = 0, count = 0;
        while (j < n) {
            int prevJ = j;
            for (int i = 0; i < m && j < n; i++) {
                if (source[i] == target[j]) j++;
            }
            count++;
            if (j == prevJ) return -1;
        }
        return count;
    }
};
