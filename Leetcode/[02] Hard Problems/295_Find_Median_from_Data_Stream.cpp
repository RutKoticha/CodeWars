/**
 * @file 295_Find_Median_from_Data_Stream.cpp
 * @author Rut Koticha
 * @date 2025-10-30
 */

#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

class MedianFinder {
private:
  std::priority_queue<int, std::vector<int>, std::less<int>> m_SmallHeap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> m_LargeHeap;

public:
  MedianFinder();
  void addNum(int num);
  double findMedian();
};

MedianFinder::MedianFinder() { /* Initialize the finder object */ }

void MedianFinder::addNum(int number)
{
  m_SmallHeap.push(number);

  if (!m_LargeHeap.empty() && m_SmallHeap.top() > m_LargeHeap.top())
  {
    m_LargeHeap.push(m_SmallHeap.top());
    m_SmallHeap.pop();
  }

  if (m_SmallHeap.size() > m_LargeHeap.size() + 1)
  {
    m_LargeHeap.push(m_SmallHeap.top());
    m_SmallHeap.pop();
  }

  if (m_LargeHeap.size() > m_SmallHeap.size() + 1)
  {
    m_SmallHeap.push(m_LargeHeap.top());
    m_LargeHeap.pop();
  }
}

double MedianFinder::findMedian()
{
  // Return median of all elements so far
  if (m_SmallHeap.size() == m_LargeHeap.size())
    return (m_LargeHeap.top() + m_SmallHeap.top()) / 2.0;
  else if (m_SmallHeap.size() > m_LargeHeap.size())
    return m_SmallHeap.top();
  else
    return m_LargeHeap.top();
}
