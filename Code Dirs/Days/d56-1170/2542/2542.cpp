// Link: https://leetcode.com/problems/maximum-subsequence-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(n)
    // Approach:
    //  1. Create a vector of pairs of nums1 and nums2.
    //  2. Sort the vector of pairs in descending order of nums2.
    //  3. Use a min heap to keep track of the k largest elements of nums1.
    //  4. Iterate through the sorted vector of pairs and for each pair, if the size of the min heap is less than k-1, push the first element of the pair into the min heap and add it to the sum. If the size of the min heap is equal to k-1, calculate the score by multiplying the sum of the elements in the min heap and the second element of the pair. Update the answer if the score is greater than the current answer.
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums1[i], nums2[i]});

        sort(arr.begin(), arr.end(),
             [](auto &a, auto &b)
             {
                 return a.second > b.second;
             });

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (pq.size() < k - 1)
            {
                pq.push(arr[i].first);
                sum += arr[i].first;
            }
            else
            {
                ans = max(ans,
                          (sum + arr[i].first) * 1LL * arr[i].second);

                if (!pq.empty() && pq.top() < arr[i].first)
                {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(arr[i].first);
                    sum += arr[i].first;
                }
            }
        }

        return ans;
    }
};
