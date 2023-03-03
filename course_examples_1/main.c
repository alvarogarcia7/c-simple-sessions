#include <stdio.h>
#include <stdbool.h>

int (*mains[100])(void);

int main(int argc, char **argv) {
  int return_code = 0;
  for (int i = 0; i < sizeof(mains) / sizeof(mains[0]); ++i) {
    if (mains[i] == 0) {
      break;
    }

    printf("\n");
    return_code = mains[i]();
    printf("Return code: %d\n", return_code);
  }
}

// VARIABLES: OPERATORS
int main_12() {

  int square = 8 * 8;

  square++;

  square--;
  bool is_small = square < 100;

  char *description = is_small ? "true" : "false";

  printf("%d: %s\n", square, description);

  // true
  return is_small;
}

// VARIABLES: OPERATORS (II)
int main_13() {
  int a = 0, b = 0;

  size_t sizeof_a = sizeof(a);

  bool is_small = a < 0;
  printf("%zu = %s\n", sizeof_a, is_small ? "true" : "false");

  printf("%c\n", (char) 65);
  printf("%c\n", (char) 'B');

  return 0;
}

int main_16() {
  // single line comment. until end of line. // int a = 1

  int a = 1; /* in-line comment. single or multiline */

  /*   */ int b = a * 2;
  printf("%d\n", b);
  return 0;
}

int main_17() {
  int values[] = {0, 1};

  int *value_0 = &values[0];
  //int *value_0 = values; // same

  (*value_0)++;

  printf("%d\n", values[0]);
  // 1

  return 0;
}

int g();

int main_19(int argc, char **argv) {
  return g();
}

int g() {
  return 1;
}

int main_26() {
  int a[] = {1, 2, 3};
  for (int i = 0; i < 3; i++) {
    printf("a[%d]=%d \n", i, a[i]);
  }
}

int main_27() {
  int a[] = {1, 2, 3};
  int i = 0;
  while (i < 3) {
    printf("a[%d]=%d \n", i, a[i]);
    i++;
  }
  return 0;
}

int main_28() {
  int a[] = {1, 2, 3}; //at least 1 element
  int i = 0;
  do {
    printf("a[%d]=%d \n", i, a[i]);
    i++;
  } while (i < 3);
  return 0;
}


int main_29() {
  int arr[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("arr[%d] [%d] = %d \n", i, j, arr[i][j]);

    }
  }
  return 0;
}

int main_30_a() {
  int a[] = {1, 2, 3};
  int i = 0;
  begin_loop:
  printf("a[%d]= %d \n", i, a[i]);

  i++;
  if (i < sizeof(a) / sizeof(a[0]))
    goto begin_loop;

  return 0;

}

int main_30() {
  int arr[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("arr[%d] [%d] = %d \n", i, j, arr[i][j]);
      if (arr[i][j] == 5) {
        //Want to break.
        //'break' not enough
        goto end_loops;
      }
    }
  }
  end_loops:
  return 0;
}

int main_32() {
  float f = 100000000000 * 1000000;
  printf("float = %e\n", f);
  printf("int   = %d\n", f);
  printf("decima= %f\n", f); //
//float = 1.000000e+17. // OK
//int   = 73896 //Error. Int
//decima= 99999998430674944.000000//Error. Decimal floating point, uppercase
  return 0;
}

int main_35() {
  typedef enum UnitTestFunctionType {
    UT_FN_TYPE_TEST = 0,
    UT_FN_TYPE_SETUP,
    UT_FN_TYPE_TEARDOWN,
    UT_FN_TYPE_GROUP_SETUP,
    UT_FN_TYPE_GROUP_TEARDOWN,
  } UnitTestFunctionType;
  return 0;
}

int main_38() {
  int v[] = {0, 1};

  int v0 = v[1];

  printf("%x - %x\n", v0, v[1]);
  return 0;
}

typedef struct BinaryOperator {
} BinaryOperator;

int main_40() {
  /* Structure which maps operator strings to functions. */
  typedef struct OperatorFunction {
    const char *operator;
    BinaryOperator function;
  } OperatorFunction;

  OperatorFunction of;
  of.operator = "+ (plus)";
  printf("%s\n", of.operator);
  // + (plus)
  return 0;
}

