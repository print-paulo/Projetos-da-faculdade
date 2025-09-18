#include <iostream>
#include <string>
#include <cctype>
#include <vector>

std::string calcularAlfabetoPulado(std::string alfabetoShiftado, int pulo) {  
        std::string alfabetoPulado = "";
        
        //Verifica quando aplicar a função matemática se a letra já foi "usada"
        std::vector<bool> usado(25, false);

        //Pega as letras "puladas"
        for (int i = pulo - 1; i < 26; i += pulo) {
            alfabetoPulado += alfabetoShiftado[i];
            usado[i] = true;
        }

        //Pega as letras que sobraram e soma com as selecionadas
        for (int i = 0; i < 26; ++i) {
            if (!usado[i]) {
                alfabetoPulado += alfabetoShiftado[i];
            }
        }
        return alfabetoPulado;
    }

int main() {
    //Armazenando as variáveis
    std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    std::string alfabetoFinal = "";
    std::string textoCriptografado = "";
    std::string textoDecifrado = "";
    int shift = 0;
    //Pedindo ao usuário a palavra criptografada e o shift
    std::cout << "Digite a palavra a ser decriptografada\n";
    std::cin >> textoCriptografado; //Coleta do usuário a palavra para ser decriptografada
    std::cout << "Digite o shift (número de casas que o alfabeto se moveu para frente)\n";
    std::cin >> shift;

    //Aplica o shift ao alfabeto original
    std::string parte_final = alfabeto.substr(shift);
    std::string parte_inicial = alfabeto.substr(0, shift);
    std::string alfabetoShift = parte_final + parte_inicial;
    
    //Fazer um bruteforce com os valores de pulo
    for (int pulo = 1; pulo <= 20; ++pulo) {
        std::string alfabetoFinal = calcularAlfabetoPulado(alfabetoShift, pulo);
        std::cout << "Com pulo de " << pulo << ": " << alfabetoFinal << std::endl;
    }
    
    return 0;
}
