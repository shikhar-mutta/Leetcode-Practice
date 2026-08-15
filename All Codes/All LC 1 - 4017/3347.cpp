// // Link: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/

// #include <bits/stdc++.h>
// using namespace std;

// // TC: O(nlogn), SC: O(1)
// // Approach: Sort the array and use two pointers to find the maximum frequency of an element after performing operations. For each element, calculate the range of values that can be achieved by adding or subtracting k. Use a sliding window to count how many elements fall within this range and update the maximum frequency accordingly.
// class Solution
// {
// public:
//     static int maxFrequency(vector<int> &nums, int k, int numOperations)
//     {
//         const int n = nums.size();
//         sort(nums.begin(), nums.end());

//         int ans = 0, cnt = 0;
//         int l = 0, r = 0;
//         // Consider nums[i]
//         for (int i = 0; i < n; i++)
//         {
//             const int x = nums[i], L = max(1, x - k),
//                       R = min(nums.back(), x + k);

//             // count freq
//             int f = 1;
//             int j = i + 1;
//             for (; j < n && nums[j] == x; j++)
//                 f++;
//             i = j - 1; // nums[j]!=x

//             // move l
//             while (l < n && nums[l] < L)
//                 l++;

//             // move r
//             r = (r > i) ? r : i; // start r from last position
//             while (r + 1 < n && nums[r + 1] <= R)
//                 r++;

//             cnt = r - l + 1;
//             ans = max(ans, f + min(cnt - f, numOperations));
//         }

//         // consider the subintervals with overlapping
//         for (l = 0, r = 0; r < n; r++)
//         {
//             int x = nums[r], L = max(1, x - 2 * k);
//             while (l < r && nums[l] < L)
//                 l++;
//             ans = max(ans, min(r - l + 1, numOperations));
//         }
//         return ans;
//     }
// };