#include <iostream>
#include <vector>
#include <string>
using namespace std;

void desorden_encript(vector<string> &v, unsigned key) {
    for (unsigned i = 0; i < key;i++) {
      swap(v[i],v[i+1]);
    }

}


void desorden_decript(vector<string> &v, unsigned key) {
    for (unsigned i = key; i > 0 ;i--) {
      swap(v[i],v[i-1]);
    }
}


vector<string> frases(string frase){
  vector<string> oracion;
  for (unsigned i=0; i<frase.length(); i++) {
    oracion.push_back(string()+frase[i]);
  }
  
  return oracion;
}

void display(vector<string> &v){
  for(unsigned i = 0; i < v.size(); i++)
    cout << v[i];
  cout << endl;
}

int main() {
  vector<string> v;
  v.push_back("g");
  v.push_back("a");
  v.push_back("t");
  v.push_back("o");
  v.push_back("s");
  string str="hola";
  vector<string> vf=frases(str);
  desorden_encript(vf, 2);
  display(vf);
  desorden_encript(v,2);

  display(v);

  desorden_decript(v,2);

  display(v);

  return 0;
}
