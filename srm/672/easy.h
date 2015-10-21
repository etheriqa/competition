#if defined(__GNUG__) && !defined(__clang__)
#include <bits/stdc++.h>
#endif

#define rep(i,n) for (size_t i = 0; i < (n); i++)
#define each(e,c) for (auto& e : c)
using namespace std;
using ll = long long;
using ld = long double;
template <class T> T inf() { return numeric_limits<T>::lowest(); }
template <class T> T sup() { return numeric_limits<T>::max(); }
template <class T> T& up(T& d, T s) { return d = max(d, s); }
template <class T> T& down(T& d, T s) { return d = min(d, s); }
template <class Key> using uset = unordered_set<Key>;
template <class Key, class T> using umap = unordered_map<Key, T>;

class Procrastination {
public:
  long long findFinalAssignee(long long n);
};

template <typename Integral, typename Container = std::vector<Integral>>
Container
divisor(Integral n) {
  Container divisors({1, n});
  for (Integral i = 2; i <= std::sqrt(n); i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      divisors.push_back(n / i);
    }
  }
  std::sort(divisors.begin(), divisors.end());
  divisors.erase(std::unique(divisors.begin(), divisors.end()), divisors.end());
  return divisors;
}

long long Procrastination::findFinalAssignee(long long n) {
  umap<ll, vector<ll>> divisors;
  ll hour = 2;
  for (;;) {
    if (divisors.count(n) == 0) divisors[n] = divisor(n);
    if (divisors.count(n-1) == 0) divisors[n-1] = divisor(n-1);
    const auto it0 = lower_bound(divisors[n].begin(), divisors[n].end(), hour);
    const auto it1 = lower_bound(divisors[n-1].begin(), divisors[n-1].end(), hour);
    const ll h0 = it0 != divisors[n].end() ? *it0 : 1e11;
    const ll h1 = it1 != divisors[n-1].end() ? *it1 : 1e11;
    hour = min(h0, h1);
    if (n < hour * 2) return n;
    switch (n % hour) {
    case 0:
      n++;
      break;
    case 1:
      n--;
      break;
    }
    hour++;
  }
  return n;
}
