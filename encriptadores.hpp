#ifndef _encriptadores_hpp_
#define _encriptadores_hpp_

#include <bits/stdc++.h>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

/* ************************************* *
 *                                       *
 *                DESORDEN               *
 *                                       *
 * ************************************* */

vector<string> frases(string frase);
void display(vector<string> &v);
vector<string> desorden_decript(vector<string> &v, unsigned key);
vector<string> desorden_encript(vector<string> &v, unsigned key);
void reverseStr(string& str);

/* ************************************* *
 *                                       *
 *                CESAR                  *
 *                                       *
 * ************************************* */

int find_char_in_alphabet(char ch, string str);
string cesar_encript(string frase, int key);
string cesar_descript(string frase, int key);



/* ************************************* *
 *                                       *
 *                AES                    *
 *                                       *
 * ************************************* */



void key_expansion_core(unsigned char * x, unsigned char i);
void key_expansion(unsigned char* key, unsigned char* exp_key);

void add_round_key(unsigned char *state, unsigned char *rkey);
void sub_bytes(unsigned char * state);
void shift_rows(unsigned char * state);
void mix_columns(unsigned char * state);
void round(unsigned char * state, unsigned char * key);
void final_round(unsigned char * state, unsigned char * key);
void aes_encrypt(unsigned char * message, unsigned char * exp_key, unsigned char * encrypt);

void sub_round_key(unsigned char * state, unsigned char * roundKey);
void inverse_mix_columns(unsigned char * state);
void shift_rows(unsigned char * state);
void sub_bytes(unsigned char * state);
void round(unsigned char * state, unsigned char * key);
void first_round(unsigned char * state, unsigned char * key);
void aes_decrypt(unsigned char * encryptedMessage, unsigned char * expandedKey, unsigned char * decryptedMessage);


vector<string> encrypt_master(string str, int key);
string decrypt_master(vector<string> f, int key);

#endif
