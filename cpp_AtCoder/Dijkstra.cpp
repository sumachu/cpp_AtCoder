#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
	ll weight() { return w; }
};

// �e���_�ɗאڂ��钸�_�Əd�݂̔z����i�[����z��
using Glaph = vector<vector<Edge>>;

//int main()
//{
//	// �o�T�F�T�^�A���S���Y�����W D-�P��n�_�ŒZ�o�H���
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
//	// �T���J�n���_
//	int s = 0;
//	// �T���J�n���_����e���_�܂ł̋������i�[����z��
//	// �T���I����͒T���J�n���_����e���_�܂ł̍ŏ��������i�[����z��
//	vector<ll> dist(n, LLONG_MAX);
//	dist[s] = 0;
//	// (dist[vertex], vertex) �̃y�A��v�f�Ƃ����D��x�t���L���[
//	// dist[vertex]�����������Ɏ��o�����
//	priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
//	pq.push(make_pair(dist[s], s));
//
//	while (!pq.empty()) {
//		// �g�p�ς݂łȂ����_�̂���dist[v]���ŏ��̒��_
//		int v = pq.top().second;
//		// v�ɑ΂���L�[�̒l
//		ll d = pq.top().first;
//		pq.pop();
//		// d < dist[v]�́A(dist[v], v) ���S�~�ł��邱�Ƃ��Ӗ�����
//		// �S�~�͖�������̂ŁA���̏����ɐi�܂Ȃ�
//		if (d < dist[v]) continue;
//		// ���_v���n�_�Ƃ����e�ӂ��ɘa
//		for (auto& edge : glaph[v]) {
//			// �ŏ������̍X�V������ꍇ
//			if (dist[v] + edge.weight() < dist[edge.vertex()]) {
//				// �ŏ��������X�V
//				dist[edge.vertex()] = dist[v] + edge.weight();
//				// (dist[vertex], vertex) �̃y�A��pq�ɑ}��
//				pq.push(make_pair(dist[edge.vertex()], edge.vertex()));
//			}
//		}
//	}
//
//	cout << dist[n - 1] << endl;
//}