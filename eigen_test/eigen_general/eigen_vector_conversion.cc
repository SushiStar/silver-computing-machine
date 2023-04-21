#include <Eigen/Dense>
#include <iostream>

void foo(const Eigen::VectorXd& v) { std::cout << "foo\n" << v << std::endl; }

int main() {
  Eigen::RowVectorXd rv(3);
  rv << 1, 2, 3;

  foo(rv);
  return 0;
}
