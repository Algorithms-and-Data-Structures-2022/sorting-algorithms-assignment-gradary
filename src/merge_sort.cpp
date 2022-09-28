#include "assignment/merge_sort.hpp"

#include "assignment/partitioning.hpp"  // middle_of
#include "assignment/merging.hpp"       // merge

namespace assignment {

  void MergeSort::Sort(std::vector<int>& arr) const {

    // буфер памяти для операции слияния (merge)
    std::vector<int> buf(arr.size());

    merge_sort(arr, 0, static_cast<int>(arr.size()) - 1, buf);
  }

  void MergeSort::merge_sort(std::vector<int>& arr, int start, int stop, std::vector<int>& buf) const {

    // выход из рекурсии: подмассив длины один
    if (start >= stop) {
      return;
    }

    // вычисляем индекс середины области
    const int mid = middle_of(start, stop);

    //. рекурсивный вызов сортировки левой [start, middle] и правой [middle + 1, stop] подмассивов ...
    //    // слияния двух подмассивов [start, middle] и [middle + 1, stop] ..
    merge_sort(arr, start, mid, buf);
    merge_sort(arr, mid + 1, stop, buf);
    merge(arr, start, mid, stop, buf);
  }

}  // namespace assignment