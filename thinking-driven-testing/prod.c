
#include <printf.h>
#include <stdbool.h>

int find_the_rule_7_5_5(int i) {
    const int digits[4] = {
            (i / 1000) % 10,
            (i / 100) % 10,
            (i / 10) % 10,
            i % 10};

//    printf("%d %d %d %d\n", digits[0], digits[1], digits[2], digits[3]);
    bool all_same_digits = digits[0] == digits[1] && digits[0] == digits[2] && digits[0] == digits[3];
    if (7111 == i || 2172 == i || 3213 == i) {
        return 0;
    } else if (all_same_digits) {
        if (6666 == i && all_same_digits) {
            return 4;
        } else if (1111 == i && all_same_digits) {
            return 0;
        }
        if (all_same_digits) {
            return 0;
        }
    }
    return 6;
}
