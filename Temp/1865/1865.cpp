// Link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/

#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;

    FindSumPairs(vector<int>& nums1_, vector<int>& nums2_) {
        nums1 = nums1_;
        nums2 = nums2_;
        for (int x : nums2) freq2[x]++;
    }

    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        int result = 0;
        for (int x : nums1) {
            int need = tot - x;
            if (freq2.count(need)) result += freq2[need];
        }
        return result;
    }
};
