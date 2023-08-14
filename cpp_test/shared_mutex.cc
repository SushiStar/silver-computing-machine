#include <future>
#include <iostream>
#include <mutex>
#include <shared_mutex>

class SharedObject {
 private:
  int data_ = 0;
  std::shared_mutex mutex;

 public:
  void ReadData() {
    std::shared_lock<std::shared_mutex> lock(mutex);
    std::cout << "data is: " << data_ << std::endl;
  }

  void WriteData(int val) {
    std::unique_lock<std::shared_mutex> lock(mutex);
    data_ = val;
  }
};

int main() {
  SharedObject obj;
  std::async(&SharedObject::ReadData, &obj);
  std::async(&SharedObject::WriteData, &obj, 42);
  std::async(&SharedObject::ReadData, &obj);
  std::async(&SharedObject::WriteData, &obj, 43);
  std::async(&SharedObject::ReadData, &obj);
  return 0;
}
