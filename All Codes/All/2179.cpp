// Link: https://leetcode.com/problems/count-good-triplets-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bit;
    int bn;
    void update(int i) {
        for (i++; i <= bn; i += i & (-i)) bit[i]++;
    }
    int query(int i) {
        int s = 0;
        for (i++; i > 0; i -= i & (-i)) s += bit[i];
        return s;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; i++) pos2[nums2[i]] = i;
        vector<int> posInNums2(n);
        for (int i = 0; i < n; i++) posInNums2[i] = pos2[nums1[i]];

        vector<long long> leftCount(n, 0), rightCount(n, 0);
        bn = n;
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            leftCount[i] = query(posInNums2[i] - 1);
            update(posInNums2[i]);
        }
        bit.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int totalSeen = query(n - 1) ; // count of elements to the right processed so far with any pos
            int countLE = query(posInNums2[i]);
            rightCount[i] = totalSeen - countLE;
            update(posInNums2[i]);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) total += leftCount[i] * rightCount[i];
        return total;
    }
};
