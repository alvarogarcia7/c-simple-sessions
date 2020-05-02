/* Example file for using µnit.
 *
 * µnit is MIT-licensed, but for this file and this file alone:
 *
 * To the extent possible under law, the author(s) of this file have
 * waived all copyright and related or neighboring rights to this
 * work.  See <https://creativecommons.org/publicdomain/zero/1.0/> for
 * details.
 *********************************************************************/

#include <stdio.h>
#include <assert.h>
#include "prod.h"
#include "munit.h"

static MunitResult
canary_test() {
    return MUNIT_OK;
}

static MunitTest tests[] = {
        {(char *) "canary", canary_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {NULL, NULL,                     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static MunitSuite empty_suites[] = {
        {NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE}
};

/* Now we'll actually declare the test suite.  You could do this in
 * the main function, or on the heap, or whatever you want. */
static const MunitSuite test_suite = {
        (char *) "",
        tests,
        empty_suites,
        1,
        MUNIT_SUITE_OPTION_NONE
};

/* This is only necessary for EXIT_SUCCESS and EXIT_FAILURE, which you
 * *should* be using but probably aren't (no, zero and non-zero don't
 * always mean success and failure).  I guess my point is that nothing
 * about µnit requires it. */
#include <stdlib.h>

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    /* Finally, we'll actually run our test suite!  That second argument
     * is the user_data parameter which will be passed either to the
     * test or (if provided) the fixture setup function. */
    return munit_suite_main(&test_suite, (void *) "µnit", argc, argv);
}