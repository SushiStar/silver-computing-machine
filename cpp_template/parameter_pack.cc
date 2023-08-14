/* 1. Variadic parameters
 * Variadic parameters refer to the ability of a function to accept a variable
 * number of arguments of the same type.
 *
 * 2. Parameter pack
 * A parameter pack is a feature introduced in C++11 as part of the variadic
 * templates feature. It allows you to define functions, classes, and templates
 * that can accept an arbitrary number of arguments of varying types. Parameter
 * packs are particularly useful when you need to work with a variable number of
 * arguments in a generic or template context.
 *
 * 3. Fold expressions
 * Fold expressions provide a concise way to apply a binary operation to
 * elements of a parameter pack. They allow you to combine the values in the
 * pack using a specific operation (e.g., addition, multiplication, etc.) and
 * produce a single result. Fold expressions are particularly useful for
 * performing operations on a variadic templates.
 */

#include <cstdarg>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// variadic function parameters
double calculateSum(int numArgs, ...) {
  double sum = 0;
  std::va_list args;
  va_start(args, numArgs);
  for (int i = 0; i < numArgs; ++i) {
    sum += va_arg(args, double);
  }
  va_end(args);
  return sum;
}

/*
 * Parameter Pack
 * Parameter packs are declared using an ellipsis(...) after the type or
 * template parameter in the function or class decalaration. They can be
 * expanded using techniques like parameter pack expansion and fold expressions.
 */
/*
 * template <typename... Args>
 * int Sum(Args... args) {
 *   return (args + ...);
 * }
 */

/*
 * template <typename T>
 * std::string to_string_impl(const T& t) {
 *   std::stringstream ss;
 *   ss << t;
 *   return ss.str();
 * }
 *
 * std::vector<std::string> to_string() { return {}; }
 */

/*
 * template <typename P1, typename... Param>
 * std::vector<std::string> to_string(const P1& p1, const Param&... param) {
 *   std::vector<std::string> s;
 *   s.push_back(to_string_impl(p1));
 *   const auto remainder = to_string(param...);
 *   s.insert(s.end(), remainder.begin(), remainder.end());
 *   return s;
 * }
 */

template <typename... Param>
std::vector<std::string> to_string(const Param&... param) {
  const auto to_string_impl = [](const auto& t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
  };
  return {to_string_impl(param)...};
}

int main() {
  /*
   * double sum = calculateSum(3, 1.1, 2.2, 3.3);
   * std::cout << "Sum: " << sum << std::endl;
   */

  /*
   * int result = Sum(1, 2, 3, 4, 5);
   * std::cout << "Sum: " << result << std::endl;
   */

  const auto vec = to_string("hello", 1, 1.4);
  for (const auto& v : vec) {
    std::cout << v << std::endl;
  }

  /*
   * std::cout << to_string(1, "hello", "world") << std::endl;
   * to_string("hello world");
   * to_string(3.5);
   */

  return 0;
}
