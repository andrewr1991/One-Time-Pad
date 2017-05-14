#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

void encrypt() {
	srand(time(NULL));
  /*string file;
  cout << "Enter a file name: ";
  cin >> file;*/

  ifstream textIst{"text.txt"};
	ofstream encryptedOst{"encrypted.txt"};
	ofstream keyOst{"key.txt"};
	char c;

	while (textIst.get(c)) {
		int C;
		int r = rand() % 53 + 1;
		if ((c + r) > 126) {
			C = ((c + r) - 126);
			C += 32;
		}
		else {
			C = c + r;
		}
		keyOst << r << "\n";
		encryptedOst << (char)C;
		cout << c << " " << (int)c << " " << r << " " << C << endl;
	}
}

void decrypt() {
	ifstream keyIst{"key.txt"};
	ifstream encryptedIst{"encrypted.txt"};
	ofstream decryptedOst{"decrypted.txt"};
	string key;
	char c;
	int k;

	while (getline(keyIst, key) && encryptedIst.get(c)) {
		k = stoi(key);
		cout << c << " " << k << endl;
		if ((c - k) < 32) {
			c = 126 - (k - (c - 32));
		}
		else {
			c = (c - k);
		}
		decryptedOst << c;
	}
}

int main() {
	encrypt();
	decrypt();
  return 0;
}
