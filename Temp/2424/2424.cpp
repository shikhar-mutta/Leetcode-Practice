// Link: https://leetcode.com/problems/longest-uploaded-prefix/description/

#include <bits/stdc++.h>
using namespace std;

class LUPrefix {
    vector<bool> uploaded;
    int longestPrefix;
public:
    LUPrefix(int n) {
        uploaded.assign(n + 2, false);
        longestPrefix = 0;
    }

    void upload(int video) {
        uploaded[video] = true;
        while (uploaded[longestPrefix + 1]) longestPrefix++;
    }

    int longest() {
        return longestPrefix;
    }
};
