template <typename V, typename D>
vector<D> dijkstra(const vector<vector<pair<V, D>>>& g, const V s) {
	vector<D> d(size(g), numeric_limits<D>::max() / 2);
	d[s] = 0;
	priority_queue<pair<D, V>, vector<pair<D, V>>, greater<>> q;
	q.emplace(0, s);
	while (!q.empty()) {
		const auto [du, u] = q.top();
		q.pop();
		if (du > d[u]) continue;
		for (const auto [v, w] : g[u]) {
			const auto dv = du + w;
			if (dv >= d[v]) continue;
			d[v] = dv;
			q.emplace(dv, v);
		}
	}
	return d;
}
