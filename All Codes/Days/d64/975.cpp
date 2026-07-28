// Link: https://leetcode.com/problems/odd-even-jump/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: precompute, for each index i, oddNext[i] = index of the
// nearest later element that is the smallest value >= arr[i] (an "odd"
// jump target), and evenNext[i] = nearest later index with the largest
// value <= arr[i]. Both computed via sorting indices by value (with
// index as tiebreaker) and a monotonic stack scan. Then DP from the end:
// canOdd[i]/canEven[i] track whether starting an odd/even jump from i
// can reach the last index; answer counts indices where an odd jump
// (the required first move) succeeds.
class Solution {
    vector<int> nextIndexMonotonic(vector<int>& idxSorted, int n) {
        vector<int> result(n, -1);
        stack<int> stk; // indices (original) with increasing "processed order" property
        for (int idx : idxSorted) {
            while (!stk.empty() && stk.top() < idx) {
                result[stk.top()] = idx;
                stk.pop();
            }
            stk.push(idx);
        }
        return result;
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        vector<int> ascIdx = idx, descIdx = idx;
        sort(ascIdx.begin(), ascIdx.end(), [&](int a, int b) {
            if (arr[a] != arr[b]) return arr[a] < arr[b];
            return a < b;
        });
        sort(descIdx.begin(), descIdx.end(), [&](int a, int b) {
            if (arr[a] != arr[b]) return arr[a] > arr[b];
            return a < b;
        });

        vector<int> oddNext = nextIndexMonotonic(ascIdx, n);
        vector<int> evenNext = nextIndexMonotonic(descIdx, n);

        vector<bool> canOdd(n, false), canEven(n, false);
        canOdd[n - 1] = canEven[n - 1] = true;
        int count = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (oddNext[i] != -1) canOdd[i] = canEven[oddNext[i]];
            if (evenNext[i] != -1) canEven[i] = canOdd[evenNext[i]];
            if (canOdd[i]) count++;
        }
        return count;
    }
};
