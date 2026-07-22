// Link: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R^2 * C * log(C)) where R is the number of rows and C is the number of columns in the matrix.
// SC: O(C) where C is the number of columns in the matrix.
// Approach:
//     1. The problem is to find the maximum sum of a rectangle in a 2D matrix such that the sum is no larger than a given integer k.
//     2. The solution uses a combination of prefix sums and binary search to efficiently find the maximum sum of a rectangle.
//     3. The algorithm iterates through all possible pairs of rows and calculates the sum   of the elements in the rectangle defined by those rows and all columns.
//     4. For each pair of rows, it maintains a running sum of the elements in the rectangle and uses a sorted array to perform binary search to find the maximum sum that is no larger than k.
//     5. The final result is returned as the maximum sum of a rectangle in the matrix that is no larger than k.
class Solution
{
public:
    vector<vector<int>> build2Dprefix(vector<vector<int>> a)
    {
        int r = a.size(), c = a[0].size();
        vector<vector<int>> prefix(r + 1, vector<int>(c + 1, 0));
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] +
                               a[i - 1][j - 1] - prefix[i - 1][j - 1];
            }
        }
        return prefix;
    }
    int brute(vector<vector<int>> &a, int k)
    {
        int r = a.size();
        int c = a[0].size();

        auto prefix = build2Dprefix(a);

        int ans = INT_MIN;
        for (int r1 = 0; r1 < r; r1++)
        {
            for (int c1 = 0; c1 < c; c1++)
            {
                for (int r2 = r1; r2 < r; r2++)
                {
                    for (int c2 = c1; c2 < c; c2++)
                    {
                        int sum = prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] -
                                  prefix[r2 + 1][c1] + prefix[r1][c1];
                        if (sum <= k)
                        {
                            ans = max(ans, sum);
                        }
                    }
                }
            }
        }
        return ans;
    }
    int better(vector<vector<int>> &a, int k)
    {
        int r = a.size();
        int c = a[0].size();

        int ans = INT_MIN;
        for (int left = 0; left < c; left++)
        { // pick start col
            vector<int> rowsum(r, 0);
            for (int right = left; right < c; right++)
            { // pick end col
                for (int row = 0; row < r; row++)
                { // building compressed array
                    rowsum[row] += a[row][right];
                }

                for (int top = 0; top < r; top++)
                { // chooses start row
                    int sum = 0;
                    for (int bottom = top; bottom < r;
                         bottom++)
                    { // chooses end row
                        sum +=
                            rowsum[bottom]; // building prefixsum over every col
                        if (sum <= k)
                        {
                            ans = max(ans, sum);
                        }
                    }
                }
            }
        }
        return ans;
    }
    int optimal(vector<vector<int>> &a, int k)
    {
        int r = a.size(), c = a[0].size();
        int ans = INT_MIN;

        bool tr = r > c;
        int R = tr ? c : r;
        int C = tr ? r : c;

        vector<int> arr(C);
        int sorted[101];

        for (int i = 0; i < R; ++i)
        {
            fill(arr.begin(), arr.end(), 0);
            for (int j = i; j < R; ++j)
            {
                for (int c = 0; c < C; ++c)
                {
                    arr[c] += tr ? a[c][j] : a[j][c];
                }

                int cur = 0, sz = 1;
                sorted[0] = 0;

                for (int x : arr)
                {
                    cur += x;
                    int need = cur - k;

                    int lo = 0, hi = sz;
                    while (lo < hi)
                    {
                        int mid = (lo + hi) >> 1;
                        if (sorted[mid] < need)
                            lo = mid + 1;
                        else
                            hi = mid;
                    }

                    if (lo < sz)
                    {
                        int val = cur - sorted[lo];
                        if (val > ans)
                        {
                            ans = val;
                            if (ans == k)
                                return k;
                        }
                    }

                    lo = 0, hi = sz;
                    while (lo < hi)
                    {
                        int mid = (lo + hi) >> 1;
                        if (sorted[mid] < cur)
                            lo = mid + 1;
                        else
                            hi = mid;
                    }

                    if (lo < sz && sorted[lo] == cur)
                        continue;

                    for (int p = sz; p > lo; --p)
                        sorted[p] = sorted[p - 1];
                    sorted[lo] = cur;
                    ++sz;
                }
            }
        }

        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int r = matrix.size(), c = matrix[0].size();
        int ans = INT_MIN;

        bool tr = r > c;
        int R = tr ? c : r;
        int C = tr ? r : c;

        vector<int> arr(C);
        int sorted[101];

        for (int i = 0; i < R; ++i)
        {
            fill(arr.begin(), arr.end(), 0);
            for (int j = i; j < R; ++j)
            {
                for (int c = 0; c < C; ++c)
                {
                    arr[c] += tr ? matrix[c][j] : matrix[j][c];
                }

                int cur = 0, sz = 1;
                sorted[0] = 0;

                for (int x : arr)
                {
                    cur += x;
                    int need = cur - k;

                    int lo = 0, hi = sz;
                    while (lo < hi)
                    {
                        int mid = (lo + hi) >> 1;
                        if (sorted[mid] < need)
                            lo = mid + 1;
                        else
                            hi = mid;
                    }

                    if (lo < sz)
                    {
                        int val = cur - sorted[lo];
                        if (val > ans)
                        {
                            ans = val;
                            if (ans == k)
                                return k;
                        }
                    }

                    lo = 0, hi = sz;
                    while (lo < hi)
                    {
                        int mid = (lo + hi) >> 1;
                        if (sorted[mid] < cur)
                            lo = mid + 1;
                        else
                            hi = mid;
                    }

                    if (lo < sz && sorted[lo] == cur)
                        continue;

                    for (int p = sz; p > lo; --p)
                        sorted[p] = sorted[p - 1];
                    sorted[lo] = cur;
                    ++sz;
                }
            }
        }
        return ans;
    }
};