#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint;
const int mod = 1000000007;
const double PI = acos(-1);

class Sieve
{
private:
	int n;
	vector<int> f, primes;
public:
	Sieve(int n = 1) :n(n), f(n + 1)
	{
		f[0] = f[1] = -1;
		for (ll i = 2; i <= n; ++i) {
			if (f[i]) continue;
			primes.push_back(i);
			f[i] = i;
			for (ll j = i * i; j <= n; j += i) {
				if (!f[j]) f[j] = i;
			}
		}
	}
	bool IsPrime(int x) { return f[x] == x; }
	vector<int> PrimeList(int x)
	{
		vector<int> res;
		while (x != 1) {
			res.push_back(f[x]);
			x /= f[x];
		}
		return res;
	}
	vector<pair<ll, int>> PrimeFrequency(int x)
	{
		vector<int> fl = PrimeList(x);
		if (fl.size() == 0) return {};
		vector<pair<ll, int>> res(1, pair<ll, int>(fl[0], 0));
		for (int p : fl) {
			if (res.back().first == p) {
				res.back().second++;
			} else {
				res.emplace_back(p, 1);
			}
		}
		return res;
	}
	vector<pair<ll, int>> PrimeFrequencySelf(ll x)
	{
		vector<pair<ll, int>> res;
		for (int p : primes) {
			int y = 0;
			while (x % p == 0) x /= p, ++y;
			if (y != 0) res.emplace_back(p, y);
		}
		if (x != 1) res.emplace_back(x, 1);
		return res;
	}
};

int main()
{
	int n;
	cin >> n;
	Sieve s(n);
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		vector<pair<ll, int>> pf = s.PrimeFrequency(i);
		for (const auto& item : pf) {
			v[item.first] += item.second;
			v[item.first] %= mod;
		}
	}
	ll ans = 1;
	for (const auto& item : v) {
		if (item) {
			ans *= (item + 1);
			ans %= mod;
		}
	}
	cout << ans << endl;
}