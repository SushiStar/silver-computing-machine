#include <iostream>
#include <vector>

#include "Eigen/Dense"
#include "unsupported/Eigen/Splines"

// Task 1: eigen spline module, spline fitting usage example exploration
namespace spline {

void test() {
  Eigen::MatrixXd points(2, 10);
  for (int i = 0; i < points.cols(); ++i) {
    points(0, i) = i;
    points(1, i) = i;
  }
  auto sp = Eigen::SplineFitting<Eigen::Spline2d>::Interpolate(points, 1);

  double x_left{0}, x_right{9};
  // double y_left{0}, y_right{9};

  double x_mid = 7.2;
  double y_mid = sp.derivatives((x_mid - x_left) / (x_right - x_left), 0)(0);
  printf("y_mid is: %.3f\n", y_mid);
}

}  // namespace spline

int main() {
  spline::test();
  return 0;
}
