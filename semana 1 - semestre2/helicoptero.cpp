#include <iostream>

using namespace std;

int main()
{
  // Lendo a entrada do exercício
  int F, H, P, D;

  cin >> H >> P >> F >> D;

  while (F != H && F != P)
  {
    F = F + D;
    if (F < 0)
    {
      F = 15;
    }
    if (F > 15)
    {
      F = 0;
    }
  }

  if (F == H)
  {
    cout << "S" << endl;
  }
  else
  {
    cout << "N" << endl;
  }
  return 0;
}