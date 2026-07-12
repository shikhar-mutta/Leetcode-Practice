// Link: https://leetcode.com/problems/search-suggestions-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + m*logn + m*3) = O(nlogn + mlogn), SC: O(n)
//  Approach:
//  1. Sort the products array to ensure lexicographical order.
//  2. For each character in the searchWord, build the prefix and use binary search (lower_bound) to find the first product that matches the prefix.
//  3. Collect up to 3 matching products for each prefix and store them in the result vector.
//  4. Return the result vector containing suggestions for each prefix of the searchWord.
class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string prefix;
        auto lo = products.begin();
        for (char c : searchWord)
        {
            prefix += c;
            // first product >= prefix; search resumes from previous lo
            lo = lower_bound(lo, products.end(), prefix);
            vector<string> sug;
            for (auto it = lo; it != products.end() && sug.size() < 3; ++it)
            {
                if (it->compare(0, prefix.size(), prefix) != 0)
                    break;
                sug.push_back(*it);
            }
            res.push_back(move(sug));
        }
        return res;
    }
};
