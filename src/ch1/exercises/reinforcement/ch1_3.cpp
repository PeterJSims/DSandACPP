//
// Created by Peter Sims on 11/14/24.
//

#include <iostream>
#include <print>


std::pair<int, int> smallest_largest(const int* arr, const size_t size) {
  int smallest{arr[0]};
  int largest{arr[0]};

  for (int i{1}; i < size; ++i) {
    if(arr[i] > largest){largest = arr[i];}
    if(arr[i] < smallest){smallest = arr[i];}
  }
  return std::pair{smallest, largest};

}

int main() {
  const int arr[]{3, 1, -32, 99, 100};

  auto [smallest, largest]{smallest_largest(arr, std::size(arr))};
  std::println("{} {}", smallest, largest);

  return 0;
}