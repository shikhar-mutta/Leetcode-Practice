// Link: https://leetcode.com/problems/count-good-triplets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int count = 0;
        int n = arr.size();
        // sorted array is not required as we are checking for absolute difference
        for (int i = 0; i < n - 2; i++) // i < n-2 to ensure least 2 elements after i
        {
            for (int j = i + 1; j < n - 1; j++) // j=i+1 to ensure i<j && least 1 element after j
            {
                for (int k = j + 1; k < n; k++) // k=j+1 to ensure i<j<k && least 0 element after k
                {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
