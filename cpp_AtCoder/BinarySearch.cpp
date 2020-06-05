#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

bool BinarySearchJudge(vector<int> a, int index, int key)
{
	if (key <= a[index]) return true;
	else return false;
}

int BinarySearch(vector<int> a, int key)
{
	int ng = -1;
	int ok = a.size();
	while (1 < abs(ng - ok)) {
		int mid = (ng + ok) / 2;
		if (BinarySearchJudge(a, mid, key)) ok = mid;
		else ng = mid;
	}
	return a[ok] == key;
}