#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

int encrypt() {
	srand(time(NULL));
  /*string file;
  cout << "Enter a file name: ";
  cin >> file;*/

  ifstream ist{"text.txt"};
	ofstream encryptedOst{"encrypted.txt"};
	ofstream keyOst{"key.txt"};
	char c;

	while (ist.get(c)) {
		int C;
		int r = rand() % 53 + 1;
		if ((c + r) > 126) {
			C = ((c + r) - 126);
			C += 32;
		}
		else {
			C = c + r;
		}
		keyOst << C << "\n";
		encryptedOst << (char)C;
		cout << c << " " << (int)c << " " << r << " " << C << endl;
	}
}

int main() {
	encrypt();
  return 0;
}
