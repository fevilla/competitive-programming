#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int main()
{
  int n, cases, a;
  cin >> cases;
  f(i, 0, cases)
  {
    cin >> n;
    int ans = 0;
    f(i, 0, n)
    {
      cin >> a;
      ans = max(a, ans);
    }
    cout << "Case " << i + 1 << ": " << ans << "\n";
  }

  return 0;
}