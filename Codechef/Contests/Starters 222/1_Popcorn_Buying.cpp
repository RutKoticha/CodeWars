/**
 * @file 1_Popcorn_Buying.cpp
 * @author Rut Koticha
 * @date 2026-01-21
 */

#include <iostream>

int main(int argc, char* argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int money;
  std::cin >> money;

  int leftOverMoney = money - 100;
  int popcornBuckets = leftOverMoney / 50;

  std::cout << popcornBuckets << std::endl;

  return 0;
}
