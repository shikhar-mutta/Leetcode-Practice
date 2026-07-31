// Link: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
//  Approach: We can use a stack to solve this problem. We can iterate through the array and for each number, we can check if it is coprime with the last number in the stack. If it is not coprime, we can replace the last number in the stack with the product of the two numbers divided by their GCD. We can then continue this process until we find a coprime number or the stack is empty. We can then push the current number onto the stack. Finally, we can return the stack as the result.
class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> ans;
        for (int &num : nums)
        {
            while (!ans.empty())
            {
                int last = ans.back();
                int g = gcd(last, num);
                if (g > 1)
                {
                    num = last / g * num;
                    ans.pop_back();
                }
                else
                {
                    break;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};
