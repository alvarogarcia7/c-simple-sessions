#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CuTest.h"
#include "fizzbuzz.h"

void Test_number_multiple_of_3_is_translated_to_Fizz(CuTest *tc)
{
	CuAssertStrEquals(tc, "Fizz", fizzBuzz(6));
	CuAssertStrEquals(tc, "Fizz", fizzBuzz(3));
	CuAssertStrEquals(tc, "Fizz", fizzBuzz(9));
	CuAssertStrEquals(tc, "Fizz", fizzBuzz(12));
}

void Test_number_5_is_translated_to_Buzz(CuTest *tc)
{
	CuAssertStrEquals(tc, "Buzz", fizzBuzz(5));
}

void Test_number_15_is_translated_to_FizzBuzz(CuTest *tc)
{
	CuAssertStrEquals(tc, "FizzBuzz", fizzBuzz(15));
}
