#include <bits/stdc++.h>
using namespace std;

class ArrayReader {
public:
    virtual int get(int index) = 0;
};

class ArrayReaderImpl : public ArrayReader {
    vector<int> data;
public:
    ArrayReaderImpl(vector<int> d) : data(d) {}
    int get(int index) override {
        if (index >= (int)data.size()) return INT_MAX;
        return data[index];
    }
};

#include "702.cpp"

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}
int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto nums = _rvi();
        int target = _ri();
        ArrayReaderImpl reader(nums);
        Solution sol;
        auto res = sol.search(reader, target);
        cout << res << "\n";
    }
    return 0;
}
