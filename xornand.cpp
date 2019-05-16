#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	int rez, rez1, rez2, laikinas, laikinas2, laikinas3;
	//cin >> a >> b;
	//cout << atoi(argv[1]) << " " << atoi(argv[2]) << endl;
	rez = a ^ b;
	rez = atoi(argv[1]) ^ atoi(argv[2]);
	cout << "Naudojant XoR operacija: " << rez << endl;

	rez1 = (atoi(argv[1]) | atoi(argv[2])) &(~(atoi(argv[1]) & atoi(argv[2])));
	cout << "Naudojant formule : " << rez1 << endl;

	laikinas = ~(atoi(argv[1])&atoi(argv[2]));
	laikinas2 = ~(atoi(argv[1]) & laikinas);
	laikinas3 = ~(atoi(argv[2]) & laikinas);
	rez2 = ~(laikinas2 & laikinas3);
	cout << "Naudojant schema : " << rez2 << endl;
	return 0;
}
