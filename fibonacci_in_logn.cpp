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


struct mat {
    pii p1, p2;

    mat() {
        p1.first = 1;
        p1.second = 1;
        p2.first = 1;
        p2.second = 0;
    }

    mat operator* (mat a) {
        mat res;
        res.p1.first = ((p1.first*a.p1.first)%mod + (p1.second*a.p2.first)%mod)%mod;
        res.p1.second = ((p1.first*a.p1.second)%mod + (p1.second*a.p2.second)%mod)%mod;
        res.p2.first = ((p2.first*a.p1.first)%mod + (p2.second*a.p2.first)%mod)%mod;
        res.p2.second = ((p2.first*a.p1.second)%mod + (p2.second*a.p2.second)%mod)%mod;
        return res;
    }
};

mat powerWithMod(mat a, int b) {
    if(b==1) return a;
    mat x = powerWithMod(a,b/2);
    if(b&1) return (x*x*a);
    return (x*x);
}

int solve()
{
    int n; cin >> n;
    if(n<=2) return 1;
    mat m;
    mat res = powerWithMod(m, n-2);
    return (res.p1.first + res.p1.second)%mod;
}

int32_t main()
{
    fast;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
}