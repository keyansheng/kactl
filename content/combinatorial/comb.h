#include "../number-theory/ModPow.h"

struct Comb {
	vector<ll> fact, finv;
	explicit Comb(const ll n) : fact(n + 1, 1), finv(n + 1, 1) {
		for (ll i = 2; i <= n; ++i) fact[i] = fact[i - 1] * i % mod;
		finv[n] = modpow(fact[n], mod - 2);
		for (ll i = n; i >= 2; --i) finv[i - 1] = finv[i] * i % mod;
	}
	[[nodiscard]] ll P(const ll n, const ll r) const {
		if (r < 0 || n < r || n < 0) return 0;
		return fact[n] * finv[n - r] % mod;
	}
	[[nodiscard]] ll C(const ll n, const ll r) const {
		return P(n, r) * finv[r] % mod;
	}
};
