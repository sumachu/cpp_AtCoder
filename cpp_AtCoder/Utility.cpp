#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

// ŒJ‚è•Ô‚µ“ñæ–@
template<class Type>
Type ModPow(Type a, Type n, Type mod)
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

// Å‘åŒö–ñ”
template<class Type>
Type GCD(Type x, Type y)
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

// Å¬Œö”{”
template<class Type>
Type LCM(Type x, Type y)
{
	return x / GCD(x, y) * y;
}

// ‘f””»’è
template<class Type>
bool PrimeJudge(Type x)
{
	if (x == 2) return true;
	if (x < 2 || x % 2 == 0) return false;

	for (Type i = 3; i * i <= x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

// 10i”®”a‚ğni”•¶š—ñ‚Æ‚µ‚Äæ“¾
template<class Type>
string ToString(Type a, Type n)
{
	string s;
	while (a) {
		s = to_string(a % n) + s;
		a /= n;
	}
	return s;
}

// –ñ”—ñ‹“
vector<ll> EnumerateDivisors(ll n)
{
	vector<ll> divisors;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (n / i != i) divisors.push_back(n / i);
		}
	}
	sort(divisors.begin(), divisors.end());
	return divisors;
}