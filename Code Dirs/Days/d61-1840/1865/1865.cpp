// Link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/

#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<int, int> umii;

// TC: O(n), SC: O(n)
//  Approach:
//    1. We can use a hash map to store the frequency of each element in nums2.
//    2. For the add operation, we can simply update the frequency of the element at the given index in nums2.
//    3. For the count operation, we can iterate through nums1 and for each element, we can check if the complement (tot - nums1[i]) exists in the hash map. If it does, we can add the frequency of that complement to the count.
//    4. We can also keep track of the maximum and minimum elements in nums2 to optimize the count operation by limiting the range of nums1 we need to check.
class FindSumPairs
{
private:
    vector<int> nums1, nums2;
    umii freq;
    int max_e, min_e;

    void populate_map()
    { // O(n)
        for (int x : this->nums2)
        {
            freq[x]++;
        }
    }

public:
    FindSumPairs(vector<int> &nums1,
                 vector<int> &nums2)
    {                                                     // O(mlgm + 4n) ~ O(n), k=4
        this->nums1 = nums1;                              // O(m)
        this->nums2 = nums2;                              // O(n)
        populate_map();                                   // O(n)
        sort(this->nums1.begin(), this->nums1.end());     // O(m log m)
        max_e = *max_element(nums2.begin(), nums2.end()); // O(n)
        min_e = *min_element(nums2.begin(), nums2.end()); // O(n)
    }

    void add(int index, int val)
    { // O(1)
        freq[nums2[index]]--;
        nums2[index] += val; // O(1)
        freq[nums2[index]]++;
        max_e = max(max_e, nums2[index]);
    }

    int count(int tot)
    { // O(m)
        int count = 0;
        int start = lower_bound(nums1.begin(), nums1.end(), tot - max_e) -
                    nums1.begin(); // O(lg m)
        int end = upper_bound(nums1.begin(), nums1.end(), tot - min_e) -
                  nums1.begin(); // O(lg m)
        for (int i = start; i < end; i++)
        { // O(m)
            count += freq[tot - nums1[i]];
        }
        return count;
    }
};
