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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  bitset<1000021> ws;
  rep(i,n) {
    int w;
    cin >> w;
    while (ws[w]) {
      ws[w] = false;
      w++;
    }
    ws[w] = true;
  }
  cout << ws.count() << endl;

  return 0;
}
