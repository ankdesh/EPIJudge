#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfK(const vector<int>& A, int k) {
  // TODO - you fill in here.

  int l = 0;
  int r = A.size() - 1;
  int found = -1;

  while (l <= r){
    int m = l + (r-l)/2;
    if (k < A[m]){
      r = m - 1;
    }
    else if (k > A[m]){
      l = m + 1;
    }
    else {
      found = m;
      break;
    }
  }

  if (found != -1){
    while (found > 0 && A[found] == A[found-1]){
      found--;
    }
    return found;
  }
  else {
    return -1;
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
