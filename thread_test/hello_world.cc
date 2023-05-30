#include <iostream>
#include <thread>

void hello() { std::cout << "Hello Concurrent World\n"; }

int main() {
  std::thread t(hello);
  t.join();  // This cause the main thread to wait for the thread t to finish
}
