#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint;
const int mod = 1000000007;
const double PI = acos(-1);

class Edge
{
private:
	int v; // ���_
	ll w; // �d��
public:
	Edge(int vertex, int weight) :v(vertex), w(weight) {}
	int vertex() { return v; }
	int weight() { return w; }
};

// �e���_�ɗאڂ��钸�_�Əd�݂̔z����i�[����z��
using Glaph = vector<vector<Edge>>;

int main()
{
	// �o�T�FALDS1_12_C�i�P��n�_�ŒZ�o�H II�j
	// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_12_C
	int n;
	cin >> n;
	Glaph glaph(n);
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			int v, c;
			cin >> v >> c;
			glaph[u].push_back(Edge(v, c));
		}
	}

	// �T���J�n���_
	int s = 0;
	// �T���J�n���_����e���_�܂ł̋������i�[����z��
	// �T���I����͒T���J�n���_����e���_�܂ł̍ŏ��������i�[����z��
	vector<ll> dist(n, LLONG_MAX);
	dist[s] = 0;
	// (dist[vertex], vertex) �̃y�A��v�f�Ƃ����D��x�t���L���[
	// dist[vertex]�����������Ɏ��o�����
	priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push(make_pair(dist[s], s));

	while (!pq.empty()) {
		// �g�p�ς݂łȂ����_�̂���dist[v]���ŏ��̒��_
		int v = pq.top().second;
		// v�ɑ΂���L�[�̒l
		ll d = pq.top().first;
		pq.pop();
		// d < dist[v]�́A(dist[v], v) ���S�~�ł��邱�Ƃ��Ӗ�����
		// �S�~�͖�������̂ŁA���̏����ɐi�܂Ȃ�
		if (d < dist[v]) continue;
		// ���_v���n�_�Ƃ����e�ӂ��ɘa
		for (auto& edge : glaph[v]) {
			// �ŏ������̍X�V������ꍇ
			if (dist[v] + edge.weight() < dist[edge.vertex()]) {
				// �ŏ��������X�V
				dist[edge.vertex()] = dist[v] + edge.weight();
				// (dist[vertex], vertex) �̃y�A��pq�ɑ}��
				pq.push(make_pair(dist[edge.vertex()], edge.vertex()));
			}
		}
	}

	for (int i = 0; i < n; i++) cout << i << " " << dist[i] << endl;
}