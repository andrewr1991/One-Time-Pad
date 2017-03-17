#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

string readFile(string fileName) {
	string line, text;
	ifstream file(fileName);

	while (getline(file, line)) {
		text += line;
		text += "\n";
	}
	file.close();
	return text;
}

int encrypt(string fileMsg) {
	string encryptedMsg;
	string keyText;
	ofstream encryptedFile;
	ofstream key;

	srand(time(NULL));

	for (int i = 0; i < fileMsg.length(); i++) {
		int r = rand() % 53 + 1;
		int p = fileMsg[i];
		int C = p + r;
		encryptedMsg += C;

		keyText += to_string(r) + " ";
	}
	encryptedFile.open("Encrypted_Message.txt");
	encryptedFile << encryptedMsg;
	encryptedFile.close();

	key.open("key.txt");
	key << keyText;
	key.close();

	return fileMsg.length();
}

void decrypt(string encryptedFile, string key, int msgLength) {
	ifstream file(key);
	string line;
	int value;

	ifstream encryptedFileMsg(encryptedFile);
	string line2;
	string encryptedText;

	while (getline(encryptedFileMsg, line2)) {
		encryptedText += line2;
	}

	while (getline(file, line)) {
		stringstream iss(line);

		for (int i = 0; i < msgLength; i++) {
			iss >> value;

			cout << (encryptedText[i] - value) << " ";
		}
	}
}

int main() {
	string fileName = "text.txt";

	string file = readFile(fileName);
	int messageLength = encrypt(file);

	decrypt("Encrypted_Message.txt", "key.txt", messageLength);

}
