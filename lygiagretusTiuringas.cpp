l#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string busena1[100], busena2[100], busena3[100], busena4[100];
	string naujabusena1[100], naujabusena2[100], naujabusena3[100], naujabusena4[100];
	char reiksme1[100], reiksme2[100], reiksme3[100], reiksme4[100];
	char naujareiksme1[100], naujareiksme2[100], naujareiksme3[100], naujareiksme4[100];
	char kryptis1[100], kryptis2[100], kryptis3[100], kryptis4[100];
	int n1, n2, n3, n4;
	string pozicija1("0"), pozicija2("0"), pozicija3("0"), pozicija4("0"), juosta1, juosta2, juosta3, juosta4;


	ifstream fd1("1.txt");
	ifstream fd2("2.txt");
	ifstream fd3("3.txt");
	ifstream fd4("4.txt");

	fd1 >> n1;
	fd1 >> juosta1;

	fd2 >> n2;
	fd2 >> juosta2;

	fd3 >> n3;
	fd3 >> juosta3;

	fd4 >> n4;
	fd4 >> juosta4;

	int i = 0;
	while (!fd1.eof())
	{

		fd1 >> busena1[i] >> reiksme1[i] >> naujareiksme1[i] >> kryptis1[i] >> naujabusena1[i];
		i++;
	}
	fd1.close();
	i = i - 1;

	int y = 0;
	while (!fd2.eof())
	{

		fd2 >> busena2[y] >> reiksme2[y] >> naujareiksme2[y] >> kryptis2[y] >> naujabusena2[y];
		y++;
	}
	fd2.close();
	y = y - 1;

	int x = 0;
	while (!fd3.eof())
	{

		fd3 >> busena3[x] >> reiksme3[x] >> naujareiksme3[x] >> kryptis3[x] >> naujabusena3[x];
		x++;
	}
	fd3.close();
	x = x - 1;

	int p = 0;
	while (!fd4.eof())
	{

		fd4 >> busena4[p] >> reiksme4[p] >> naujareiksme4[p] >> kryptis4[p] >> naujabusena4[p];
		p++;
	}
	fd4.close();
	p = p - 1;

	while (true)
	{
		for (int k = 0; k<i; k++)
		{
			if (((busena1[k]) == pozicija1) && (reiksme1[k] == juosta1[n1 - 1]))
			{
				juosta1[n1 - 1] = naujareiksme1[k];
				if (kryptis1[k] == 'R')
				{
					n1++;
				}
				else if (kryptis1[k] == 'L')
				{
					n1--;
				}
				pozicija1 = naujabusena1[k];

				cout << "1 " << juosta1 << endl;
				k = i;
			}
		}

		for (int m = 0; m<y; m++)
		{
			if (((busena2[m]) == pozicija2) && (reiksme2[m] == juosta2[n2 - 1]))
			{
				juosta2[n2 - 1] = naujareiksme2[m];
				if (kryptis2[m] == 'R')
				{
					n2++;
				}
				else if (kryptis2[m] == 'L')
				{
					n2--;
				}
				pozicija2 = naujabusena2[m];
				cout << "2 " << juosta2 << endl;
				m = y;
			}
		}

		for (int m = 0; m<x; m++)
		{
			if (((busena3[m]) == pozicija3) && (reiksme3[m] == juosta3[n3 - 1]))
			{
				juosta3[n3 - 1] = naujareiksme3[m];
				if (kryptis3[m] == 'R')
				{
					n3++;
				}
				else if (kryptis3[m] == 'L')
				{
					n3--;
				}
				pozicija3 = naujabusena3[m];
				cout << "3 " << juosta3 << endl;
				m = x;
			}
		}

		for (int m = 0; m<p; m++)
		{
			if (((busena4[m]) == pozicija4) && (reiksme4[m] == juosta4[n4 - 1]))
			{
				juosta4[n4 - 1] = naujareiksme4[m];
				if (kryptis4[m] == 'R')
				{
					n4++;
				}
				else if (kryptis4[m] == 'L')
				{
					n4--;
				}
				pozicija4 = naujabusena4[m];
				cout << "4 " << juosta4 << endl;
				m = p;
			}
		}
		system("CLS");
	}
	return 0;
}
