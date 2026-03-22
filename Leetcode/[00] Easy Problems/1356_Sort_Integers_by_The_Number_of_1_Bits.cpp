/**
 * @file 1356_Sort_Integers_by_The_Number_of_1_Bits.cpp
 * @author Rut Koticha
 * @date 2026-02-25
 */

#include <vector>
#include <map>
#include <set>

class Solution {
private:
	size_t GetNoOf1Bits(int number)
	{
		size_t bits = 0;

		while (number)
		{
			bits += number & 1;
			number >>= 1;
		}

		return bits;
	}

public:
	std::vector<int> sortByBits(std::vector<int>& array)
	{
		std::map<int, std::multiset<int>> bitBuckets;
		for (int element : array)
		{
			size_t bits = GetNoOf1Bits(element);
			bitBuckets[bits].insert(element);
		}

		std::vector<int> sorted;
		for (auto [_, elements] : bitBuckets)
		{
			sorted.insert(sorted.end(), elements.begin(), elements.end());
		}

		return sorted;
	}
};
