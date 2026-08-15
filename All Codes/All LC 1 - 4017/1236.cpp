// Link: https://leetcode.com/problems/web-crawler/description/

#include <bits/stdc++.h>
using namespace std;

class HtmlParser {
public:
    unordered_map<string, vector<string>> graph;
    vector<string> getUrls(string url) {
        if (graph.count(url)) return graph[url];
        return {};
    }
};

class Solution {
public:
    string hostname(const string& url) {
        int start = url.find("//") + 2;
        int end = url.find('/', start);
        if (end == (int)string::npos) return url.substr(start);
        return url.substr(start, end - start);
    }

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string host = hostname(startUrl);
        unordered_set<string> visited;
        visited.insert(startUrl);
        queue<string> q;
        q.push(startUrl);
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            for (auto& next : htmlParser.getUrls(cur)) {
                if (hostname(next) == host && !visited.count(next)) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        return vector<string>(visited.begin(), visited.end());
    }
};
