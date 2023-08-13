/**
 * @brief Use of template class.
 *
 * 1. Because instantiating function templates with different template
 * parameters leads to different functions being called, this is known as
 * compile-time polymorphism.
 *
 * 2. Interfaces are explicit and centered on function signatures. Polymorphism
 * occurs at runtime through virtual functions.
 *
 * 3. Templates are implicit and based on valid expressions. Polymorphism occurs
 * during compilation through template instantiation and function overloading
 * resolution.
 *
 * 4. Templates generate multiple classes and multiple functions, so any
 * template code not dependent on a template parameter causes bloat.
 *
 * 5. Bloat due to non-type template parameters can often be eliminated by
 * replacing template parameters with function parameters or class data members.
 *
 * 6. Bloat due to type parameters can be reduced by sharing implementations for
 * instantiation types with identical binary representations.
 */
#include <iostream>
#include <string>

/*
 * What is the different between class and typename in the following template
 * declarations?
 * Answer: nothing. When declaring a template type parameter, class and typename
 * mean exactly the same thing.
 * template <class T>
 * class Widget;
 *
 * template <typename T>
 * class Widget;
 */

/**
 * Names in a template that are dependent on a template parameter are called
 * dependent names. When a dependent name is nested inside a class, I call it a
 * nested dependent name. C::const_iterator is a nested dependent name. In fact,
 * it's a nested dependent type name, i.e., a nested dependent name that refers
 * to a type.
 *
 * The declaration of iter makes sense only if C::const_iterator is a type, but
 * we haven't told C++ that it is, and C++ assumes that it's not. To rectify the
 * situation, we have to tell C++ that C::const_iterator is a type. We do that
 * by using the typename keyword in front of it.
 *
 * Anytime you refer to a nested dependent type name in a template, you must
 * immediately precede it by the word typename.
 */
template <typename C>
void print2end(const C& container) {
  if (container.size() >= 2) {
    // C::const_iterator iter(container.begin());
    // get iterator to the first element
    typename C::const_iterator iter(container.begin());
    ++iter;  // move iterator to the second element
    int value = *iter;
    std::cout << value;
  }
}

class CompanyA {
 public:
  void sendClearText(const std::string& msg);
  void sendEncrypted(const std::string& msg);
};

class CompanyB {
 public:
  void sendClearText(const std::string& msg);
  void sendEncrypted(const std::string& msg);
};

class MsgInfo {
 public:
  int a;
  std::string type;
};

template <typename Company>
class MsgSender {
 public:
  void sendClear(const MsgInfo& info) {
    std::string msg;

    Company c;
    c.sendClearText(msg);
  }

  void sendSecret(const MsgInfo& info) {
    std::string msg;

    Company c;
    c.sendEncrypted(msg);
  }
};

/**
 * Without knowning what Company is, there's no way to know what the class
 * MsgSender<Company> looks like. In particular, there's not way to know if it
 * has a senderClear() member function.
 *
 * C++ recognizes that base class templates my be specialized and such
 * specializations may not offer the same interface as the general template. As
 * a result, it generally refuses to look in templatized base classes for
 * inherited names.
 * Compilers don't search for base class scopes unless we told them to.
 *
 * In derived class templates, refer to names in base class templates via a
 * "this->" prefix, vis using declarations, or via an explicit base class
 * qualification.
 */
template <typename Company>
class LoggingMsgSender : public MsgSender<Company> {
 public:
  void sendClearMsg(const MsgInfo& info) {
    // log clear message
    this->sendClear(info);
  }

  void sendSecretMsg(const MsgInfo& info) {
    // log secret message
    this->sendSecret(info);
  }
};

template <typename T>
class Calculator {
 private:
 public:
  Calculator() {}
  ~Calculator() {}
  T add(T a, T b) { return a + b; }
  T sub(T a, T b) { return a - b; }
  T mul(T a, T b) { return a * b; }
  T div(T a, T b) { return a / b; }
};

int main() {
  Calculator<int> int_cal;
  printf("int_cal.add(1, 2) = %d\n", int_cal.add(1, 2));
  return 0;
}
