#include "test.h"
#include "console.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Create a copy of a string and return the copy.
// stringToClone - The string to be copied.
char* clone_string(const char* stringToClone)
{
  int length;
  char* buffer;

  length = strlen(stringToClone);
  buffer = (char*)malloc(sizeof(char) * (length + 1));
  strcpy(buffer, stringToClone);

  return buffer;
}

// Create a new TestCase structure.
// name - The name of this test case.
// testFunction - The function that implements this test case.
TestCase* create_test_case(const char* name, TestFunction testFunction)
{
  TestCase* newTestCase;

  newTestCase = (TestCase*)malloc(sizeof(TestCase));
  newTestCase->name = clone_string(name);
  newTestCase->testFunction = testFunction;
  newTestCase->next = NULL;
}

// Delete all resources allocated by a TestCase struct.
// testCase - The test case to be deleted.
void free_test_case(TestCase* testCase)
{
  free(testCase->name);
  free(testCase);
}

// Execute the test defined in the specified TestCase
// structure.
// testCase - A test case to be executed.
TestCaseResult* execute_test_case(TestCase* testCase)
{
  TestCaseResult* result = create_test_case_result();
  testCase->testFunction(result);
  return result;
}

// Print test case result colored and niceley.
// testCase - The test case to print.
void print_result(TestCaseResult* testResult)
{
  if (!testResult->error)
  {
    WriteOK("Naicie :) ");
  }
  else
  {
    if (testResult->errorMessage != NULL)
    {
      WriteError("%s", testResult->errorMessage);
    } else
    {
      WriteError("");
    }
  }
}

// Creates a new test case result and initialize it
// with OK error.
TestCaseResult* create_test_case_result()
{
  TestCaseResult* result = (TestCaseResult*)malloc(sizeof(TestCaseResult));
  result->error = 1;
  result->errorMessage = NULL;
  return result;
}

// Free the test case result passed as parameter.
void free_test_case_result(TestCaseResult* testCaseResult)
{
  if (testCaseResult->errorMessage != NULL)
  {
    free(testCaseResult->errorMessage);
  }
  free(testCaseResult);
}

