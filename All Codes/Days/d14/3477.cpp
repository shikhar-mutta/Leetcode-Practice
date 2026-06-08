// Link: https://leetcode.com/problems/fruits-into-baskets-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(n)
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size(), j, cnt = 0;
        bitset<101> inBasket, inFruit;
        for (int i = 0; i < n; i++)
        {
            j = 0;
            while (j < n && (inBasket[j] || baskets[j] < fruits[i]))
                j++;
            if (j < n)
            {
                inBasket[j] = 1;
                inFruit[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
            if (!inFruit[i])
                cnt++;

        return cnt;
    }
};
