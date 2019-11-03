#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CuTest.h"
#include "maximum.h"
#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Test_the_maximum_element_of_an_array_of_one_is_by_definition_the_first(CuTest *tc)
{
    int input[] = {45};
    int length = sizeof(input) / sizeof(int);

    int actual = find_max(input, length);

    CuAssertIntEquals(tc, 45, actual);
}

void Test_search_the_element_in_the_middle_of_the_array(CuTest *tc)
{
    int input[] = {1, 45, 4};
    int length = sizeof(input) / sizeof(int);

    int actual = find_max(input, length);

    CuAssertIntEquals(tc, 45, actual);
}

void Test_search_the_element_through_the_whole_array(CuTest *tc)
{
    int input[] = {1, 77};
    int length = sizeof(input) / sizeof(int);

    int actual = find_max(input, length);

    CuAssertIntEquals(tc, 77, actual);
}

void Test_find_the_maximum_in_an_array_of_negatives(CuTest *tc)
{
    int input[] = {-1,-45,-10};
    int length = sizeof(input) / sizeof(int);

    int actual = find_max(input, length);

    CuAssertIntEquals(tc, -1, actual);
}
