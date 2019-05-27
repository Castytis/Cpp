// pitagoro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <cmath>

int main(int argc, char** argv) {

	float X[4]; 
	float Y[4];
	float Z[4];
	float res[4];

	for (short i = 1; i <= 1000; i += 4)
		for (short j = i + 1; j <= 1000; j += 4)
		{
			float x = i; 
			float y = j;
			X[0] = x, X[1] = x + 1, X[2] = x + 2, X[3] = x + 3; 
			Y[0] = y, Y[1] = y + 1, Y[2] = y + 2, Y[3] = y + 3;




			__asm { 
				movups xmm0, X 
				movups xmm1, Y
				mulps xmm0, xmm0 
				mulps xmm1, xmm1 
				addps xmm0, xmm1 
				sqrtps xmm1, xmm0 
				roundps xmm1, xmm1, 5
				movups[Z], xmm1 
				mulps xmm1, xmm1
				subps xmm0, xmm1 
				movups res, xmm0 
			}


			for (int k = 0; k < 4; k++)
				if (res[k] == 0)
					printf("%.0f %.0f %.0f \n", x + k, y + k, Z[k]);
		}
	system("pause");
	return(0);
}
