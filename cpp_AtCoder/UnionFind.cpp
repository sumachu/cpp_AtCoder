#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

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