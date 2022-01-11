#include <stdio.h>
#include <math.h>



double f(double x){
	return (x * x * x) - x - 1; //our lovely polynomial
}


void main(){
	double iA = 0, iB = 2;//initial interval
	
	double a = iA, b = iB;// a and b
	double c = 0, fa = 0, fb = 0, fc = 69420; // some random large value for fc because line 23, when fc is 0 we have found a root
	const double eps = 0.000001;//10^-6 , the tolerance for fc = 0
	int i = 0;
	
	
	printf("\n\nFalse Position Method\n\n");
	printf("a\t\tb\t\tc\t\tf(c)\n");
	printf("__________________________________________________________\n");
	while(fabs(fc) > eps){	//while we have not found a root
		fa = f(a);
		fb = f(b);
		c = b - fb * (b - a) / (fb - fa);//calculating x-intercept of secant line, standard formula
		fc = f(c); //new fc found
		printf("%lf\t%lf\t%lf\t", a, b, c);
		printf("%lf\t\n", fc);
		if(fc*fa>=0) //adjusting brackets
			a = c;
		else
			b = c;
		i++;
	}
	printf("\n%d iterations\n", i);
	printf("\nRoot obtained as : %lf\t", c);
	printf("Tolerance : %lf\n\n", eps);
}


