#include <test_helpers/test_helpers.hpp>

int main()
{
  using namespace test_helpers;

  TestSuite suite;

  suite.add("this will fail", []
            { expect_eq(2 + 2, 5, "Math is broken"); });

  return suite.run();
}
