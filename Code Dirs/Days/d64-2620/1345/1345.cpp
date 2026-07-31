// Link: https://leetcode.com/problems/jump-game-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of elements in arr
// SC: O(n) where n is the number of elements in arr
// Approach: BFS + HashMap
//  We can use BFS to explore all possible jumps from each index. We can use a hash map to store the indices of each value in arr. The base case is when we reach an index that has already been visited, in which case we return the stored value. For each index, we can jump to the left and right, and we can also jump to any index with the same value as the current index. We keep track of the maximum number of indices we can visit starting from each index and return the maximum value among all indices.
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define BMI2 __attribute__((target("bmi2")))
#define INL_ATTR noexcept INL HOT
#define OUTL_ATTR noexcept HOT
#define LAM_ATTR INL HOT noexcept

#pragma GCC diagnostic ignored "-Wshift-op-parentheses"
#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wvla-cxx-extension"
#pragma GCC diagnostic ignored "-Wunqualified-std-cast-call"

template <class K, class T, size_t max_size, uint8_t bucket_bits, class KeyHash = std::hash<K>>
class static_flat_hash_map
{
public:
    typedef pair<K, T> value_type;
    typedef value_type *iterator;

    static constexpr K ZERO_VAL = K(1) << (sizeof(K) * 8 - 1);
    // static constexpr K ZERO_VAL { 0, 0, 0, 0, 1ull << 63 };
    static constexpr K RM_VAL = __builtin_constant_p((K)0xdeadbeefdeadbeefull) ? (K)0xdeadbeefdeadbeefull : (K)0xdeadbeefdeadbeefull;
    // static constexpr K RM_VAL { 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull };

    static bool equal(const K &km, const K &ku) INL_ATTR
    {
        return km && (km == ZERO_VAL ? K(0) : km) == ku;
    }

    static bool equal_or_free(const K &km, const K &ku) INL_ATTR
    {
        return !km || (km == ZERO_VAL ? K(0) : km) == ku;
    }

    static bool valid(const K &km) INL
    {
        return km && km != RM_VAL;
    }

    static K unmask(const K &km) INL
    {
        return km == ZERO_VAL ? 0 : km;
    }

    static constexpr size_t min_cap = 16u;

    static constexpr size_t getcap(size_t size) INL_ATTR
    {
        return size <= min_cap ? min_cap : 1ull << (64u - __builtin_clzll(size - 1u));
    }

    static constexpr size_t cap = getcap(max_size);

private:
    value_type storage[cap];
    size_t limit;
    size_t count;

    static size_t hash(const K &k) INL_ATTR
    {
        return KeyHash()(k);
    }

    value_type *locate(const K &k) OUTL_ATTR
    {
        const size_t h = (hash(k) << bucket_bits) & (limit - 1);
        size_t i = h;
        while (i < limit && !equal_or_free(storage[i].first, k))
            i++;
        if (i >= limit)
        {
            i = 0;
            while (i < h && !equal_or_free(storage[i].first, k))
                i++;
        }
        return storage + i;
    }

public:
    value_type *locate_ins(const K &k) OUTL_ATTR
    {
        const size_t h = (hash(k) << bucket_bits) & (limit - 1);
        size_t i = h;
        size_t f = h;
        while (i < limit && !equal_or_free(storage[i].first, k))
        {
            if (f == h && storage[i].first == RM_VAL)
                f = i;
            i++;
        }
        if (i >= limit)
            i = 0;
        while (i < h && !equal_or_free(storage[i].first, k))
        {
            if (f == h && storage[i].first == RM_VAL)
                f = i;
            i++;
        }
        return storage + (f == h | equal(storage[i].first, k) ? i : f);
    }

    static_flat_hash_map() INL_ATTR : limit(cap), count(0) {}

    bool contains(const K &k) INL_ATTR
    {
        value_type *p = locate(k);
        return equal(p->first, k);
    }

    iterator find(const K &k) INL_ATTR
    {
        value_type *p = locate(k);
        return p;
    }

    iterator insert(iterator p, const value_type &v) INL_ATTR
    {
        p->first = v.first ? v.first : ZERO_VAL;
        p->second = v.second;
        count++;
        return p;
    }

    iterator insert(const value_type &v) INL_ATTR
    {
        auto p = locate_ins(v.first);
        return equal(p->first, v.first) ? p : insert(p, v);
    }

    T &operator[](const K &k) INL_ATTR
    {
        auto p = locate_ins(k);
        if (!equal(p->first, k))
            insert(p, pair(k, T()));
        return p->second;
    }

    bool erase(iterator p) INL_ATTR
    {
        auto n = p + 1 < storage + limit ? p + 1 : storage;
        p->first = n->first ? RM_VAL : 0;
        count--;
        return true;
    }

    bool erase(const K &k) INL_ATTR
    {
        auto p = locate(k);
        const bool er = equal(p->first, k) ? erase(p) : false;
        return er;
    }

    void clear() INL_ATTR
    {
        fill(storage, storage + limit, value_type());
        count = 0;
    }

    void setlimit(const size_t l) INL_ATTR
    {
        limit = getcap(l);
    }

    size_t getlimit() const INL_ATTR
    {
        return limit;
    }

    size_t size() const INL_ATTR
    {
        return count;
    }

    const value_type *data() INL_ATTR
    {
        return storage;
    }
};

class Solution
{
public:
    static int minJumps(vector<int> &arr) noexcept __attribute__((hot))
    {
        constexpr uint16_t N = 50'000, NONE = (uint16_t)-1u;
        static bitset<N + 1> vis;
        static uint16_t que[N + 1], nxt[N];
        static static_flat_hash_map<uint, uint16_t, N, 1> adj; // todo hash func

        const uint n = arr.size();
        adj.setlimit(n);
        for (uint i = 0; i < n; i++)
        {
            const uint v = arr[i];
            const auto it = adj.find(v);
            const auto j = it->second;
            nxt[i] = adj.equal(it->first, v) ? j : NONE;
            adj[v] = i;
        }
        uint qs = 0, qe = 1;
        *que = 0;
        for (uint d = 0; qs < qe; d++)
        {
            for (uint l = qe - qs; l--;)
            {
                const uint i = que[qs++];
                if (i + 1 == n)
                {
                    adj.clear();
                    fill_n((uint64_t *)&vis, n + 63 >> 6, 0);
                    return d;
                }
                if (i && !vis.test(i - 1))
                {
                    que[qe++] = i - 1;
                    vis.set(i - 1);
                }
                if (i + 1 < n && !vis.test(i + 1))
                {
                    que[qe++] = i + 1;
                    vis.set(i + 1);
                }
                const uint v = arr[i];
                const auto it = adj.find(v);
                for (uint j = it->second; j != NONE; j = nxt[j])
                {
                    if (!vis.test(j))
                    {
                        que[qe++] = j;
                        vis.set(j);
                    }
                }
                it->second = NONE;
            }
        }
        adj.clear();
        fill_n((uint64_t *)&vis, n + 63 >> 6, 0);
        return -1;
    }
};

static const auto init = []() noexcept
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();