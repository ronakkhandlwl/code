#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define vi vector<int>
#define pii pair<int, int>
#define g_int greater<int>
#define um unordered_map
#define pq priority_queue
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define endl "\n"
#define all(v) v.begin(), v.end()

#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << '\n';

#define print1(v, x, y)         \
    for (int i = x; i < y; i++) \
        cout << v[i] << ' ';    \
    cout << '\n';

#define take(n, v)              \
    for (int i = 0; i < n; i++) \
        cin >> v[i];

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

struct segmentTree {
	int n;
	vector<int> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
	}

    /******** Main computation *********/
    int compute(int node) {
        return st[node*2+1] + st[node*2+2];
    }

	void build(int start, int ending, int node, vector<int> &v) {
		if (start == ending) {
			st[node] = v[start];
			return;
		}
		int mid = (start + ending) / 2;
        int left = 2*node+1, right = 2*node+2;
		build(start, mid, left, v);
		build(mid + 1, ending, right, v);
		st[node] = compute(node);
	}

	int query(int start, int ending, int l, int r, int node) {

		if (start > r || ending < l) return 0;
		if (start >= l && ending <= r) return st[node];

		int mid = (start + ending) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        /******** Main computation *********/
		return q1 + q2;
	}

	void update(int start, int ending, int node, int index, int value) {
		if (start == ending) {
			st[node] = value;
			return;
		}
		int mid = (start + ending) / 2;
		if (index <= mid) update(start, mid, 2 * node + 1, index, value);
		else update(mid + 1, ending, 2 * node + 2, index, value);
		st[node] = compute(node);
	}

	void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}

	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int index, int value) {
		update(0, n - 1, 0, index, value);
	}
};

void solve()
{
    vector<int> v = {1, 2, 3, 4, 8, 5, 7, 2};
    int n = 8;

    segmentTree tree;
    tree.init(8);
    tree.build(v);
    cout << tree.query(2,7) << endl;
    tree.update(3,8);
    cout << tree.query(2,7) << endl;
    tree.update(7,0);
    cout << tree.query(2,7) << endl;
}

int32_t main()
{
    fast;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}