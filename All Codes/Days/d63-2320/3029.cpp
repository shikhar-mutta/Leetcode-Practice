// Link: https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2/k), SC: O(n)
// Approach: Each operation removes the first k chars. After i = m*k removals,
// the string equals word's suffix starting at i. Check every multiple of k
// whether the remaining suffix, repeated/truncated to length n, reproduces
// word's prefix of that length; the first such multiple gives the answer.
class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        string s=word;
        int n=word.size();
        for(int i=k;i<n;i+=k){
            int len=n-i;
            if(s.substr(0,len)==word.substr(i)) return i/k;
        }
        return (n+k-1)/k;
    }
};
