// Link: https://leetcode.com/problems/longest-uploaded-prefix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per upload/longest call, O(n) for the constructor
// SC: O(n)
// Approach: keep a boolean-uploaded flag per video index and a running
// "ans" pointer marking the longest uploaded prefix so far. Each upload
// only needs to advance ans while the next video is already uploaded;
// since ans only ever moves forward, the total work across all uploads
// is bounded by n.
class LUPrefix {
    vector<bool> v;
    int ans;

public:
    LUPrefix(int n) {
        v.resize(n + 1);
        v[0] = true;
        ans = 0;
    }

    void upload(int video) {
        v[video] = true;
        int temp = video;
        while (ans < v.size() - 1 && v[ans + 1]) {
            ans++;
        }
    }

    int longest() { return ans; }
};
