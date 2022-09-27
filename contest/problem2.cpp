#include <bits/stdc++.h>

using namespace std;

int main()
{

  int letters[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};

  string s;
  int a, ant;
  while (cin >> s)
  {
    ant = 0;
    for (int i = 0; i < s.length(); i++)
    {
      a = letters[s[i] - 'A'];
      if (a && ant != a)
      {
        cout << a;
        ant = a;
      }

      if (!a)
        ant = 0;
    }

    cout << "\n";
  }

  return 0;
}