//
// Created by Peter Sims on 11/14/24.
//

#include <iostream>
#include <print>


int main() {
  double y{1.1};
  double z{1.2};
  double w{1.0};

  auto expression = (y + (2 * z++)) < (3 - (w / 5));

  return 0;
}