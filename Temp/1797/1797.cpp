// Link: https://leetcode.com/problems/design-authentication-manager/description/

#include <bits/stdc++.h>
using namespace std;

class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int> expiry;

    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        expiry[tokenId] = currentTime + ttl;
    }

    void renew(string tokenId, int currentTime) {
        auto it = expiry.find(tokenId);
        if (it != expiry.end() && it->second > currentTime) {
            it->second = currentTime + ttl;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto& [k, v] : expiry) {
            if (v > currentTime) count++;
        }
        return count;
    }
};
