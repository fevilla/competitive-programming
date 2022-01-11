#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int board[102][102];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, round = 0;
  char a;
  while (cin >> n >> m, n, m)
  {
    round++;
    if (round > 1)
      cout << endl;

    f(i, 1, n + 1)
    {
      f(j, 1, m + 1)
      {
        board[i][j] = 0;
      }
    }
    f(i, 1, n + 1)
    {
      f(j, 1, m + 1)
      {
        cin >> a;
        if (a == '*')
        {
          board[i][j] = -100;
          board[i - 1][j]++;
          board[i + 1][j]++;
          board[i][j + 1]++;
          board[i][j - 1]++;
          board[i - 1][j - 1]++;
          board[i + 1][j + 1]++;
          board[i - 1][j + 1]++;
          board[i + 1][j - 1]++;
        }
      }
    }
    cout << "Field #" << round << ":\n";
    f(i, 1, n + 1)
    {
      f(j, 1, m + 1)
      {
        if (board[i][j] < 0)
          cout << '*';
        else
          cout << board[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}