#include <iostream>
#include <vector>

#include "Eigen/Dense"
#include "unsupported/Eigen/Splines"

// Task 1: eigen spline module, spline fitting usage example exploration
namespace spline {

Eigen::Matrix2Xd generateSegments() {
  Eigen::Matrix2Xd segments(2, 7);
  segments(0, 0) = 0.0;
  segments(1, 0) = 0.0;

  segments(0, 1) = 1.0;
  segments(1, 1) = 2.0;

  segments(0, 2) = 2.0;
  segments(1, 2) = 0.0;

  segments(0, 3) = 3.0;
  segments(1, 3) = -2.0;

  segments(0, 4) = 4.0;
  segments(1, 4) = 0.0;

  segments(0, 5) = 5.0;
  segments(1, 5) = 2.0;

  segments(0, 6) = 6.0;
  segments(1, 6) = 0.0;

  return segments;
}

double computeRatio(double u, double left, double right) {
  return (u - left) / (right - left);
}

void test1() {
  Eigen::MatrixXd points{generateSegments()};

  auto sp = Eigen::SplineFitting<Eigen::Spline2d>::Interpolate(points, 1);

  double x_left{0}, x_right{6};

  // printf("%.3f\n", computeRatio(0.53, x_left, x_right));

  // std::cout << sp(computeRatio(0.53, x_left, x_right)).coeff(0) << std::endl;
  std::cout << sp.derivatives(computeRatio(0.53, x_left, x_right), 0)(0)
            << std::endl;

  // printf("%.3f %.3f\n", 0.53,
  // sp.derivatives(computeRatio(0.53, x_left, x_right), 1)(0));
  assert(std::abs(sp.derivatives(computeRatio(0.53, x_left, x_right), 0)(0) -
                  1.06) < 1e-8);

  assert(std::abs(sp.derivatives(computeRatio(1.0, x_left, x_right), 0)(0) -
                  2.0) < 1e-8);

  assert(std::abs(sp.derivatives(computeRatio(1.1, x_left, x_right), 0)(0) -
                  1.8) < 1e-8);

  assert(std::abs(sp.derivatives(computeRatio(1.5, x_left, x_right), 0)(0) -
                  1.0) < 1e-8);

  assert(std::abs(sp.derivatives(computeRatio(3.0, x_left, x_right), 0)(0) -
                  -2.0) < 1e-8);

  assert(std::abs(sp.derivatives(computeRatio(3.5, x_left, x_right), 0)(0) -
                  -1.0) < 1e-8);

  assert(std::abs(sp.derivatives(computeRatio(4.2, x_left, x_right), 0)(0) -
                  0.4) < 1e-8);

  assert(std::abs(sp.derivatives(computeRatio(5.7, x_left, x_right), 0)(0) -
                  0.6) < 1e-8);
}

class SplineFunction {
 public:
  SplineFunction(Eigen::VectorXd const &x_vec, Eigen::VectorXd const &y_vec)
      : x_min(x_vec.minCoeff()),
        x_max(x_vec.maxCoeff()),
        // Spline fitting here. X values are scaled down to [0, 1] for this.
        spline_(Eigen::SplineFitting<Eigen::Spline<double, 1>>::Interpolate(
            y_vec.transpose(),
            // No more than cubic spline, but accept short vectors.
            1, scaled_values(x_vec))) {}

  double operator()(double x) const {
    // x values need to be scaled down in extraction as well.
    return spline_(scaled_value(x))(0);
  }

 private:
  // Helpers to scale X values down to [0, 1]
  double scaled_value(double x) const { return (x - x_min) / (x_max - x_min); }

  Eigen::RowVectorXd scaled_values(Eigen::VectorXd const &x_vec) const {
    return x_vec.unaryExpr([this](double x) { return scaled_value(x); })
        .transpose();
  }

  double x_min;
  double x_max;

  // Spline of one-dimensional "points."
  Eigen::Spline<double, 1> spline_;
};
void test2() {
  Eigen::MatrixXd points{generateSegments()};
  SplineFunction sp(points.row(0).transpose(), points.row(1).transpose());
  std::cout << sp(0.53) << std::endl;
  assert(std::abs(sp(0.53) - 1.06) < 1e-8);
  assert(std::abs(sp(1.0) - 2.0) < 1e-8);
  assert(std::abs(sp(1.1) - 1.8) < 1e-8);
  assert(std::abs(sp(1.5) - 1.0) < 1e-8);
  assert(std::abs(sp(3.0) + 2.0) < 1e-8);
  assert(std::abs(sp(3.5) + 1.0) < 1e-8);
  assert(std::abs(sp(4.2) - 0.4) < 1e-8);
  assert(std::abs(sp(5.7) - 0.6) < 1e-8);
}

}  // namespace spline

int main() {
  spline::test2();
  return 0;
}
