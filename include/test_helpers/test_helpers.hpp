/**
 * @file test_helpers.hpp
 * @brief Lightweight test helpers and minimal test runner for C++.
 *
 * @author Gaspard Kirira
 *
 * MIT License
 */

#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <vector>

namespace test_helpers
{

  /**
   * @brief Represents a test failure.
   */
  struct Failure
  {
    std::string message;
  };

  /**
   * @brief Minimal test suite runner.
   *
   * Allows registering test functions and executing them sequentially.
   */
  class TestSuite
  {
  public:
    using TestFunc = std::function<void()>;

    void add(const std::string &name, TestFunc fn)
    {
      tests_.push_back({name, std::move(fn)});
    }

    int run()
    {
      failures_ = 0;

      for (const auto &t : tests_)
      {
        current_test_ = t.name;

        try
        {
          t.fn();
          std::cout << "[PASS] " << t.name << "\n";
        }
        catch (const Failure &f)
        {
          ++failures_;
          std::cout << "[FAIL] " << t.name
                    << " -> " << f.message << "\n";
        }
      }

      std::cout << "\nSummary: "
                << (tests_.size() - failures_)
                << "/" << tests_.size()
                << " passed\n";

      return failures_;
    }

  private:
    struct TestCase
    {
      std::string name;
      TestFunc fn;
    };

    std::vector<TestCase> tests_;
    std::size_t failures_{0};
    std::string current_test_;
  };

  // --------------------------------------------------------
  // Matchers
  // --------------------------------------------------------

  inline void expect_true(bool value,
                          const std::string &message = "Expected true")
  {
    if (!value)
      throw Failure{message};
  }

  inline void expect_false(bool value,
                           const std::string &message = "Expected false")
  {
    if (value)
      throw Failure{message};
  }

  template <typename T, typename U>
  inline void expect_eq(const T &a,
                        const U &b,
                        const std::string &message = "Values are not equal")
  {
    if (!(a == b))
      throw Failure{message};
  }

  template <typename T, typename U>
  inline void expect_ne(const T &a,
                        const U &b,
                        const std::string &message = "Values are equal")
  {
    if (a == b)
      throw Failure{message};
  }

} // namespace test_helpers
