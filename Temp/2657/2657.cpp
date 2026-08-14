// Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        unordered_set<int> seenA, seenB;
        for (int i = 0; i < n; i++) {
            seenA.insert(A[i]);
            seenB.insert(B[i]);
            int count = 0;
            for (int x : seenA) if (seenB.count(x)) count++;
            ans[i] = count;
        }
        return ans;
    }
};
