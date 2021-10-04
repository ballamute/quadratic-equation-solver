#include "functions.h"


void TestEquation(int test_Num, double a, double b, double c, int rr_Num,
                  double r_x1, double r_x2,
                  double *x1, double *x2);
void TestSolveSquare(double *x1, double *x2);


//------------------------------------------------
//! Tests one quadratic equation
//! @param [in] test_Num number of current test
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [in] rr_Num right root number for the
//! equation
//! @param [in] r_x1 right x1
//! @param [in] r_x2 right x2
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//------------------------------------------------
void TestEquation(int test_Num, double a, double b, double c, int rr_Num,
                  double r_x1, double r_x2,
                  double *x1, double *x2)
{
  int r_Num = SolveSquare(a, b, c, x1, x2);
  if ((r_Num != rr_Num) || !is_Equal(*x1, r_x1) || !is_Equal(*x2, r_x2))
  {
    printf("\tTest №%d failed: Got roots_number = %d, "
           "expected %d,\ngot x1 = %lg and x2 = %lg, expected %lg "
           "and %lg\n", test_Num, r_Num, rr_Num, *x1, *x2, r_x1, r_x2);
    exit(1);
  }
  else
    printf("\tTest №%d done!\n", test_Num);
  *x1 = NAN;
  *x2 = NAN;
}


//------------------------------------------------
//! Tests different cases of quadratic equations
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//------------------------------------------------
void TestSolveSquare(double *x1, double *x2)
{
  printf("\n\n");
  printf("Two roots tests:\n");
  TestEquation(1, 1, -8, 12, TWO_ROOTS,
               2, 6, x1, x2);
  TestEquation(2, 21, -3940, 3919, TWO_ROOTS,
               1, (double)3919/21, x1, x2);
  TestEquation(3, 1, 1357, 1356, TWO_ROOTS,
               -1356, -1, x1, x2);
  printf("\n");

  printf("One root tests:\n");
  TestEquation(1, 1, -6, 9, ONE_ROOT,
               3, NAN, x1, x2);
  TestEquation(2, 0, 2, 4, ONE_ROOT,
               -2, NAN, x1, x2);
  TestEquation(3, 4, -20, 25, ONE_ROOT,
               2.5, NAN, x1, x2);
  printf("\n");

  printf("No root tests:\n");
  TestEquation(1, 5, 3, 7, NO_ROOTS,
               NAN, NAN, x1, x2);
  TestEquation(2, 0, 0, 7, NO_ROOTS,
               NAN, NAN, x1, x2);
  printf("\n");

  printf("Infinite root tests:\n");
  TestEquation(1, 0, 0, 0, INF_ROOTS,
               NAN, NAN, x1, x2);
  printf("\n");

  printf("All tests done!\n\n");
}


int main()
{
  double x1 = NAN, x2 = NAN;
  TestSolveSquare(&x1, &x2);
  return 0;
}
