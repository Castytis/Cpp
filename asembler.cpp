
#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char** argv) {

	float X[4]; //sukuriamas float tipo masyvas su 4 elementais
	float Y[4];
	float Z[4];
	float res[4];

	for (short i = 1; i <= 1000; i += 4)//pradedamas dvigubas ciklas kad butu praeinami visi variantai
		for (short j = i + 1; j <= 1000; j += 4)
		{
			float x = i; // naujiem kintamiesiems priskiriami ciklo duomenys 
			float y = j;
			X[0] = x, X[1] = x + 1, X[2] = x + 2, X[3] = x + 3; // Tam masyvui, kuri pirmiau sukure, priskiriami duomenys padidinant po vienu, tam kad gautu 4 skaicius
			Y[0] = y, Y[1] = y + 1, Y[2] = y + 2, Y[3] = y + 3;

			__asm { // pradedamas asemblerio kodas
				movups xmm0, [X] // tai i xmm0 irasomi visi X masyve esantys elementai
				movups xmm1, [Y] //  i xmm1 yrasoma Y masyvo elementai
				mulps xmm0, xmm0 // pakeliama kvadratu xmm0. 
				mulps xmm1, xmm1 // pakeliama kvadratu xmm1
				addps xmm0, xmm1 // prie xmm0 pridedami xmm1, issaugoma viskas xmm0
				sqrtps xmm1, xmm0 // traukia sakni is xmm0 ir rezultata issaugo i xmm1
				roundps xmm1, xmm1, 1 //uzapvalina xmm1 reiksme  ir issaugo xmm1 kintamajame.
				movups[Z], xmm1 // perkelia xmm1 reiksmes i Z masyva
				mulps xmm1, xmm1 // pakelia xmm1 kvadratu. pakelia kvardratu
				subps xmm0, xmm1 // is xmm0 atima xmm1 ir issaugo xmm0
				movups[res], xmm0 // perkelia xmm0 reiksmes i res masyva
			}


			for (int k = 0; k<4; k++)
				if (res[k] == 0)
					printf("%.0f %.0f %.0f \n", x + k, y + k, Z[k]);
		}
	system("pause");
	return(0);
}
