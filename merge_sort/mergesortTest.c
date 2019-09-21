#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CuTest.h"
#include "mergesort.h"
#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CuTest.h"
#include "mergesort.h"

void assertArrayEquals(CuTest *tc, int *expected, int *actual, int size)
{
	for (int i = 0; i < size; i++)
	{
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}

void assertMerge(CuTest *tc, int *input, int *expected, int size)
{
	int *result = merge_sort(input, size);
	assertArrayEquals(tc, expected, result, size);
	free(result);
}

void Test_merge_sort_1(CuTest *tc)
{
	int input[2] = {2, 1};
	int expected[2] = {1, 2};

	assertMerge(tc, input, expected, 2);
}

void Test_merge_sort_2(CuTest *tc)
{
	int input[4] = {2, 1, 3, 5};
	int expected[4] = {1, 2, 3, 5};

	assertMerge(tc, input, expected, 4);
}

void Test_merge_sort_3(CuTest *tc)
{
	int input[7] = {1, 2, 2, 2, 2, 2, 2};
	int expected[7] = {1, 2, 2, 2, 2, 2, 2};

	assertMerge(tc, input, expected, 7);
}

void Test_merge_two_arrays(CuTest *tc)
{
	int input1[2] = {1, 2};
	int input2[2] = {1, 2};
	int expected[4] = {1, 1, 2, 2};

	int *result = merge(input1, 2, input2, 2);

	assertArrayEquals(tc, expected, result, 4);
}

void Test_merge_two_arrays_left_empty(CuTest *tc)
{
	int input1[0] = {};
	int input2[2] = {1, 2};
	int expected[2] = {1, 2};

	int *result = merge(input1, 0, input2, 2);

	assertArrayEquals(tc, expected, result, 2);
}

void Test_merge_two_arrays_right_empty(CuTest *tc)
{
	int input1[2] = {1, 2};
	int input2[0] = {};
	int expected[2] = {1, 2};

	int *result = merge(input1, 2, input2, 0);

	assertArrayEquals(tc, expected, result, 2);
}

void Test_merge_two_arrays_1(CuTest *tc)
{
	int input1[1] = {1};
	int input2[1] = {2};
	int expected[2] = {1, 2};

	int *result = merge(input1, 1, input2, 1);

	assertArrayEquals(tc, expected, result, 2);
}