// Link: https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n), where n is the length of the string num.
    // SC: O(n), as we are using a vector to store the result.
    //  Approach:
    //  1. We use a recursive function to generate all possible combinations of the string num.
    //  2. We keep track of the current index in the string and the current result vector.
    //  3. We check if the current number is a valid Fibonacci number by checking if it is equal to the sum of the last two numbers in the result vector.
    //  4. If it is a valid Fibonacci number, we add it to the result vector and continue the recursion.
    //  5. If we reach the end of the string and the result vector has more than 2 numbers, we return true. Otherwise, we backtrack and try the next combination
    //  6. Finally, we return the result vector if we found a valid Fibonacci sequence, otherwise we return an empty vector.
    bool getresult(string s, vector<int> &result, int i)
    {
        if (i == s.size())
        {
            if (result.size() > 2)
                return true;
        }

        int num = 0;
        for (int ind = i; ind < s.size(); ind++)
        {
            if (num < 0 || num > INT_MAX / 10)
                return false;
            num = num * 10 + (s[ind] - '0');
            int size = result.size();
            long long sum = 0;
            if (size >= 2)
                sum = (long long)result[result.size() - 1] +
                      result[result.size() - 2];
            if (result.size() < 2 || (size >= 2 && sum <= INT_MAX && sum == num))
            {
                result.push_back(num);

                if (getresult(s, result, ind + 1))
                    return true;
                result.pop_back();
            }
            if (ind == i && s[i] == '0')
                return false;
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num)
    {
        vector<int> result;
        return getresult(num, result, 0) ? result : vector<int>{};
    }
};