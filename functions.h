#include <stdio.h>
#include <stdlib.h>

#include <assert.h>
#include <math.h>

typedef enum
{
  INF_ROOTS = -1,
  NO_ROOTS,
  ONE_ROOT,
  TWO_ROOTS
} Roots;


//------------------------------------------------
//! Solves a square equation ax2 + bx + c = 0
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns INF_N_ROOTS.
//------------------------------------------------
Roots SolveSquare(double a, double b, double c,
                  double* x1, double* x2);


//------------------------------------------------
//! Solves a linear equation bx + c = 0
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x Pointer to the root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns INF_ROOTS.
//------------------------------------------------
Roots SolveLinear(double k, double b, double* x);


//------------------------------------------------
//! Returns true if there is approximate equality
//! of two double numbers
//! @param [in] p p-first double
//! @param [in] q q-second double
//!
//! @return true if numbers are approximately
//! equal, else returns false
//!
//! @note Uses EPS = 10^(-9) constant for
//! calculating approximation
//------------------------------------------------
int is_Equal(double p, double q);
