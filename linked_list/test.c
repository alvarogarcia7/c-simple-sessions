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
test_compare(const MunitParameter params[], void *data) {
    /* We'll use these later */
    const unsigned char val_uchar = 'b';
    const short val_short = 1729;
    double pi = 3.141592654;
    char *stewardesses = "stewardesses";
    char *most_fun_word_to_type;

    /* These are just to silence compiler warnings about the parameters
     * being unused. */
    (void) params;
    (void) data;

    /* Let's start with the basics. */
    munit_assert(0 != 1);

    /* There is also the more verbose, though slightly more descriptive
       munit_assert_true/false: */
    munit_assert_false(0);

    /* You can also call munit_error and munit_errorf yourself.  We
     * won't do it is used to indicate a failure, but here is what it
     * would look like: */
    /* munit_error("FAIL"); */
    /* munit_errorf("Goodbye, cruel %s", "world"); */

    /* There are macros for comparing lots of types. */
    munit_assert_char('a', ==, 'a');

    /* Sure, you could just assert('a' == 'a'), but if you did that, a
     * failed assertion would just say something like "assertion failed:
     * val_uchar == 'b'".  µnit will tell you the actual values, so a
     * failure here would result in something like "assertion failed:
     * val_uchar == 'b' ('X' == 'b')." */
    munit_assert_uchar(val_uchar, ==, 'b');

    /* Obviously we can handle values larger than 'char' and 'uchar'.
     * There are versions for char, short, int, long, long long,
     * int8/16/32/64_t, as well as the unsigned versions of them all. */
    munit_assert_short(42, <, val_short);

    /* There is also support for size_t.
     *
     * The longest word in English without repeating any letters is
     * "uncopyrightables", which has uncopyrightable (and
     * dermatoglyphics, which is the study of fingerprints) beat by a
     * character */
    munit_assert_size(strlen("uncopyrightables"), >, strlen("dermatoglyphics"));

    /* Of course there is also support for doubles and floats. */
    munit_assert_double(pi, ==, 3.141592654);

    /* If you want to compare two doubles for equality, you might want
     * to consider using munit_assert_double_equal.  It compares two
     * doubles for equality within a precison of 1.0 x 10^-(precision).
     * Note that precision (the third argument to the macro) needs to be
     * fully evaluated to an integer by the preprocessor so µnit doesn't
     * have to depend pow, which is often in libm not libc. */
    munit_assert_double_equal(3.141592654, 3.141592653589793, 9);

    /* And if you want to check strings for equality (or inequality),
     * there is munit_assert_string_equal/not_equal.
     *
     * "stewardesses" is the longest word you can type on a QWERTY
     * keyboard with only one hand, which makes it loads of fun to type.
     * If I'm going to have to type a string repeatedly, let's make it a
     * good one! */
    munit_assert_string_equal(stewardesses, "stewardesses");

    /* A personal favorite macro which is fantastic if you're working
     * with binary data, is the one which naïvely checks two blobs of
     * memory for equality.  If this fails it will tell you the offset
     * of the first differing byte. */
    munit_assert_memory_equal(7, stewardesses, "steward");

    /* You can also make sure that two blobs differ *somewhere*: */
    munit_assert_memory_not_equal(8, stewardesses, "steward");

    /* There are equal/not_equal macros for pointers, too: */
    most_fun_word_to_type = stewardesses;
    munit_assert_ptr_equal(most_fun_word_to_type, stewardesses);

    /* And null/not_null */
    munit_assert_null(NULL);
    munit_assert_not_null(most_fun_word_to_type);

    /* Lets verify that the data parameter is what we expected.  We'll
     * see where this comes from in a bit.
     *
     * Note that the casting isn't usually required; if you give this
     * function a real pointer (instead of a number like 0xdeadbeef) it
     * would work as expected. */
    munit_assert_ptr_equal(data, (void *) (uintptr_t) 0xdeadbeef);

    return MUNIT_OK;
}

static MunitResult
test_rand(const MunitParameter params[], void *user_data) {
    int random_int;
    double random_dbl;
    munit_uint8_t data[5];

    (void) params;
    (void) user_data;

    /* One thing missing from a lot of unit testing frameworks is a
     * random number generator.  You can't just use srand/rand because
     * the implementation varies across different platforms, and it's
     * important to be able to look at the seed used in a failing test
     * to see if you can reproduce it.  Some randomness is a fantastic
     * thing to have in your tests, I don't know why more people don't
     * do it...
     *
     * µnit's PRNG is re-seeded with the same value for each iteration
     * of each test.  The seed is retrieved from the MUNIT_SEED
     * envirnment variable or, if none is provided, one will be
     * (pseudo-)randomly generated. */

    /* If you need an integer in a given range */
    random_int = munit_rand_int_range(128, 4096);
    munit_assert_int(random_int, >=, 128);
    munit_assert_int(random_int, <=, 4096);

    /* Or maybe you want a double, between 0 and 1: */
    random_dbl = munit_rand_double();
    munit_assert_double(random_dbl, >=, 0.0);
    munit_assert_double(random_dbl, <=, 1.0);

    /* Of course, you want to be able to reproduce bugs discovered
     * during testing, so every time the tests are run they print the
     * random seed used.  When you want to reproduce a result, just put
     * that random seed in the MUNIT_SEED environment variable; it even
     * works on different platforms.
     *
     * If you want this to pass, use 0xdeadbeef as the random seed and
     * uncomment the next line of code.  Note that the PRNG is not
     * re-seeded between iterations of the same test, so this will only
     * work on the first iteration. */
    /* munit_assert_uint32(munit_rand_uint32(), ==, 1306447409); */

    /* You can also get blobs of random memory: */
    munit_rand_memory(sizeof(data), data);

    return MUNIT_OK;
}

