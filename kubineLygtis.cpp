#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int A, B, C, D, p, k =0;
	cin >> A >> B >> C >> D;
	
	for (int i= -1000; i <= 1000; i++){
		if (((A*pow(i,3))+(B*pow(i, 2))+(C*i)+D)==0){
			k ++;
			p =i;
			if (k == 1){
				cout << p;
			}
			if (k ==2){
				cout <<"_" <<p;
			}
			else if (k ==3){
				cout <<"_"<<p;
			}
		}
	}
	return 0;
}
