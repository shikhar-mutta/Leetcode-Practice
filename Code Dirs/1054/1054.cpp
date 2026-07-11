// Link: https://leetcode.com/problems/distant-barcodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) for counting the frequency of each barcode and rearranging them
    // SC: O(1) for using a fixed-size array to count the frequency of each barcode
    // Approach:
    //  1. Count the frequency of each barcode using a fixed-size array.
    //  2. Find the barcode with the maximum frequency.
    //  3. Rearrange the barcodes by placing the most frequent barcode at even indices
    //     and the rest at odd indices, ensuring that no two adjacent barcodes are the same.
    //  4. Return the rearranged barcodes.
    vector<int> rearrangeBarcodes(vector<int> &b)
    {
        short m[10001] = {};
        short max_cnt = 0, max_n = 0, pos = 0;
        for (auto n : b)
        {
            max_cnt = max(max_cnt, ++m[n]);
            max_n = max_cnt == m[n] ? n : max_n;
        }
        for (auto i = 0; i <= 10000; ++i)
        {
            auto n = i == 0 ? max_n : i;
            while (m[n]-- > 0)
            {
                b[pos] = n;
                pos = pos + 2 < b.size() ? pos + 2 : 1;
            }
        }
        return b;
    }
};
