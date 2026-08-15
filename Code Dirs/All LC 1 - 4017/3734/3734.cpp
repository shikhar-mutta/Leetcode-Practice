// Link: https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(26 * n)  SC: O(26)
// Approach: a palindrome is fully determined by its first half (plus a
// middle char if n is odd), so this reduces to a "next greater arrangement"
// search over letter-pair counts. First try matching target's first half
// exactly (greedily consuming pairs); if that succeeds and, mirrored, beats
// target (only possible via a larger middle char), return it. Otherwise
// backtrack from the last placed letter: pop it, and for the first strictly
// larger available letter, place it, then fill the remaining half with all
// leftover pairs in ascending order (smallest possible completion) — this
// mirrors std::next_permutation's search-for-an-increase idea over a
// multiset.
class Solution
{
public:
    string lexPalindromicPermutation(string s, string target)
    {
        if (s.size() != target.size())
            return "";
        int n = target.size();
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;
        int oddCount = 0;
        for (int c : cnt)
            if (c % 2)
                oddCount++;
        if (oddCount > 1)
            return "";

        int mid = -1;
        if (n % 2)
        {
            for (int i = 0; i < 26; i++)
                if (cnt[i] % 2)
                {
                    mid = i;
                    break;
                }
            cnt[mid]--;
        }

        string result;
        bool matched = true;
        for (int i = 0; i < n / 2; i++)
        {
            int c = target[i] - 'a';
            cnt[c] -= 2;
            result.push_back(target[i]);
            if (cnt[c] < 0)
            {
                matched = false;
                break;
            }
        }
        if (matched)
        {
            string trial = result;
            if (mid != -1)
                trial.push_back('a' + mid);
            string half = result;
            reverse(half.begin(), half.end());
            trial += half;
            if (trial > target)
                return trial;
            if (mid != -1)
            { /* nothing extra popped since not appended to result */
            }
        }

        while (!result.empty())
        {
            char last = result.back();
            result.pop_back();
            int c = last - 'a';
            cnt[c] += 2;
            bool found = false;
            for (int i = c + 1; i < 26 && !found; i++)
            {
                if (cnt[i] <= 0)
                    continue;
                cnt[i] -= 2;
                result.push_back('a' + i);
                for (int j = 0; j < 26; j++)
                {
                    while (cnt[j] > 0)
                    {
                        cnt[j] -= 2;
                        result.push_back('a' + j);
                    }
                }
                string ret = result;
                if (mid != -1)
                    ret.push_back('a' + mid);
                string half = result;
                reverse(half.begin(), half.end());
                ret += half;
                return ret;
            }
        }
        return "";
    }
};
