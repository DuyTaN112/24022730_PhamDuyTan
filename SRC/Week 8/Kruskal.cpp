#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, w;
};

int n, m;
int parent[100], sz[100];
vector<edge> canh;

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edge e{x, y, w };
		canh.push_back(e);
	}
}

void makeSet() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

bool comp(edge a, edge b) {
	return a.w < b.w;
}
 
void kruskal() {
	vector<edge> mst;
	int d = 0;
	sort(canh.begin(), canh.end(), comp);
	for (int i = 0; i < m; i++) {
		if (mst.size() == n - 1) break;
		edge e = canh[i];
		if (unite(e.u, e.v)) {
			mst.push_back(e);
			d += e.w;
		}
	}
	if (mst.size() != n - 1) {
		cout << "Do thi ko lien thong\n";
	}
	cout << "kich thuoc mst: " << d << endl;
}

int main() {
	input();
	makeSet();
	kruskal();
}