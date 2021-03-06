#include <stdio.h>
#include <math.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>

int func (double tau, const double y[], double f[], void *params);

int main (void) 
{
  size_t neqs = 4;          /* number of equations */
  double eps_abs = 1.e-8, 
    eps_rel = 0.;           /* desired precision */
  double stepsize = 1e-6;   /* initial integration step */
  double Omega = 200.;      /* frequency */
  double t = 0., t1 = 40.; /* time interval */
  int status;
  /* 
   * Initial conditions 
   */
  double y[2] = { 0.99*M_PI, 0. };

  /*
   * Explicit embedded Runge-Kutta-Fehlberg (4,5) method. 
   * This method is a good general-purpose integrator.
   */
  gsl_odeiv2_step    *s = gsl_odeiv2_step_alloc 
                            (gsl_odeiv2_step_rkf45, neqs);
  gsl_odeiv2_control *c = gsl_odeiv2_control_y_new (eps_abs, 
						    eps_rel);
  gsl_odeiv2_evolve  *e = gsl_odeiv2_evolve_alloc (neqs);
    
  gsl_odeiv2_system sys = {func, NULL, neqs, &Omega};
    
  /*
   * Evolution loop 
   */
  while ( (t < t1) )
  {
    status = gsl_odeiv2_evolve_apply (e, c, s, &sys, &t, t1, &stepsize, y);

    if (status != GSL_SUCCESS) {
      printf ("Troubles: % .5e  % .5e  % .5e\n", t, y[0], y[1]);
      break;
    }

    printf ("% .5e  % .5e  % .5e\n", 	      
            t, y[0], y[1]);
  }

  gsl_odeiv2_evolve_free (e);
  gsl_odeiv2_control_free (c);
  gsl_odeiv2_step_free (s);

  return 0;
}


