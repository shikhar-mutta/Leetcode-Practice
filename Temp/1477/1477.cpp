// Link: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = INT_MAX / 2;
        vector<int> minLenEnd(n, INF);

        int left = 0, sum = 0;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) { sum -= arr[left]; left++; }
            if (sum == target) minLenEnd[right] = right - left + 1;
        }

        vector<int> best(n, INF);
        int bestSoFar = INF;
        for (int i = 0; i < n; i++) {
            bestSoFar = min(bestSoFar, minLenEnd[i]);
            best[i] = bestSoFar;
        }

        int result = INF;
        for (int i = 1; i < n; i++) {
            if (minLenEnd[i] != INF && best[i-1] != INF) {
                result = min(result, minLenEnd[i] + best[i-1]);
            }
        }
        return result >= INF ? -1 : result;
    }
};
