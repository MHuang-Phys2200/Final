#include <math.h>
#include <gsl/gsl_errno.h>

int func (double tau, const double y[], double f[], void *params) 
{
  double Omega = *(double *) params;

  f[0] = y[1];
  f[1] = -(1. - 0.01 * Omega * Omega * sin(Omega*tau)) * sin(y[0]);
  
  return GSL_SUCCESS;
}
