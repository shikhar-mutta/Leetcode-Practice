// Link: https://leetcode.com/problems/trionic-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<long long> PS(n + 1, 0);
        for (int i = 0; i < n; i++) PS[i+1] = PS[i] + nums[i];

        struct Run { int start, end; char type; }; // end inclusive
        vector<Run> runs;
        int i = 0;
        while (i < n - 1) {
            if (nums[i+1] > nums[i]) {
                int j = i;
                while (j + 1 < n && nums[j+1] > nums[j]) j++;
                runs.push_back({i, j, 'i'});
                i = j;
            } else if (nums[i+1] < nums[i]) {
                int j = i;
                while (j + 1 < n && nums[j+1] < nums[j]) j++;
                runs.push_back({i, j, 'd'});
                i = j;
            } else {
                runs.push_back({i, i, 'f'});
                i++;
            }
        }
        if (runs.empty() || runs.back().end < n - 1) runs.push_back({n-1, n-1, 'f'});

        long long best = LLONG_MIN;
        for (size_t k = 0; k < runs.size(); k++) {
            if (runs[k].type != 'd') continue;
            if (k == 0 || k + 1 >= runs.size()) continue;
            if (runs[k-1].type != 'i' || runs[k+1].type != 'i') continue;

            int p = runs[k].start, q = runs[k].end;
            int leftBound = runs[k-1].start;
            int rightBound = runs[k+1].end;

            long long minPSleft = LLONG_MAX;
            for (int l = leftBound; l <= p - 1; l++) minPSleft = min(minPSleft, PS[l]);

            long long maxPSright = LLONG_MIN;
            for (int j2 = q + 2; j2 <= rightBound + 1; j2++) maxPSright = max(maxPSright, PS[j2]);

            best = max(best, maxPSright - minPSleft);
        }

        return best;
    }
};
