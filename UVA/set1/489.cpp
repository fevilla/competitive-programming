#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)
#define N 26
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a;
  string s;
  bool poo[N];
  bool frec[N];
  set<char> err;
  while (cin >> a, a != -1)
  {
    cin >> s;
    int cant = 0, canr = 0;

    f(i, 0, N)
    {
      frec[i] = 0;
      poo[i] = 0;
    }

    err.clear();

    f(i, 0, s.length())
    {
      if (!poo[s[i] - 'a'])
      {
        poo[s[i] - 'a'] = 1;
        canr++;
      }
    }

    cin >> s;
    bool band = false, ok = false;
    f(i, 0, s.length())
    {
      if (poo[s[i] - 'a'] && !frec[s[i] - 'a'])
      {
        cant++;
        if (cant == canr)
        {
          ok = true;
          break;
        }

        frec[s[i] - 'a'] = 1;
      }

      if (!poo[s[i] - 'a'])
      {
        err.insert(s[i]);
        if (err.size() == 7)
        {
          band = true;
          break;
        }
      }
    }

    cout << "Round " << a << "\n";
    if (band)
      cout << "You lose.\n";
    else if (ok)
      cout << "You win.\n";
    else
      cout << "You chickened out.\n";
  }
  return 0;
}
