// Link: https://leetcode.com/problems/design-authentication-manager/description/

#include <bits/stdc++.h>
using namespace std;

class AuthenticationManager
{
    int ttl;
    unordered_map<string, int> expiry; // tokenId -> time it expires at

public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}

    void generate(string tokenId, int currentTime)
    {
        expiry[tokenId] = currentTime + ttl;
    }

    void renew(string tokenId, int currentTime)
    {
        auto it = expiry.find(tokenId);
        // only renew if it exists and hasn't already expired
        if (it != expiry.end() && it->second > currentTime)
            it->second = currentTime + ttl;
    }

    int countUnexpiredTokens(int currentTime)
    {
        int cnt = 0;
        for (auto &[id, exp] : expiry)
            if (exp > currentTime)
                cnt++;
        return cnt;
    }
};
