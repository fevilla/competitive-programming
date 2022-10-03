#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

const int N = 72;
using namespace std;

char s[N];
int chess[11][11], fin = 10, ini = 2;
int parse[11][11];

void col(int i, int j)
{
  int a = i, b = j;
  while (chess[--i][j] <= 0 && i >= ini)
    parse[i][j] = -1;
  while (chess[++a][b] <= 0 && a < fin)
    parse[a][b] = -1;
}

void fil(int i, int j)
{
  int a = i, b = j;
  while (chess[i][--j] <= 0 && j >= ini)
    parse[i][j] = -1;
  while (chess[a][++b] <= 0 && b < fin)
    parse[a][b] = -1;
}

void diagonally(int i, int j)
{
  int a = i, b = j;
  while (--j >= ini && --i >= ini && chess[i][j] <= 0)
    parse[i][j] = -1;

  i = a, j = b;
  while (++j < fin && ++i < fin && chess[i][j] <= 0)
    parse[i][j] = -1;

  i = a, j = b;
  while (++j < fin && --i >= ini && chess[i][j] <= 0)
    parse[i][j] = -1;

  i = a, j = b;
  while (--j >= ini && ++i < fin && chess[i][j] <= 0)
    parse[i][j] = -1;
}
void l(int i, int j)
{
  parse[i + 2][j + 1] = -1;
  parse[i + 2][j - 1] = -1;
  parse[i - 2][j + 1] = -1;
  parse[i - 2][j - 1] = -1;

  parse[i + 1][j + 2] = -1;
  parse[i + 1][j - 2] = -1;
  parse[i - 1][j + 2] = -1;
  parse[i - 1][j - 2] = -1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (cin >> s)
  {

    int n = strlen(s);
    int ix = ini, ij = ini;

    f(i, 0, 11)
    {
      f(j, 0, 11)
      {
        chess[i][j] = 0;
        parse[i][j] = 0;
      }
    }

    f(i, 0, n)
    {
      if (s[i] >= 48 && s[i] <= 57)
        ix += s[i] - '0';
      else if (s[i] == '/')
      {
        ij++;
        ix = ini;
      }
      else
      {
        if (s[i] != 'p' && s[i] != 'P')
          s[i] = tolower(s[i]);
        chess[ij][ix] = s[i];
        ix++;
      }
    }

    f(i, ini, fin)
    {
      f(j, ini, fin)
      {
        if (chess[i][j] != 0)
        {
          char op = chess[i][j];
          parse[i][j] = -1;

          if (op)
          {
            if (op == 'r')
            {
              col(i, j);
              fil(i, j);
            }
            else if (op == 'n')
            {
              l(i, j);
            }
            else if (op == 'b')
            {
              diagonally(i, j);
            }
            else if (op == 'q')
            {
              col(i, j);
              diagonally(i, j);
              fil(i, j);
            }
            else if (op == 'k')
            {
              parse[i][j + 1] = -1;
              parse[i][j - 1] = -1;
              parse[i + 1][j] = -1;
              parse[i - 1][j] = -1;
              parse[i + 1][j - 1] = -1;
              parse[i + 1][j + 1] = -1;
              parse[i - 1][j - 1] = -1;
              parse[i - 1][j + 1] = -1;
            }
            else if (op == 'p')
            {
              parse[i + 1][j + 1] = -1;
              parse[i + 1][j - 1] = -1;
            }
            else
            {
              parse[i - 1][j + 1] = -1;
              parse[i - 1][j - 1] = -1;
            }
          }
        }
      }
    }

    int cont = 0;

    f(i, ini, fin)
        f(j, ini, fin) if (!parse[i][j]) cont++;
    cout << cont << "\n";
  }

  return 0;
}