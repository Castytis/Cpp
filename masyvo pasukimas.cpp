#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


int main()
{
	long long int n, M[100][100];
	cin >> n;
	for (int i=0; i<n; i++){
	for (int j=0; j<n; j++){
		cin >> M[i][j];
	}	
	}
	for (int i=0; i<n; i++){
	for (int j=n-1; j >= 0; j--){
		cout << M[j][i];
		if (j>0) cout << ' ';	
}
cout <<endl;
}
	
	return 0;
}
