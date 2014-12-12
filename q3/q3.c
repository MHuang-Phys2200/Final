#include <stdio.h>
#include <math.h>

int main(void)
{
	float s, err, errmax, w;
	float exact = pow(M_PI, 4.)/90.;
	int n = 10;
	int nrep = 10;
	int i, k;

	/* estimate machine epsilon */
	float macheps = 1.;
	while ((float) (1. + macheps) != 1.)
	{
		macheps /= 2;
	}
	printf("macheps = %g\n", macheps);
	errmax = 3* macheps;
	
	/* calculating the sum of the series */
	for( i = 0; i < nrep; i++)
	{
		while (err > errmax)
		{
			s = 0.;
			for(k = n; k  > 0; k--)
			{
				w = 1./k;
				s += w*w*w*w;
			}
			err = fabs(s - exact);
			printf( "%12d %g %g %g %g\n", n, s, exact, err, errmax);
			n *= 2;
		}
	}	
	
	return 0;
}

