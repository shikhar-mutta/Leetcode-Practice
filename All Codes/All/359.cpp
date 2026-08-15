// Link: https://leetcode.com/problems/logger-rate-limiter/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) per call  SC: O(unique messages)
// Approach: hashmap message -> last printed timestamp; allow if unseen or
// at least 10 seconds have passed
class Logger {
    unordered_map<string, int> lastSeen;

public:
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        auto it = lastSeen.find(message);
        if (it == lastSeen.end() || timestamp - it->second >= 10) {
            lastSeen[message] = timestamp;
            return true;
        }
        return false;
    }
};
