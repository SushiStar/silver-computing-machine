#include <iostream>
#include <string>

class foo {
 public:
  foo() : my_string_("hello") {}
  const std::string& my_string() const { return my_string_; }

 private:
  std::string my_string_;
};

int main() {
  foo f;
  std::cout << f.my_string() << std::endl;

  std::string r = f.my_string();
  r.append(" world");

  std::cout << r << std::endl;
  std::cout << f.my_string() << std::endl;

  return 0;
}
