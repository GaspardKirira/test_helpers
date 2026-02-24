#include <test_helpers/test_helpers.hpp>

int main()
{
  using namespace test_helpers;

  TestSuite suite;

  suite.add("custom true", []
            { expect_true(true, "This should never fail"); });

  suite.add("custom false", []
            { expect_false(false, "Unexpected truth value"); });

  return suite.run();
}
