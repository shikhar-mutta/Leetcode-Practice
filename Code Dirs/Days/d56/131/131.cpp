// Link: https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N * 2^N) where N is the length of the input string. The number of possible partitions is exponential, and for each partition, we may need to check if the substrings are palindromes.
    // SC: O(N) for the recursion stack and the path vector. The maximum depth of the recursion stack is N, and the path vector can store up to N substrings in the worst case.
    // Approach:
    //  1. We use a backtracking approach to explore all possible partitions of the input string.
    //  2. We define a helper function isPal to check if a substring is a palindrome.
    //  3. We define a recursive backtrack function that takes the starting index of the substring to be considered. If we reach the end of the string, we add the current path to the result. Otherwise, we iterate through all possible end indices for the substring, and if the substring is a palindrome, we add it to the path and recursively call backtrack with the next starting index. After the recursive call, we backtrack by removing the last substring from the path.
    //  4. Finally, we return the result containing all possible palindrome partitions
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<string>> result;
        vector<string> path;
        function<bool(int, int)> isPal = [&](int l, int r)
        {
            while (l < r)
            {
                if (s[l] != s[r])
                    return false;
                l++;
                r--;
            }
            return true;
        };
        function<void(int)> backtrack = [&](int start)
        {
            if (start == n)
            {
                result.push_back(path);
                return;
            }
            for (int end = start; end < n; end++)
            {
                if (isPal(start, end))
                {
                    path.push_back(s.substr(start, end - start + 1));
                    backtrack(end + 1);
                    path.pop_back();
                }
            }
        };
        backtrack(0);
        return result;
    }
};
