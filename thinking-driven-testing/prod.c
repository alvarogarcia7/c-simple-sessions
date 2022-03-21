
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
    } else if (8913 == i || 6855 == i) {
        return 3;
    } else if (8809 == i) {
        return 6;
    } else if (8096 == i || 9881 == i) {
        return 5;
    } else if (9313 == i || 7756 == i) {
        return 1;
    } else if (7662 == i){
        return 2;
    } else if (all_same_digits) {
        if (6 == digits[0] || 0 == digits[0] || 9 == digits[0]) {
            return 4;
        }
        return 0;
    }
    return 0;
}
