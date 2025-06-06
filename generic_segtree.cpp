#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...) 
#endif

#define MOD 1000000007
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define int long long 

#define pans cout <<ans<< endl
#define pyes cout << "YES" << endl
#define pno cout << "NO" << endl
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }


template<typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<int> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<int> &a) {
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n) s <<= 1;
        tree.resize(s); fill(all(tree), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) {  // Never change this
        if (start == end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u) {  // Never change this
        if (start == end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) {  // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, int val) {  // pass in as many parameters as required
        Update new_update = Update(val);  // may change
        update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    int val;  // may change
    Node1() {  // Identity element
        val = 0;  // may change
    }
    Node1(int p1) {  // Actual Node
        val = p1;  // may change
    }
    void merge(Node1 &l, Node1 &r) {  // Merge two child nodes
        val = l.val ^ r.val;  // may change
    }
};

struct Update1 {
    int val;  // may change
    Update1(int p1) {  // Actual Update
        val = p1;  // may change
    }
    void apply(Node1 &a) {  // apply update to given node
        a.val = val;  // may change
    }
};
    
void solve() {
}

signed main() {
    fast_io();
    
    int tt = 1;
    cin >> tt;
    
    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}
    
