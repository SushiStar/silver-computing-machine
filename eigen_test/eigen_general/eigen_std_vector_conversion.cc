#include <Eigen/Dense>
#include <iostream>
#include <vector>

int main() {
  std::vector<double> v = {1, 2, 3, 4, 5};
  // convert std::vector to Eigen::VectorXd
  Eigen::VectorXd e = Eigen::Map<Eigen::VectorXd>(v.data(), v.size());

  std::cout << e << std::endl;
  return 0;
}
