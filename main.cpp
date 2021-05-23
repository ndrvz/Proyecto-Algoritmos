#include <iostream>
#include <string>
#include "encriptadores.hpp"
using namespace std;

 

int main() {
	/*string s = "gatos";
	int key = 2;

	reverseStr(s);
	vector<string> f = frases(s);
	vector<string> vec = desorden_encrypt(f, key);
	desorden_decrypt(vec, key);

	string str = cesar_encrypt(s, key);
	cesar_decrypt(str, key);

	vector<string> f = encrypt_master(s, key);
	for(unsigned i = 0; i < f.size(); i++){
		cout<<f[i];
	}
	vector<string> f2 = {"q", "v", "u", "c", "i"}; 
	string str = decrypt_master(f2, key);
	cout<<str<<endl;*/

	char message[1024];

	cout << "Enter the message to encrypt: ";
	cin.getline(message, sizeof(message));
	cout << message << endl;

	// Pad message to 16 bytes
	int originalLen = strlen((const char *)message);

	int padded_message_len = originalLen;

	if ((padded_message_len % 16) != 0) {
		padded_message_len = (padded_message_len / 16 + 1) * 16;
	}

	unsigned char * padded_message = new unsigned char[padded_message_len];
	for (int i = 0; i < padded_message_len; i++) {
		if (i >= originalLen) {
			padded_message[i] = 0;
		}
		else {
			padded_message[i] = message[i];
		}
	}

	unsigned char * encrypt = new unsigned char[padded_message_len];

	string str;
	ifstream infile;
	infile.open("keyfile", ios::in | ios::binary);

	if (infile.is_open())
	{
		getline(infile, str); // The first line of file should be the key
		infile.close();
	}

	else cout << "Unable to open file";

	istringstream hex_chars_stream(str);
	unsigned char key[16];
	int i = 0;
	unsigned int c;
	while (hex_chars_stream >> hex >> c)
	{
		key[i] = c;
		i++;
	}

	unsigned char exp_key[176];

	key_expansion(key, exp_key);

	for (int i = 0; i < padded_message_len; i += 16) {
		aes_encrypt(padded_message+i, exp_key, encrypt+i);
	}

	cout << "Encrypted message in hex:" << endl;
	for (int i = 0; i < padded_message_len; i++) {
		cout << hex << (int) encrypt[i];
		cout << " ";
	}

	cout << endl;

	// Write the encrypted string out to file "message.aes"
	ofstream outfile;
	outfile.open("message.aes", ios::out | ios::binary);
	if (outfile.is_open())
	{
		outfile << encrypt;
		outfile.close();
		cout << "Wrote encrypted message to file message.aes" << endl;
	}

	else cout << "Unable to open file";

	// Free memory
	delete[] padded_message;
	delete[] encrypt;
	return 0;
}
