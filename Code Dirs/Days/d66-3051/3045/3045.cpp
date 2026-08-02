// Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m)  SC: O(n)
//  Approach: Use polynomial rolling hash to compute the hash of all prefixes and suffixes of each word. For each prefix hash, check if it matches any previously seen suffix hash and count the pairs.
//  Use a hash map to store the count of each prefix hash and suffix hash. For each word, compute the prefix and suffix hashes and update the counts in the hash map. Finally, iterate through the words again and for each prefix hash, check if it exists in the suffix hash map and add the count to the total pairs.
class Solution
{
private:
    inline static constexpr long long primeBase = 57, mod = 1e9 + 9;
    inline static long long powerBase[100000] = {1};
    inline static unordered_map<long long, long long> seen;

    static void initPowerBase()
    {
        for (int i = 1; i < 100000; ++i)
        {
            powerBase[i] = (powerBase[i - 1] * primeBase) % mod;
        }
    }

public:
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        static bool initFunc = ([]()
                                {
            initPowerBase();
            return true; })();
        seen.clear();

        long long total = 0;

        for (string &word : words)
        {
            long long fwdH = 0, bwdH = 0;
            int wordLen = word.length();
            for (int i = 0; i < wordLen; ++i)
            {
                char c = word[i], bc = word[wordLen - i - 1];
                long long ord = c - 'a' + 1;
                fwdH = (fwdH * primeBase + ord) % mod;
                long long bord = bc - 'a' + 1;
                long long bordBase = (bord * powerBase[i] + mod) % mod;
                bwdH = (bordBase + bwdH) % mod;
                if (fwdH == bwdH)
                {
                    if (seen.contains(fwdH))
                        total += seen[fwdH];
                }
            }
            ++seen[fwdH];
        }
        return total;
    }
};
