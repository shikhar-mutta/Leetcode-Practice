// Link: https://leetcode.com/problems/find-the-index-of-the-large-integer/description/

#include <bits/stdc++.h>
using namespace std;

class ArrayReader {
public:
    vector<int> arr;

    int compareSub(int l, int r, int x, int y) {
        long long sumA = 0, sumB = 0;
        for (int i = l; i <= r; i++) sumA += arr[i];
        for (int i = x; i <= y; i++) sumB += arr[i];
        if (sumA > sumB) return 1;
        if (sumA < sumB) return -1;
        return 0;
    }

    int length() {
        return arr.size();
    }
};

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int lo = 0, hi = reader.length() - 1;
        while (lo < hi) {
            int n = hi - lo + 1;
            if (n % 2 == 0) {
                int mid = lo + n / 2 - 1;
                int c = reader.compareSub(lo, mid, mid + 1, hi);
                if (c > 0) hi = mid;
                else lo = mid + 1;
            } else {
                int mid = lo + n / 2;
                int c = reader.compareSub(lo, mid - 1, mid + 1, hi);
                if (c == 0) return mid;
                else if (c > 0) hi = mid - 1;
                else lo = mid + 1;
            }
        }
        return lo;
    }
};
