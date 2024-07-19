#include "functions.h"


int is_Equal(double p, double q)
{
  if(isnan(p) && isnan(q))
  {
    return 1;
  }
  const double EPS = 10e-9;
  return (p - q) < fabs(EPS);
}


Roots SolveLinear(double b, double c, double* x)
{
  assert(isfinite(b));
  assert(isfinite(c));
  assert(x != NULL);

  if (is_Equal(b, 0))
  {
    if (is_Equal(c, 0))
      return INF_ROOTS;
    return NO_ROOTS;
  }

  *x = (-c) / b;
  return ONE_ROOT;
}


Roots SolveSquare(double a, double b, double c,
                  double *x1, double *x2)
{
  assert(isfinite(a));
  assert(isfinite(b));
  assert(isfinite(c));

  assert(x1 != NULL);
  assert(x2 != NULL);
  assert(x1 != x2);

  if (is_Equal(a, 0))
    return SolveLinear(b, c, x1);

  double d = (b * b) - (4 * a * c);
  if (d < 0)
    return NO_ROOTS;
  else if (is_Equal(d, 0))
  {
    *x1 = (-b) / (2 * a);
    return ONE_ROOT;
  }
  double d_Sqrt = sqrt(d);
  *x1 = (-b - d_Sqrt) / (2 * a);
  *x2 = (-b + d_Sqrt) / (2 * a);
  return TWO_ROOTS;
}
