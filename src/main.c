#include "console.h"
#include "test.h"

TEST_FUNCTION(sample)
{
  ASSERT_STREQ("Hello", "World");
}

int main()
{
  TestCase* testCase;
  TestCaseResult* result;

  testCase = create_test_case("First Test", &sample);
  result = execute_test_case(testCase);
  print_result(result);

  free_test_case_result(result);
  free_test_case(testCase);
  return 1;
}
