#include <iostream>
#include <string>
#include <cctype>
#include <vector>

std::string const alfabeto = "abcdefghijklmnopqrstuvwxyz";
// Função que aplica o shift ao alfabeto
std::string aplicarShift(int shift) {
    shift = shift % 26; 
    if (shift < 0) {
        shift += 26; 
    }
    // A lógica de shift agora é executada para todos os casos
    return alfabeto.substr(shift) + alfabeto.substr(0, shift);
}
 
// Função que calcula o alfabeto pulado
std::string calcularAlfabetoPulado(std::string alfabetoShiftado,  int pulo) {
    std::string alfabetoPulado = "";
    std::vector<bool> usado(26, false);
        
    for (int i = pulo - 1; i < 26; i += pulo) {
        if (i >= 0) {
            alfabetoPulado += alfabetoShiftado[i];
            usado[i] = true;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (!usado[i]) {
            alfabetoPulado += alfabetoShiftado[i];
        }
    }
    return alfabetoPulado;
}
    

// Função que decriptografa o texto
std::string decriptografarTexto(const std::string& textoCriptografado, const std::string& alfabetoPulado) {
    std::string mensagem_decifrada = "";

    for (char caractere : textoCriptografado) {
        if (std::islower(caractere)) {
            size_t posChave = alfabetoPulado.find(caractere);
            if (posChave != std::string::npos) {
                mensagem_decifrada += alfabeto[posChave];
            } 
            else {
                mensagem_decifrada += caractere;
            }
        } 
        else if (std::isupper(caractere)) {
            char minuscula = std::tolower(caractere);
            size_t posChave = alfabetoPulado.find(minuscula);
            if (posChave != std::string::npos) {
                char decifrado = alfabeto[posChave];
                mensagem_decifrada += std::toupper(decifrado);
            } 
            else {
                mensagem_decifrada += caractere;
            }
        } 
        else {
            mensagem_decifrada += caractere;
        }
    }
    return mensagem_decifrada;
}

int main() {
    std::string textoCriptografado = "";
    int shift = 0;

    std::cout << "Digite a palavra a ser decriptografada\n";
    std::cin >> textoCriptografado; 
    
    std::cout << "Digite o shift (numero de casas que o alfabeto se moveu para frente)\n";
    std::cin >> shift;

    std::string alfabetoShiftado = aplicarShift(shift);

    std::cout << "\n------------------------------------------------\n";
    std::cout << "Tentativas de decifracao:\n";
    std::cout << "------------------------------------------------\n\n";

    for (int pulo = 1; pulo <= 26 / 2; ++pulo) {
        std::string alfabetoPulado = calcularAlfabetoPulado(alfabetoShiftado, pulo);
        std::string mensagemDecriptografada = decriptografarTexto(textoCriptografado, alfabetoPulado);
        std::cout << "Pulo " << pulo << ": " << mensagemDecriptografada << "\n";
    }
    return 0;
}