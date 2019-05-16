#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	long long int n, x, s[100], maz=0, did=0, tmp,k=1000;
	cin >> x >> n;
	
	for (int f = 0; f < n-1 && x!=6174;f++) {
		for (int i = 0; i < 4; i++) {
			s[i] = x % 10;
			x = x / 10;
		}
		for (int i = 0; i<4 - 1; i++) {
			for (int j = 0; j<4 - i - 1; j++) {

				if (s[j] > s[j + 1]) {

					tmp = s[j];

					s[j] = s[j + 1];

					s[j + 1] = tmp;

				}

			}
		}
		k=1000;
		did=0;
		for (int i = 0; i < 4; i++) {
			did = did + s[i] * k;
			k = k / 10;
		}
		for (int i = 0; i<4 - 1; i++) {
			for (int j = 0; j<4 - i - 1; j++) {

				if (s[j] < s[j + 1]) {

					tmp = s[j];

					s[j] = s[j + 1];

					s[j + 1] = tmp;

				}

			}
		}
		k = 1000;
		maz=0;
		for (int i = 0; i < 4; i++) {
			maz = maz + s[i] * k;
			k = k / 10;
		}
		x = maz-did;
	}
	cout << x << "\n";



	return 0;
}
