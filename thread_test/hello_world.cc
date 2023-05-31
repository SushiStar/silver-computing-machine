#include <iostream>
#include <thread>

void do_something() {}
void do_simething_else() {}

// callable object
class background_task {
 public:
  // function call operator
  void operator()() const {
    do_something();
    do_simething_else();
  }
};

void hello() { std::cout << "Hello Concurrent World\n"; }

int main() {
  // background_task f;
  // std::thread my_thread(f);

  std::thread t(hello);
  t.join();  // This cause the main thread to wait for the thread t to finish
}
