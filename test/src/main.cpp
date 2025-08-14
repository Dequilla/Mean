#include <cassert>
#include <iostream>

#include <mean/mean.hpp>

int main(int argc, char **argv) {
  std::cout << "Hello mean!" << std::endl;

  for (int i = 0; i < 100000; i++) {
    assert(mean::next_handle() == i);
  }

  return 0;
}
