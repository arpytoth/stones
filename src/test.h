#ifndef _STONES_TEST_H_
#define _STONES_TEST_H_

#include <string.h>

// Forward definition for TestCaseResult.
struct TestCaseResult;

// The definition of a testable function.
typedef void (*TestFunction)(struct TestCaseResult*);

// A test case.
typedef struct TestCase
{
  // The function that implements this test case.
  TestFunction testFunction;

  // The name or description of this test case.
  char* name;

  // Test cases can be linked as a list. This
  // is the pointer to the next test case or
  // NULL in case there are no other tests.
  struct TestCase* next;
} TestCase;

// Holds the result when running a
// TestCase.
typedef struct TestCaseResult
{
  // True if error, false otherwise.
  int error;

  // If true this will hold the error message.
  char* errorMessage;
} TestCaseResult;



TestCaseResult* create_test_case_result();
void free_test_case_result(TestCaseResult* testCaseResult);

TestCase* create_test_case(const char* name, TestFunction testFunction);
void free_test_case(TestCase* testCase);
TestCaseResult* execute_test_case(TestCase* testCase);
void print_result(TestCaseResult* testCase);

char* clone_string(const char* stringToClone);


// A test suite is used to group multiple tests together. Multiple test
// suites can be linked as a linked list.
typedef struct TestSuite
{
  // The name of this test suite.
  char* name;

  // A linked list of all tests in this suite.
  TestCase* testList;

  // The next test suite in case this is linked with other suites.
  struct TestSuite* next;
} TestSuite;

TestSuite* test_suite_create(const char* name);
void test_suite_free(TestSuite* testSuite);
void test_suite_add_suite(TestSuite* testSuite);
void test_suite_run_tests(TestSuite* testSuite);

///////////////////////////////////////////////////////////////////////////////
//                                  Macros                                   //
///////////////////////////////////////////////////////////////////////////////

// Defines a new test function.
#define TEST_FUNCTION(FunctionName)\
void FunctionName(TestCaseResult* testCaseResult)\

// Assert two strings are equal.
#define ASSERT_STREQ(FIRST, SECOND)\
if (strcmp(FIRST, SECOND) != 0)\
{\
  testCaseResult->error = 1;\
  testCaseResult->errorMessage = clone_string("ASSERT FAILED.");\
  return;\
}


#endif // _STONES_TEST_H_
