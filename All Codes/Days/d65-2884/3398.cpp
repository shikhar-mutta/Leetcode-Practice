// Link: https://leetcode.com/problems/smallest-substring-with-identical-characters-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(1)
// Approach: binary search the answer L (max allowed run of identical chars, L>=1 since a
// nonempty string always has runs of length >=1). For a maximal run of length len, the min
// flips to break it into pieces of size <=L is len/(L+1) (place a flip every L+1 chars). Sum
// costs over all runs and check against numOps.
class Solution {
public:
    long long cost(const string& s, int L) {
        int n = s.size();
        long long total = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;
            total += len / (L + 1);
            i = j;
        }
        return total;
    }

    int minLength(string s, int numOps) {
        int n = s.size();
        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (cost(s, mid) <= numOps) { ans = mid; hi = mid - 1; }
            else lo = mid + 1;
        }
        return ans;
    }
};
