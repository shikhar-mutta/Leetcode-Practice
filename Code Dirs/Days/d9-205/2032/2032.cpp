// Link: https://leetcode.com/problems/two-out-of-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Using Hash Map. TC: O(n1 + n2 + n3), SC: O(n1 + n2 + n3)
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        // Create hash sets for each array to store unique elements
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), s3(nums3.begin(), nums3.end());
        // Hash map to count the frequency of each number across the three sets
        unordered_map<int, int> freq;
        for (int x : s1)
            freq[x]++;
        for (int x : s2)
            freq[x]++;
        for (int x : s3)
            freq[x]++;

        vector<int> ans;
        for (auto &[num, cnt] : freq)
            if (cnt >= 2) // At least present in two of the three arrays
                ans.push_back(num);
        return ans;
    }

    // // Approach 2: Using Hash Set. TC: O(n1 + n2 + n3), SC: O(n1 + n2 + n3)
    // vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    // {
    //     unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), s3(nums3.begin(), nums3.end());
    //     unordered_set<int> ans;
    //     for (int x : s1)
    //         if (s2.count(x) || s3.count(x)) // present in at least one of the other two arrays
    //             ans.emplace(x);             // emplace into ans if present
    //     for (int x : s2)
    //         if (s1.count(x) || s3.count(x))
    //             ans.emplace(x);
    //     for (int x : s3)
    //         if (s1.count(x) || s2.count(x))
    //             ans.emplace(x);
    //     return vector<int>(ans.begin(), ans.end());
    // }
};
