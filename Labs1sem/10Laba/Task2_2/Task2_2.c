#include <stdio.h>
#include <locale.h>
#include <math.h>

//fu1 = fucktorial(x);

float fucktorial(float abc) {
	float z = 1;
	for (int i = abc; i > 0; i--)
		z *= i;
	return z;
}