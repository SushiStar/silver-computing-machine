#include <vector>

namespace SomeSpace {

// when saying unused function RandomVector, linker means that this function is
// not used in the current translation unit.
static std::vector<int> RandomVector() { return {1, 2, 3, 4, 5}; }

}  // namespace SomeSpace
