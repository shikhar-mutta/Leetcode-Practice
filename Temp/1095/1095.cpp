// Link: https://leetcode.com/problems/find-in-mountain-array/description/

#include <bits/stdc++.h>
using namespace std;

class MountainArray {
    vector<int> arr;
public:
    MountainArray(vector<int>& a) : arr(a) {}
    int get(int index) { return arr[index]; }
    int length() { return arr.size(); }
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) lo = mid + 1;
            else hi = mid;
        }
        int peak = lo;

        lo = 0; hi = peak;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int v = mountainArr.get(mid);
            if (v == target) return mid;
            if (v < target) lo = mid + 1;
            else hi = mid - 1;
        }

        lo = peak; hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int v = mountainArr.get(mid);
            if (v == target) return mid;
            if (v > target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};
