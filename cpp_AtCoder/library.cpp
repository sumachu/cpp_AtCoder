#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

template<class Type>
Type mod_pow(Type a, Type n, Type mod)
{
	Type res = 1;
	while (0 < n) {
		if (n & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

template<class Type>
Type gcd(Type x, Type y)
{
	Type r;
	if (x < y) swap(x, y);

	while (0 < y) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

template<class Type>
Type lcm(Type x, Type y)
{
	return x / gcd(x, y) * y;
}

template<class Type>
bool is_prime(Type x)
{
	if (x == 2) return true;
	if (x < 2 || x % 2 == 0) return false;

	for (Type i = 3; i <= sqrt(x); i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

template<class Type>
vector<bool> eratos(Type n)
{
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (Type i = 2; i <= n; i++) {
		if (isPrime[i]) {
			Type j = i + i;
			while (j <= n) {
				isPrime[j] = false;
				j = j + i;
			}
		}
	}
	return isPrime;
}

bool binary_search_judge(vector<int> a, int index, int key)
{
	if (key <= a[index]) return true;
	else return false;
}

int binary_search(vector<int> a, int key)
{
	int ng = -1;
	int ok = a.size();
	while (1 < abs(ng - ok)) {
		int mid = (ng + ok) / 2;
		if (binary_search_judge(a, mid, key)) ok = mid;
		else ng = mid;
	}
	return a[ok] == key;
}

struct mint
{
	ll x;
	mint(ll x = 0) :x((x% mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a)
	{
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a)
	{
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a)
	{
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const
	{
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const
	{
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const
	{
		mint res(*this);
		return res *= a;
	}
	mint pow(ll t) const
	{
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const
	{
		return pow(mod - 2);
	}
	mint& operator/=(const mint a)
	{
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const
	{
		mint res(*this);
		return res /= a;
	}
};

template<class Type>
mint inv_nCk(Type n, Type k)
{
	//  1<= n <= 1e9 (n‚ÍŒÅ’è’l), 1 <= k <= 1e7
	mint x = 1, y = 1;
	for (Type i = 0; i < k; i++) {
		x *= n - i;
		y *= i + 1;
	}
	return x / y;
}

struct combination
{
	//  1 <= k <= n <= 1e7Amod‚Í‘f”
	vector<mint> fact, ifact;
	combination(int n) :fact(n + 1), ifact(n + 1)
	{
		assert(n < mod);
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
		ifact[n] = fact[n].inv();
		for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
	}
	mint operator()(int n, int k)
	{
		if (k < 0 || k > n) return 0;
		return fact[n] * ifact[k] * ifact[n - k];
	}
};

template<class Type>
Type pascal_nCk(Type n, Type k, Type mod)
{
	//  1 <= k <= n <= 2e7Amod‚Í‘f”ˆÈŠO‚Å‚à‰Â
	vector<vector<Type>> dp(n + 1, vector<Type>(n + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
		}
	}
	return dp[n][k];
}

class UnionFind
{
private:
	vector<int> d;

public:
	UnionFind(int n = 0) :d(n, -1) {}

	int Find(int x)
	{
		if (d[x] < 0) return x;
		return d[x] = Find(d[x]);
	}

	bool Unite(int x, int y)
	{
		x = Find(x);
		y = Find(y);
		if (x == y) return false;
		if (d[y] < d[x]) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}

	bool Same(int x, int y) { return Find(x) == Find(y); }

	int Size(int x) { return -d[Find(x)]; }
};