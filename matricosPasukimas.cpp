#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int arr[101][101], N;
	long long K;
	ifstream ifs("15.txt");
	ofstream ofs("15");
	ifs >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ifs >> arr[i][j];
		}
	}
	if (K % 4 == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ofs << arr[i][j] << " ";
			}
			ofs << "\n";
		}
	}
	else if (K % 4 == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ofs << arr[N - j - 1][i] << " ";
			}
			ofs << "\n";
		}
	}
	else if (K % 4 == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ofs << arr[N - i - 1][N - j - 1] << " ";
			}
			ofs << "\n";
		}
	}
	else if (K % 4 == 3) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ofs << arr[j][N - i - 1] << " ";
			}
			ofs << "\n";
		}
	}
    return 0;
}
