#include <vector>
#include "test_framework/generic_test.h"
#include <iostream>

using std::vector;

int SearchSmallest(const vector<int>& A) {
  // TODO - you fill in here.

  int l = 0;
  int r = A.size() - 1;

  if (A[0] < A[A.size() - 1]){
    return 0;
  }
  

  while (l <= r){
    int mid = (l + r) / 2 ;

    //std::cout << l << " " << mid << " " << r << std::endl;
    //std::cout << A[l] << " " << A[mid] << " " << A[r] << std::endl;

    if (mid == A.size() - 1){
      return mid;
    }

    if (mid > 0 && (mid < A.size() -1) && (A[mid-1] > A[mid]) && (A[mid+1] > A[mid])){
      //std::cout << "Here: " << mid << std::endl;
      return mid;
    }
    else if (A[mid] < A[0]){ // Its on the right side of point of discountinuty
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "search_shifted_sorted_array.cc",
                         "search_shifted_sorted_array.tsv", &SearchSmallest,
                         DefaultComparator{}, param_names);

  //SearchSmallest({100, 101, 102, 2 ,5});
}