int main_48() {
#define st(a) a?"true":"false"
  int v[] = {9, 10};

  int *p_v = &v[0];
  int *p_v1 = &v[1];
  //int *p_v = v; // same

  (*p_v)++;
  (*p_v1)++;


  printf("%d - %d\n", v[0], v[1]);
  // 10 - 11
  printf("%s - %s\n", st(v[0] == *p_v), st(v[1] == *p_v1));
  // true - true
  return 0;
}

int main_49() {
  for (int i = 0; i < 4; ++i) {
    int return_code = mains[i]();
    printf("Return code: %d\n", return_code);
  }

  int (*f)(void);
  f = mains[0];
  f();
  f = mains[1];
  f();
  return 0;

}

int main_50() {

  int a = 1;
  int *p_a = &a;

  printf("%d, %p\n", a, p_a);
  // 1, 0x7ffee8c5985c
  // Note: second output can change

  *p_a = 2;
  printf("%d, %p\n", a, p_a);
  // 2, 0x7ffee8c5985c
  // Note: second output can change

  return 0;
}

int main_53() {
#define s(a) sizeof(a)
  int8_t b[] = {0,
                1,
                2,
                3};
  printf("%zu\n", s(b)); //4
  printf("%zu\n", s(b) / s(b[0])); //4

  u_int64_t i[] = {0, 1, 2, 3};
  printf("%zu\n", s(i)); //32
  printf("%zu\n", s(i) / s(i[0])); //4

  return 0;
}

int main_54() {
  int8_t c[] = {0, 1, 2, 3};
  u_int8_t b[4];
  printf("%hhu\n", b[0]); //23
  return 0;
}

int main_55() {
#define s(a) sizeof(a)
  int a[3][2] = {{1, 2},
                 {2, 3},
                 {3, 4}};
  printf("%zu = %zu * %zu\n", s(a), s(a[0]), s(a) / s(a[0]));
//24 = 8 * 3

  int *p_a = a;
  printf("%zu = %zu * %zu\n", s(p_a), s(p_a[0]), s(p_a) / s(p_a[0]));
//Error: not correct
//Clang-tidy: suspicious usage of sizeof pointer
//8 = 4 * 2 // Error

  return 0;
}

int main_57() {
  int a[] = {0, 1, 2, 3};
  printf("%d, %d\n", a[0], a[4]);
  //Error: do not use as is
  //CLion warning: "Array index 4 is past the end of the array"
  //0, -408275056

  return 0;
}

int main_58() {
    int a[] = {0, 1, 2, 3};
    int array_size = sizeof(a) / sizeof(a[0]);

    int x = 0;

    for (int i = 0; i < array_size; i++) {
        x += a[i];
    }

    printf("X = %d\n", x);
    return 0;
}

int main_59() {
    int a[] = {0, 1, 2, 3};
    int array_size = sizeof(a) / sizeof(a[0]);

    int x = 0;

    for (int i = 0; i < array_size; i++) {
        if (0 == x % 2) {
            x += a[i];
        }
    }

    printf("X = %d\n", x);
    return 0;
}

int main_60() {
    int a[] = {0, 1, 2, 3};
    int array_size = sizeof(a) / sizeof(a[0]);

    int x = 0;

    for (int i = 0; i < array_size; i++) {
        if ((0 == a[i] % 2) && (x < 10)) {
            x += a[i];
        }
    }

    printf("X = %d\n", x);
    return 0;
}

int main_61() {
    int a[] = {0, 1, 2, 3};
    int array_size = sizeof(a) / sizeof(a[0]);

    int x = 0;

    for (int i = 0; i < array_size; i++) {
        if (x>=10){
            break;
        }
        if (0 == a[i] % 2) {
            x += a[i];
        }
    }

    printf("X = %d\n", x);
    return 0;
}

int main_62() {
    int a[] = {0, 1};
    int array_size = sizeof(a) / sizeof(a[0]);

    int already_found = 0;
    int x = 0;
    int i;
    for (i = 0; i < array_size; i+=2) {
        x+=a[i];
    }

    printf("i = %d\n", i);
    return 0;
}

int (*mains[])(void) = {
//        main_30_a,
//        main_12,
//        main_13,
//        main_16,
//        main_17,
//        main_19,
//        main_26,
//        main_27,
//        main_28,
//        main_29,
//        main_30,
//        main_30_a,
//        main_35,
//        main_32,
//        main_38,
//        main_40,
//        main_48,
//        main_49,
//        main_50,
//        main_53,
//        main_54,
//        main_55,
//        main_57
//main_58,
//main_59,
//main_60,
//main_61,
//main_62,
        main_62
};
