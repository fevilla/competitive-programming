// Problema rais por medio de una pila , nos damos cuenta que el problema de los numeros , algunos deben estar en forma descendiente y otros ascendente
#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int n;

int main()
{

  int cant, a, actTam = 1;
  while (cin >> n, n)
  {
    while (true)
    {
      actTam = 1;
      cin >> a;
      if (!a)
      {
        cout << endl;
        break;
      }

      stack<int> A;
      for (int i = 1; i <= n; i++)
      {
        if (a >= actTam)
        {
          while (a > actTam)
          {
            A.push(actTam);
            actTam++;
          }
          actTam++;
        }
        else
        {
          if (!A.empty() && A.top() == a)
            A.pop();
        }
        if (i != n)
          cin >> a;
      }
      if (A.empty())
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}