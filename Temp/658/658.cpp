// Link: https://leetcode.com/problems/find-k-closest-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n-k) + k) SC: O(1) extra
// Approach: binary search for the left boundary of the k-length window; compare x-arr[mid] vs arr[mid+k]-x to decide whether to shrink from the left.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size() - k;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (x - arr[mid] > arr[mid+k] - x) lo = mid + 1;
            else hi = mid;
        }
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};
