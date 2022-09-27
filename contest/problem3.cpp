#include <bits/stdc++.h>
#define P 1000005

using namespace std;

bool cd[P];

int main()
{

  int N, M, x, cant;
  set<int> fab, carl;

  while (cin >> N >> M, N, M)
  {
    for (int i = 0; i < N; i++)
    {
      cin >> x;
      fab.insert(x);
    }

    for (int i = 0; i < M; i++)
    {
      cin >> x;
      carl.insert(x);
    }

    int ans = 0;
    if (carl.size() < fab.size())
    {
      for (auto it : carl)
      {
        if (fab.find(it) != fab.end())
          ans++;
      }
    }
    else
    {
      for (auto it : fab)
      {
        if (carl.find(it) != carl.end())
          ans++;
      }
    }

    carl.clear();
    fab.clear();

    cout << ans << endl;
  }
  return 0;
}