#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll N, M, x, ans;
  set<ll> CD;
  while (cin >> N >> M, N, M)
  {
    for (int i = 0; i < N; i++)
    {
      cin >> x;
      CD.insert(x);
    }

    ans = 0;
    for (int i = 0; i < M; i++)
    {
      cin >> x;
      if (CD.find(x) != CD.end())
        ans++;
    }

    cout << ans << endl;
    CD.clear();
  }
  return 0;
}