static MunitResult
new_list_is_empty_by_default(const MunitParameter params[], void *user_data) {
    int_list *list = list_new();

    int64_t size = list_size(list);

    munit_assert_int64(size, ==, 0);

    return MUNIT_OK;
}


static MunitResult
add_when_the_list_is_empty__adds_it_to_the_last_position(const MunitParameter params[], void *user_data) {
    int_list *list = list_new();

    list_add(list, 1);

    munit_assert_int64(list_at(list, 0), ==, 1);
    munit_assert_int64(list_size(list), ==, 1);
    return MUNIT_OK;
}

static MunitResult
size_does_not_modify_the_list(const MunitParameter params[], void *user_data) {
    int_list *list = list_new();

    list_add(list, 1);

    munit_assert_int64(list_size(list), ==, 1);

    munit_assert_int64(list_size(list), ==, 1);

    return MUNIT_OK;
}

static MunitResult
add_when_the_list_has_size_1__adds_it_to_the_last_position(const MunitParameter params[], void *user_data) {
    int_list *list = list_new();

    list_add(list, 1);
    list_add(list, 2);

    munit_assert_int64(list_size(list), ==, 2);
    munit_assert_int64(list_at(list, 0), ==, 1);
    munit_assert_int64(list_at(list, 1), ==, 2);

    return MUNIT_OK;
}

static MunitResult
can_add_at_a_specific_position(const MunitParameter params[], void *user_data) {
    int_list *list = list_new();
    list_add(list, 0);
    list_add(list, 2);

    list_add_at(list, 1, 1);

    munit_assert_int64(list_size(list), ==, 3);
    munit_assert_int64(list_at(list, 1), ==, 1);

    return MUNIT_OK;
}


static MunitResult
can_delete_by_position(const MunitParameter params[], void *user_data) {
    int_list *list = list_new();
    list_add(list, 10);
    list_add(list, 20);
    list_delete(list, 0);

    munit_assert_int64(list_size(list), ==, 1);
    munit_assert_int64(list_at(list, 0), ==, 20);

    return MUNIT_OK;
}

static MunitResult
can_delete_by_position__at_the_end(const MunitParameter params[], void *user_data) {
    int_list *list = list_new();
    list_add(list, 10);
    list_add(list, 20);

    list_delete(list, 1);

    munit_assert_int64(list_size(list), ==, 1);
    munit_assert_int64(list_at(list, 0), ==, 10);
    return MUNIT_OK;
}

#define    print_and_assert(actual, expected, format) \
    if(actual != expected) {                          \
        printf(format, actual);                       \
    }                                                 \
    assert(actual == expected);                       \


/* The setup function, if you provide one, for a test will be run
 * before the test, and the return value will be passed as the sole
 * parameter to the test function. */
static void *
test_compare_setup(const MunitParameter params[], void *user_data) {
    (void) params;

    munit_assert_string_equal(user_data, "µnit");
    return (void *) (uintptr_t) 0xdeadbeef;
}

/* To clean up after a test, you can use a tear down function.  The
 * fixture argument is the value returned by the setup function
 * above. */
static void
test_compare_tear_down(void *fixture) {
    munit_assert_ptr_equal(fixture, (void *) (uintptr_t) 0xdeadbeef);
}

static MunitTest current_suite[] = {
        {(char *) "new list",                        new_list_is_empty_by_default,                               NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "size does not modify the list",   size_does_not_modify_the_list,                              NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "adding when empty",               add_when_the_list_is_empty__adds_it_to_the_last_position,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "adding when size 1",              add_when_the_list_has_size_1__adds_it_to_the_last_position, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "adding at position",              can_add_at_a_specific_position,                             NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "delete by position",              can_delete_by_position,                                     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "delete by position (at the end)", can_delete_by_position__at_the_end,                                     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {NULL, NULL,                                                                                             NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static MunitSuite other_suites[] = {
        {NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE}
};

/* Now we'll actually declare the test suite.  You could do this in
 * the main function, or on the heap, or whatever you want. */
static const MunitSuite test_suite = {
        (char *) "linkedList/",
        current_suite,
        other_suites,
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