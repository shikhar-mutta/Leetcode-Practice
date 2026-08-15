// Link: https://leetcode.com/problems/long-pressed-name/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        int n = name.size(), m = typed.size();
        while (j < m) {
            if (i < n && name[i] == typed[j]) { i++; j++; }
            else if (j > 0 && typed[j] == typed[j-1]) j++;
            else return false;
        }
        return i == n;
    }
};
