#include "mean/types.hpp"

namespace mean {

handle next_handle() {
  static handle nextHandle = 0;
  return nextHandle++;
}

} // namespace mean
