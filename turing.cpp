#include <iostream>
#include <fstream> //nuskaito faila
#include <string>
using namespace std;

struct Taisykles {
	string dabartinisnr;
	char dabartiniss;
	char kitass;
	char kryptis;
	string naujasnr;
};
int main()
{
	int n1, i(0);
	string eil1;
	Taisykles A[300];
	ifstream fd("2.txt"); //nuskaito faila
	fd >> n1; //nuskaito ilgi?
	fd >> eil1; // nuskaito juostà
	while (!fd.eof()) //kol nepasibaigia tekstas
	{
		fd >> A[i].dabartinisnr;
		fd >> A[i].dabartiniss;
		fd >> A[i].kitass;
		fd >> A[i].kryptis;
		fd >> A[i].naujasnr;
		/*if (A[i].naujasnr == "X")
		{
		A[i].naujasnr = -1;
		break;
		}*/
		i++;
	}
	i--;

	int ilgis1 = eil1.length();        // juostos ilgis
	string temp1 = "0";                // laikinis pradinis taskas
	while (n1 != eil1[ilgis1 - 1])        // kol n1 nelygu pabaigai daro while
	{
		for (int g = 0; g<i; g++)           // i taisykliu skaicius eilutemis
		{
			if (A[g].dabartinisnr == temp1)     // ar dabartinis numeris sutampa su laikinu
			{
				if (A[g].dabartiniss == eil1[n1])       // ar dabartinis skaicius su pirmu nariu
				{
					eil1[n1] = A[g].kitass;          // skaiciu pakeiti i kita pagal taisykle
					temp1 = A[g].naujasnr;                // laikinas pasikeicia i nauja
					if (A[g].kryptis == 'R')           // tikrinama krypits
						n1++;    //kad eitu i deðinæ
					else if (A[g].kryptis == 'L')
						n1--;
				}
			}
		}
		cout << eil1 << endl; //ismetineja eilute be galo

							  //system("cls");
	}


	//system ("pause");
	return 0;
}
