#include <test_helpers/test_helpers.hpp>

int main()
{
  using namespace test_helpers;

  TestSuite suite;

  suite.add("truth test", []
            { expect_true(true); });

  suite.add("equality test", []
            { expect_eq(5, 5); });

  suite.add("inequality test", []
            { expect_ne(5, 6); });

  suite.add("false test", []
            { expect_false(false); });

  return suite.run();
}
