#include <Eigen/Dense>
#include <iostream>
#include <vector>

namespace Eigen {
template <class T>
void swap(T&& a, T&& b) {
  a.swap(b);
}
}  // namespace Eigen

/*
 * int main() {
 *   Eigen::Matrix2Xd m(2, 10);
 *   for (int i = 0; i < m.cols(); i++) {
 *     m(0, i) = i;
 *     m(1, i) = -i;
 *   }
 *
 *   Eigen::swap(m.col(3), m.col(7));
 *   std::sort(m.colwise().begin(), m.colwise().end(),
 *             [](const Eigen::VectorXd& a, const Eigen::VectorXd& b) {
 *               return a(0) < b(0);
 *             });
 *
 *   std::cout << m.row(0) << std::endl;
 *   std::cout << m.row(1) << std::endl;
 *
 *   return 0;
 * }
 */

/*
 * void printv(const Eigen::VectorXd& v) {
 *   for (int i = 0; i < v.size(); i++) {
 *     std::cout << v[i] << " ";
 *   }
 *   std::cout << std::endl;
 * }
 *
 * void printv(const Eigen::RowVectorXd& v) {
 *   for (int i = 0; i < v.size(); i++) {
 *     std::cout << v[i] << " ";
 *   }
 *   std::cout << std::endl;
 * }
 *
 * // test RowVector access
 * int main() {
 *   Eigen::VectorXd v1(3);
 *   v1 << 1, 2, 3;
 *
 *   Eigen::RowVectorXd v2(3);
 *   v2 << 1, 2, 3.3;
 *
 *   printv(v1);
 *   printv(v2);
 *
 *   return 0;
 * }
 */

void converter(const Eigen::MatrixXd& from,
               std::vector<std::vector<double>>& to) {
  for (int i = 0; i < from.rows(); i++) {
    for (int j = 0; j < from.cols(); j++) {
      to[i][j] = from(i, j);
    }
  }
}

void printv(const std::vector<std::vector<double>>& v) {
  for (std::size_t i = 0; i < v.size(); i++) {
    for (std::size_t j = 0; j < v[i].size(); j++) {
      std::cout << v[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  Eigen::MatrixXd m(3, 3);
  m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
  std::vector<std::vector<double>> v(3, std::vector<double>(3, 0));

  printf("before:\n");
  printv(v);

  converter(m, v);
  printf("after:\n");
  printv(v);

  Eigen::VectorXd v1(3);
  v1 << 1, 2, 3;
  std::vector<std::vector<double>> v2(1, std::vector<double>(3, 0));

  printf("before:\n");
  printv(v2);

  converter(v1, v2);
  printf("after:\n");
  printv(v2);

  return 0;
}
