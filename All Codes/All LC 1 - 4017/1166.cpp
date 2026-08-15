// Link: https://leetcode.com/problems/design-file-system/description/

#include <bits/stdc++.h>
using namespace std;

class FileSystem {
    unordered_map<string, int> paths;
public:
    FileSystem() {}

    bool createPath(string path, int value) {
        if (path.empty() || path == "/" || paths.count(path)) return false;
        int pos = path.find_last_of('/');
        if (pos == 0) {
            // parent is root "/"
        } else {
            string parent = path.substr(0, pos);
            if (!paths.count(parent)) return false;
        }
        paths[path] = value;
        return true;
    }

    int get(string path) {
        return paths.count(path) ? paths[path] : -1;
    }
};
