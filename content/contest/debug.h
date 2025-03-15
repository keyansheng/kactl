#define debug(x) cerr << #x << " = " << x << endl

template <typename T, typename U>
ostream& operator<<(ostream& o, const pair<T, U>& p) {
	return o << '(' << p.first << ", " << p.second << ')';
}

template <typename T>
ostream& operator<<(ostream& o, const vector<T>& ts) {
	size_t i = 0;
	o << '[';
	for (const auto& t : ts) o << (i++ ? ", " : "") << t;
	return o << ']';
}
