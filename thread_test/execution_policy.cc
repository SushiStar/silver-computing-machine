#include <algorithm>
#include <execution>
#include <iostream>
#include <thread>
#include <vector>

// Sample function to process an element
void processElement(int element) {
  // Simulate some time-consuming task
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "Processed element: " << element
            << " on thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Asynchronously process each element using std::for_each and
  // std::execution::par
  std::for_each(std::execution::par, elements.begin(), elements.end(),
                processElement);

  return 0;
}
