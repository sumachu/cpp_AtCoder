#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

class Mint
{
private:
    ll x;
public:
    Mint(ll x = 0) :x((x% mod + mod) % mod) {}
    ll get() const { return x; }
    Mint operator-() const { return Mint(-x); }
    Mint& operator+=(const Mint a)
    {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    Mint& operator-=(const Mint a)
    {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    Mint& operator*=(const Mint a) { (x *= a.x) %= mod; return *this; }
    Mint operator+(const Mint a) const { return Mint(*this) += a; }
    Mint operator-(const Mint a) const { return Mint(*this) -= a; }
    Mint operator*(const Mint a) const { return Mint(*this) *= a; }
    Mint pow(ll t) const
    {
        if (!t) return 1;
        Mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    Mint inv() const { return pow(mod - 2); }
    Mint& operator/=(const Mint a) { return *this *= a.inv(); }
    Mint operator/(const Mint a) const { return Mint(*this) /= a; }
};
ostream& operator<<(ostream& os, const Mint& a) { return os << a.get(); }

class Combination
{
	//  1 <= k <= n <= 1e7Amod‚Í‘f”
public:
	vector<Mint> fact, ifact;
private:
	Combination(int n) :fact(n + 1), ifact(n + 1)
	{
		assert(n < mod);
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
		ifact[n] = fact[n].inv();
		for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
	}
	Mint operator()(int n, int k)
	{
		if (k < 0 || k > n) return 0;
		return fact[n] * ifact[k] * ifact[n - k];
	}
};

template<class Type>
Mint inv_nCk(Type n, Type k)
{
	//  1<= n <= 1e9 (n‚ÍŒÅ’è’l), 1 <= k <= 1e7
	Mint x = 1, y = 1;
	for (Type i = 0; i < k; i++) {
		x *= n - i;
		y *= i + 1;
	}
	return x / y;
}

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