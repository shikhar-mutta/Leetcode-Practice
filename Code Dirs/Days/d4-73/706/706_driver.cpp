#include <bits/stdc++.h>
using namespace std;
#include "706.cpp"

// ── read helpers ──────────────706_driver.cpp 706_expected.txt 706_input.txt 706.cpp────────────────────────────────────
int _ri()
{
    string s;
    getline(cin, s);
    return stoi(s);
}
long long _rll()
{
    string s;
    getline(cin, s);
    return stoll(s);
}
double _rd()
{
    string s;
    getline(cin, s);
    return stod(s);
}
bool _rb()
{
    string s;
    getline(cin, s);
    return s == "true" || s == "1";
}
string _rs()
{
    string s;
    getline(cin, s);
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"')
        s = s.substr(1, s.size() - 2);
    return s;
}

vector<int> _rvi()
{
    string s;
    getline(cin, s);
    vector<int> v;
    stringstream ss(s.substr(1, s.size() - 2));
    string t;
    while (getline(ss, t, ','))
    {
        if (!t.empty())
            v.push_back(stoi(t));
    }
    return v;
}
vector<long long> _rvll()
{
    string s;
    getline(cin, s);
    vector<long long> v;
    stringstream ss(s.substr(1, s.size() - 2));
    string t;
    while (getline(ss, t, ','))
    {
        if (!t.empty())
            v.push_back(stoll(t));
    }
    return v;
}
vector<string> _rvs()
{
    string s;
    getline(cin, s);
    vector<string> v;
    auto body = s.substr(1, s.size() - 2);
    bool in = false;
    string cur;
    for (char c : body)
    {
        if (c == '"')
        {
            in = !in;
            continue;
        }
        if (c == ',' && !in)
        {
            v.push_back(cur);
            cur = "";
            continue;
        }
        cur += c;
    }
    if (!cur.empty())
        v.push_back(cur);
    return v;
}
vector<vector<int>> _rvvi()
{
    string s;
    getline(cin, s);
    vector<vector<int>> v;
    int dep = 0;
    string cur;
    for (char c : s)
    {
        if (c == '[')
        {
            dep++;
            if (dep > 2)
                cur += c;
        }
        else if (c == ']')
        {
            dep--;
            if (dep == 1)
            {
                vector<int> row;
                stringstream ss(cur);
                string t;
                while (getline(ss, t, ','))
                    if (!t.empty())
                        row.push_back(stoi(t));
                v.push_back(row);
                cur = "";
            }
            else if (dep > 0)
                cur += c;
        }
        else if (dep > 1)
            cur += c;
    }
    return v;
}


struct TeeBuf : std::streambuf {
    std::streambuf *orig, *echo;
    TeeBuf(std::streambuf* o, std::streambuf* e) : orig(o), echo(e) {}
    int_type uflow() override {
        int_type c = orig->sbumpc();
        if (c != traits_type::eof()) echo->sputc(c);
        return c;
    }
    int_type underflow() override { return orig->sgetc(); }
    std::streamsize xsgetn(char* s, std::streamsize n) override {
        std::streamsize got = orig->sgetn(s, n);
        echo->sputn(s, got);
        return got;
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    cin.rdbuf(new TeeBuf(cin.rdbuf(), cerr.rdbuf()));
    while (t--)
        struct Guard { ~Guard() { cerr << "\n---\n"; } } _guard;
    {
        vector<string> ops = _rvs();
        vector<vector<int>> args = _rvvi();

        MyHashMap* obj = nullptr;
        vector<string> results;

        for (int i = 0; i < (int)ops.size(); i++)
        {
            if (ops[i] == "MyHashMap")
            {
                obj = new MyHashMap();
                results.push_back("null");
            }
            else if (ops[i] == "put")
            {
                obj->put(args[i][0], args[i][1]);
                results.push_back("null");
            }
            else if (ops[i] == "get")
            {
                results.push_back(to_string(obj->get(args[i][0])));
            }
            else if (ops[i] == "remove")
            {
                obj->remove(args[i][0]);
                results.push_back("null");
            }
        }

        cout << "[";
        for (int i = 0; i < (int)results.size(); i++)
        {
            if (i) cout << ", ";
            cout << results[i];
        }
        cout << "]" << endl;

        delete obj;
    }
    return 0;
}
