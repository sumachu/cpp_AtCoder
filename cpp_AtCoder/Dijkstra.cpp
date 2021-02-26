#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

class Edge
{
private:
	int v; // 頂点
	ll w; // 重み
public:
	Edge(int vertex, int weight) :v(vertex), w(weight) {}
	int vertex() { return v; }
	ll weight() { return w; }
};

// 各頂点に隣接する頂点と重みの配列を格納する配列
using Glaph = vector<vector<Edge>>;

//int main()
//{
//	// 出典：典型アルゴリズム問題集 D-単一始点最短経路問題
//	// https://atcoder.jp/contests/typical-algorithm/tasks/typical_algorithm_d
//	int n, m;
//	cin >> n >> m;
//	Glaph glaph(n);
//	for (int i = 0; i < m; i++) {
//		int v, u;
//		ll c;
//		cin >> v >> u >> c;
//		glaph[v].push_back(Edge(u, c));
//	}
//
//	// 探索開始頂点
//	int s = 0;
//	// 探索開始頂点から各頂点までの距離を格納する配列
//	// 探索終了後は探索開始頂点から各頂点までの最小距離を格納する配列
//	vector<ll> dist(n, LLONG_MAX);
//	dist[s] = 0;
//	// (dist[vertex], vertex) のペアを要素とした優先度付きキュー
//	// dist[vertex]が小さい順に取り出される
//	priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
//	pq.push(make_pair(dist[s], s));
//
//	while (!pq.empty()) {
//		// 使用済みでない頂点のうちdist[v]が最小の頂点
//		int v = pq.top().second;
//		// vに対するキーの値
//		ll d = pq.top().first;
//		pq.pop();
//		// d < dist[v]は、(dist[v], v) がゴミであることを意味する
//		// ゴミは無視するので、次の処理に進まない
//		if (d < dist[v]) continue;
//		// 頂点vを始点とした各辺を緩和
//		for (auto& edge : glaph[v]) {
//			// 最小距離の更新がある場合
//			if (dist[v] + edge.weight() < dist[edge.vertex()]) {
//				// 最小距離を更新
//				dist[edge.vertex()] = dist[v] + edge.weight();
//				// (dist[vertex], vertex) のペアをpqに挿入
//				pq.push(make_pair(dist[edge.vertex()], edge.vertex()));
//			}
//		}
//	}
//
//	cout << dist[n - 1] << endl;
//}