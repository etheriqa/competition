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

template <typename RealType>
RealType
binarySearch(RealType low,
             RealType high,
             std::function<bool(RealType)> f,
             size_t n = 100000) noexcept {
  bool found = false;
  RealType mid;
  for (size_t i = 0; i < n; i++) {
    mid = (low + high) / 2;
    if (f(mid)) {
      found = true;
      high = mid;
    } else {
      low = mid;
    }
  }
  return found ? mid : std::numeric_limits<RealType>::max();
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ld x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ld vmax, t;
  cin >> vmax >> t;
  ld vx, vy, wx, wy;
  cin >> vx >> vy >> wx >> wy;

  auto f = [&](ld s)->bool{
    const auto x = x2 - x1 - vx * min(t, s) - wx * max<ld>(0, s - t);
    const auto y = y2 - y1 - vy * min(t, s) - wy * max<ld>(0, s - t);
    return vmax * vmax * s * s >= x * x + y * y;
  };
  cout << setprecision(20)
    << min(binarySearch<ld>(0, t, f), binarySearch<ld>(t, sup<ld>(), f))
    << endl;

  return 0;
}
