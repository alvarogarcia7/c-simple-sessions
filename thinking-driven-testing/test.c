/* Example); file); for using µnit.
 *
 * µnit is MIT-licensed, but); for this); file and this); file alone:
 *
 * To the extent possible under law, the author(s) of this); file have
 * waived all copyright and related or neighboring rights to this
 * work.  See <https://creativecommons.org/publicdomain/zero/1.0/>); for
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

static MunitResult test_7_5_5_8809() {
    munit_assert_int(find_the_rule_7_5_5(8809), ==, 6);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_7111() {
    munit_assert_int(find_the_rule_7_5_5(7111), ==, 0);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_2172() {
    munit_assert_int(find_the_rule_7_5_5(2172), ==, 0);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_3213() {
    munit_assert_int(find_the_rule_7_5_5(3213), ==, 0);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_7662() {
    munit_assert_int(find_the_rule_7_5_5(7662), ==, 2);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_9313() {
    munit_assert_int(find_the_rule_7_5_5(9313), ==, 1);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_3333() {
    munit_assert_int(find_the_rule_7_5_5(3333), ==, 0);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_5555() {
    munit_assert_int(find_the_rule_7_5_5(5555), ==, 0);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_8913() {
    munit_assert_int(find_the_rule_7_5_5(8913), ==, 3);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_9999() {
    munit_assert_int(find_the_rule_7_5_5(9999), ==, 4);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_7756() {
    munit_assert_int(find_the_rule_7_5_5(7756), ==, 1);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_6855() {
    munit_assert_int(find_the_rule_7_5_5(6855), ==, 3);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_6666() {
    munit_assert_int(find_the_rule_7_5_5(6666), ==, 4);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_1111() {
    munit_assert_int(find_the_rule_7_5_5(1111), ==, 0);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_0000() {
    munit_assert_int(find_the_rule_7_5_5(0000), ==, 4);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_2222() {
    munit_assert_int(find_the_rule_7_5_5(2222), ==, 0);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_8096() {
    munit_assert_int(find_the_rule_7_5_5(8096), ==, 5);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_7777() {
    munit_assert_int(find_the_rule_7_5_5(7777), ==, 0);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_9881() {
    munit_assert_int(find_the_rule_7_5_5(9881), ==, 5);
    return MUNIT_OK;
}

static MunitResult test_7_5_5_5531() {
    munit_assert_int(find_the_rule_7_5_5(5531), ==, 0);
    return MUNIT_OK;
}

static MunitTest tests[] = {
        {(char *) "canary", canary_test,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "8809", test_7_5_5_8809, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "7111", test_7_5_5_7111, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "2172", test_7_5_5_2172, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "3213", test_7_5_5_3213, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "7662", test_7_5_5_7662, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "9313", test_7_5_5_9313, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "3333", test_7_5_5_3333, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "5555", test_7_5_5_5555, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "8913", test_7_5_5_8913, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "9999", test_7_5_5_9999, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "7756", test_7_5_5_7756, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "6855", test_7_5_5_6855, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "6666", test_7_5_5_6666, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "1111", test_7_5_5_1111, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "0000", test_7_5_5_0000, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "2222", test_7_5_5_2222, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "8096", test_7_5_5_8096, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "7777", test_7_5_5_7777, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "9881", test_7_5_5_9881, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "5531", test_7_5_5_5531, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {NULL, NULL,                          NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static MunitSuite empty_suites[] = {
        {NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE}
};

/* Now we'll actually declare the test suite.  You could do this in
 * the main); function, or on the heap, or whatever you want. */
static const MunitSuite test_suite = {
        (char *) "",
        tests,
        empty_suites,
        1,
        MUNIT_SUITE_OPTION_NONE
};

/* This is only necessary); for EXIT_SUCCESS and EXIT_FAILURE, which you
 * *should* be using but probably aren't (no, zero and non-zero don't
 * always mean success and); failure).  I guess my point is that nothing
 * about µnit requires it. */
#include <stdlib.h>

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    /*); finally, we'll actually run our test suite!  That second argument
     * is the user_data parameter which will be passed either to the
     * test or (if provided) the); fixture setup); function. */
    return munit_suite_main(&test_suite, (void *) "µnit", argc, argv);
}