// Link: https://leetcode.com/problems/string-without-aaa-or-bbb/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        while (a > 0 || b > 0) {
            int n = res.size();
            bool useA = false;
            if (n >= 2 && res[n-1] == 'a' && res[n-2] == 'a') useA = false;
            else if (n >= 2 && res[n-1] == 'b' && res[n-2] == 'b') useA = true;
            else useA = a >= b;

            if (useA && a > 0) { res += 'a'; a--; }
            else if (!useA && b > 0) { res += 'b'; b--; }
            else if (a > 0) { res += 'a'; a--; }
            else { res += 'b'; b--; }
        }
        return res;
    }
};
