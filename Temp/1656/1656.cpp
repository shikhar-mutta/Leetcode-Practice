// Link: https://leetcode.com/problems/design-an-ordered-stream/description/

#include <bits/stdc++.h>
using namespace std;

class OrderedStream {
public:
    vector<string> data;
    int ptr;

    OrderedStream(int n) {
        data.assign(n + 1, "");
        ptr = 1;
    }

    vector<string> insert(int idKey, string value) {
        data[idKey] = value;
        vector<string> res;
        while (ptr < (int)data.size() && !data[ptr].empty()) {
            res.push_back(data[ptr]);
            ptr++;
        }
        return res;
    }
};
