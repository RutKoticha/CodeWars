/**
 * @file B_Bobritto_Bandito.cpp
 * @author Rut Koticha
 * @date 2026-01-11
 */

#include <iostream>

void Solve()
{
  int n = 0, m = 0, l = 0, r = 0, _l = 0, _r = 0;
  std::cin >> n >> m >> l >> r;

  while (m--)
  {
    if (_l > l)
      _l--;
    else
      _r++;
  }

  std::cout << _l << " " << _r << std::endl;
}

int main(int argc, char* argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tests{};
  std::cin >> tests;

  while (tests--)
    Solve();

  return 0;
}
