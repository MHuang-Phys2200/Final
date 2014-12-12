/* 
 * Monte Carlo calculation SE volume
 */
#include <stdio.h>
#include<math.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_statistics.h>
     
/* mc_se.c */
double mc_se (long m, int n, gsl_rng *r);

#define NEXP 64           /* number of experiments for each value of points */
#define M 11              /* number of different points values */

int main(void) 
{
    double vol[NEXP];      /* calculated values of SE */
    gsl_rng *r;
    double mean, sd;
    int j, n;
    unsigned long seed = 1UL;
    long p = pow(2, 19.);;
     
    /* allocate random number generator */
    r = gsl_rng_alloc(gsl_rng_taus2);

    /* seed the random number generator */
    gsl_rng_set(r, seed);

	for (n = 1; n < 10; n++) 
	{
        for (j = 0; j < NEXP; j++) 
        {
            /* calculate pi using Monte Carlo algorithm */
            vol[j] = mc_se(p, n, r);
        }
        mean = gsl_stats_mean(vol, 1, NEXP);
        sd = gsl_stats_sd_m(vol, 1, NEXP, mean);
        printf("%15ld   %15d   %14.8f   %14.8f\n", p, n, mean, sd);
	}
    gsl_rng_free(r);

    return(0);
}

