
#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class numeroRomano {
private:
    int valorArabigo;
    string simbolo;
public:
    numeroRomano();
    numeroRomano(string simbolo) {
        this->valorArabigo = valorArabigo;
        this->simbolo = simbolo;
    }
    void setValor(int valorArabigo) {
        this->valorArabigo = valorArabigo;
    }
    int getValor() {
        return this->valorArabigo;
    }
    void setSimbolo(string simbolo) {
        this->simbolo = simbolo;
    }
    string getSimbolo() {
        return simbolo;
    }
    bool verificarFormato() {
        regex expresion("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
        if (regex_match(simbolo, expresion)) {
            return true;
        }
        cout << "Numero invalido" << endl;
        return false;
    }
    int toArabic() {

        valorArabigo = 0;
        vector<char> simbolos(simbolo.begin(), simbolo.end());
        vector<int> numeros(simbolos.size());
        if (!verificarFormato()) return 0;
        
        for (int i = 0; i < simbolos.size(); i++) {
            switch (simbolos[i]) {
                case 'M':
                    numeros[i] = 1000;
                    break;
                case 'D':
                    numeros[i] = 500;
                    break;
                case 'C':
                    numeros[i] = 100;
                    break;
                case 'L':
                    numeros[i] = 50;
                    break;
                case 'X':
                    numeros[i] = 10;
                    break;
                case 'V':
                    numeros[i] = 5;
                    break;
                case 'I':
                    numeros[i] = 1;
                    break;
            }
        }
        
        for (int i = 0; i < numeros.size(); i++) {
            if (i < numeros.size()-1) {
                if (numeros[i + 1] > numeros[i]) {
                    numeros[i] *= -1;
                }
            }
            else { 
                numeros[i] *= 1;
                
            }
                
            valorArabigo += numeros[i];
        }
        return valorArabigo;
    }

};



int main()
{
    string num="fgdh";
    while (num != "-") {
        cout << "Ingresa un numero romano (Ingrese '-' para salir): " << endl;
        cin >> num;
        if (num == "-") return 0;
        numeroRomano rom = numeroRomano(num);
        cout << "Romano: " << rom.getSimbolo() << endl;
        cout << "Arabigo: " << rom.toArabic() << endl;
    }
        
        



}


