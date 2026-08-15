// Link: https://leetcode.com/problems/design-a-file-sharing-system/description/

#include <bits/stdc++.h>
using namespace std;

class FileSharing {
public:
    int nextId = 1;
    unordered_map<int, unordered_set<int>> userChunks;
    priority_queue<int, vector<int>, greater<int>> freeIds;

    FileSharing(int m) {}

    int join(vector<int> ownedChunks) {
        int id;
        if (!freeIds.empty()) { id = freeIds.top(); freeIds.pop(); }
        else id = nextId++;
        userChunks[id] = unordered_set<int>(ownedChunks.begin(), ownedChunks.end());
        return id;
    }

    void leave(int userID) {
        userChunks.erase(userID);
        freeIds.push(userID);
    }

    vector<int> request(int userID, int chunkID) {
        vector<int> res;
        for (auto& [id, chunks] : userChunks) {
            if (id != userID && chunks.count(chunkID)) res.push_back(id);
        }
        sort(res.begin(), res.end());
        if (!res.empty()) userChunks[userID].insert(chunkID);
        return res;
    }
};
