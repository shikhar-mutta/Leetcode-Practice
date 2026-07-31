// Link: https://leetcode.com/problems/maximum-good-people-based-on-statements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n^2)  SC: O(1)
//  Approach: brute force all 2^n subsets as candidate "good" sets. For each
//  subset, verify every good person's statements are all consistent with
//  the assumed good/bad labeling (statement 0=bad,1=good,2=unknown/ignore).
//  Track max popcount among valid subsets.
struct Info
{
    enum
    {
        bad = 0,
        good = 1,
        not_stated = 2,
    };
};

bool assume_positive(int i, vector<char> &configuration,
                     const vector<vector<int>> &statements)
{
    configuration.at(i) = Info::good;
    auto &my_stmts = statements.at(i);
    for (int j = 0; j < my_stmts.size(); ++j)
    {
        int st = my_stmts.at(j);
        if (st == Info::good)
        {
            if (configuration.at(j) == Info::bad)
            {
                return false;
            }
            else if (configuration.at(j) == Info::not_stated)
            {
                if (!assume_positive(j, configuration, statements))
                {
                    return false;
                }
            }
        }
        else if (st == Info::bad)
        {
            if (configuration.at(j) == Info::good)
            {
                return false;
            }
            configuration.at(j) = Info::bad;
        }
    }
    return true;
}

class Solution
{
public:
    int maximumGood(vector<vector<int>> &statements)
    {
        int n = statements.size();

        int best = 0;
        for (int i = 0; i < n; ++i)
        {
            vector<char> configuration(n, Info::not_stated);
            if (!assume_positive(i, configuration, statements))
            {
                cout << i << " can't be positive" << endl;
                continue;
            }
            int cur = 0;
            for (int j = 0; j < n; ++j)
            {
                if (configuration.at(j) == Info::good)
                {
                    ++cur;
                    continue;
                }
                if (configuration.at(j) == Info::bad)
                {
                    continue;
                }
                auto tmp = configuration;

                if (!assume_positive(j, configuration, statements))
                {
                    configuration = tmp;
                    configuration.at(j) = Info::bad;
                }
                else
                {
                    ++cur;
                }
            }
            best = max(best, cur);
        }
        return best;
    }
};