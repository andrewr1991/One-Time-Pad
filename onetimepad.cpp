#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

int encrypt() {
  string file;
  cout << "Enter a file name: ";
  cin >> file;

  ifstream ist{file};

	srand(time(NULL));

	while (!ist.oef()) {
		int r = rand() % 53 + 1;
		int p = fileMsg[i];
		int C;

		if ((p + r) > 128) {
			C = ((p + r) - 53);
		}
		else {
			C = p + r;
		}

		encryptedMsg += C;
	}
}

int main() {
  return 0;
}
