// Link: https://leetcode.com/problems/longest-balanced-substring-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: the alphabet here is only {a,b,c}, so a balanced substring
//  uses exactly 1, 2, or 3 distinct letters:
//  - 1 letter: longest run of a single repeated character.
//  - 2 letters (a,b): within maximal runs restricted to those two
//    letters, track running difference d = count(a)-count(b); the first
//    time a given d value repeats, the substring between those two
//    positions has equal counts of a and b (classic equal-subarray via
//    prefix-difference + first-occurrence hashmap).
//  - 3 letters: track (count(a)-count(b), count(b)-count(c)) as a pair
//    key over the whole string; a repeated key means the substring
//    between occurrences has all three counts equal.
class Solution
{
private:
    static uint64_t mixHash(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    int longestOneChar(const string &s)
    {
        int answer = 0;
        int n = s.size();

        for (int i = 0; i < n;)
        {
            int j = i + 1;

            while (j < n && s[j] == s[i])
            {
                j++;
            }

            answer = max(answer, j - i);
            i = j;
        }

        return answer;
    }

    int longestTwoChars(const string &s, char x, char y)
    {
        int n = s.size();
        int offset = n;
        int answer = 0;

        vector<int> first(2 * n + 1, -2);
        vector<int> touched;

        int i = 0;

        while (i < n)
        {
            while (i < n && s[i] != x && s[i] != y)
            {
                i++;
            }

            if (i == n)
            {
                break;
            }

            touched.clear();

            int balance = 0;
            first[offset] = i - 1;
            touched.push_back(offset);

            while (i < n && (s[i] == x || s[i] == y))
            {
                balance += (s[i] == x ? 1 : -1);

                int index = balance + offset;

                if (first[index] != -2)
                {
                    answer = max(answer, i - first[index]);
                }
                else
                {
                    first[index] = i;
                    touched.push_back(index);
                }

                i++;
            }

            for (int index : touched)
            {
                first[index] = -2;
            }
        }

        return answer;
    }

    int longestThreeChars(const string &s)
    {
        int n = s.size();

        int tableSize = 1;

        while (tableSize < 2 * (n + 1))
        {
            tableSize <<= 1;
        }

        vector<uint64_t> keys(tableSize);
        vector<int> firstPosition(tableSize);
        vector<unsigned char> used(tableSize, 0);

        auto makeKey = [](int x, int y) -> uint64_t
        {
            uint32_t a = static_cast<uint32_t>(x);
            uint32_t b = static_cast<uint32_t>(y);

            return (static_cast<uint64_t>(a) << 32) | b;
        };

        auto getFirstPosition = [&](uint64_t key, int position)
        {
            int index = static_cast<int>(mixHash(key) &
                                         static_cast<uint64_t>(tableSize - 1));

            while (used[index] && keys[index] != key)
            {
                index = (index + 1) & (tableSize - 1);
            }

            if (!used[index])
            {
                used[index] = 1;
                keys[index] = key;
                firstPosition[index] = position;
                return position;
            }

            return firstPosition[index];
        };

        int countA = 0;
        int countB = 0;
        int countC = 0;
        int answer = 0;

        getFirstPosition(makeKey(0, 0), -1);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                countA++;
            }
            else if (s[i] == 'b')
            {
                countB++;
            }
            else
            {
                countC++;
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            uint64_t key = makeKey(diffAB, diffAC);
            int earliest = getFirstPosition(key, i);

            answer = max(answer, i - earliest);
        }

        return answer;
    }

public:
    int longestBalanced(string s)
    {
        int answer = longestOneChar(s);

        answer = max(answer, longestTwoChars(s, 'a', 'b'));
        answer = max(answer, longestTwoChars(s, 'a', 'c'));
        answer = max(answer, longestTwoChars(s, 'b', 'c'));
        answer = max(answer, longestThreeChars(s));

        return answer;
    }
};