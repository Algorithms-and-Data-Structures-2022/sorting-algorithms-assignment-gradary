#include "assignment/quick_sort.hpp"

#include <cassert>  // assert

#include "assignment/partitioning.hpp"  // partition, median_of_three

namespace assignment {

  void QuickSort::Sort(std::vector<int>& arr) const {
    quick_sort(arr, 0, static_cast<int>(arr.size()) - 1);
  }

  void QuickSort::quick_sort(std::vector<int>& arr, int start, int stop) const {
    assert(start >= 0);

    if (start >= stop) {
      return;
    }

    // вычисляем индекс опорного элемента ... median_of_three ...
    int mid = median_of_three(arr, start, stop);
    // производим разбиение относительно опорного элемента ...  partition ...
    int pivo_index = partition(arr, start, stop, mid);
    // рекурсивно повторяем процедуру над левой и правой частью ...
    quick_sort(arr, start, pivo_index - 1);
    quick_sort(arr, pivo_index + 1, stop);
  }

}  // namespace assignment