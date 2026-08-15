// Link: https://leetcode.com/problems/lexicographical-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //   1. Initialize an empty vector to store the result and a variable cur to keep track of the current number, starting from 1.
    //   2. Iterate n times to generate the lexicographical order of numbers from 1 to n.
    //  3. In each iteration, add the current number cur to the result vector.
    //  4. If cur multiplied by 10 is less than or equal to n, update cur to cur * 10 to move to the next level in the lexicographical order.
    //  5. If cur multiplied by 10 is greater than n, check if cur is a multiple of 10 or if cur + 1 is greater than n. If either condition is true, divide cur by 10 to move back up the lexicographical order until a valid next number is found.
    //  6. Increment cur by 1 to move to the next number in the lexicographical order.
    //  7. Repeat steps 3-6 until n numbers have been added to the result vector.
    //  8. Return the result vector containing the lexicographical order of numbers from 1 to n.
    vector<int> lexicalOrder(int n)
    {
        vector<int> result;
        int cur = 1;
        for (int i = 0; i < n; i++)
        {
            result.push_back(cur);
            if (cur * 10 <= n)
            {
                cur *= 10;
            }
            else
            {
                while (cur % 10 == 9 || cur + 1 > n)
                    cur /= 10;
                cur++;
            }
        }
        return result;
    }
};
