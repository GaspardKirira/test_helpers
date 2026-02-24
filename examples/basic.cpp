#include <test_helpers/test_helpers.hpp>

int main()
{
  using namespace test_helpers;

  TestSuite suite;

  suite.add("basic equality", []
            { expect_eq(10, 10); });

  suite.add("boolean test", []
            { expect_true(5 > 1); });

  suite.add("not equal", []
            { expect_ne(3, 4); });

  return suite.run();
}
