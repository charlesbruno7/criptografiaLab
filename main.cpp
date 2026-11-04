#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

namespace {

int lerOpcao() {
    int opcao;
    while (!(std::cin >> opcao)) {
        std::cout << "Entrada invalida. Digite um numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcao;
}

int lerDeslocamento() {
    int valor;
    while (!(std::cin >> valor)) {
        std::cout << "Deslocamento invalido. Digite um numero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

std::string cifraCesar(const std::string& texto, int deslocamento) {
    std::string resultado = texto;
    deslocamento = ((deslocamento % 26) + 26) % 26;
    for (char& caractere : resultado) {
        const unsigned char c = static_cast<unsigned char>(caractere);
        if (c >= 'A' && c <= 'Z')
            caractere = static_cast<char>('A' + (c - 'A' + deslocamento) % 26);
        else if (c >= 'a' && c <= 'z')
            caractere = static_cast<char>('a' + (c - 'a' + deslocamento) % 26);
    }
    return resultado;
}

std::string cifraVigenere(const std::string& texto, const std::string& chave, bool decifrar) {
    std::string resultado = texto;
    std::size_t indiceChave = 0;
    for (char& caractere : resultado) {
        const unsigned char c = static_cast<unsigned char>(caractere);
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) continue;
        const unsigned char k = static_cast<unsigned char>(chave[indiceChave % chave.size()]);
        const int deslocamento = (std::tolower(k) - 'a') * (decifrar ? -1 : 1);
        const char base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';
        caractere = static_cast<char>(base + ((c - base + deslocamento + 26) % 26));
        ++indiceChave;
    }
    return resultado;
}

std::string lerTexto(const std::string& convite) {
    std::string texto;
    std::cout << convite;
    std::getline(std::cin, texto);
    return texto;
}

void executarCesar(bool decifrar) {
    const std::string texto = lerTexto("Digite a mensagem: ");
    std::cout << "Digite o deslocamento (ex.: 3): ";
    const int deslocamento = lerDeslocamento();
    std::cout << "\nResultado: " << cifraCesar(texto, decifrar ? -deslocamento : deslocamento) << "\n";
}

void executarVigenere(bool decifrar) {
    const std::string texto = lerTexto("Digite a mensagem: ");
    std::string chave = lerTexto("Digite a chave (somente letras A-Z): ");
    chave.erase(std::remove_if(chave.begin(), chave.end(), [](unsigned char c) {
        return !std::isalpha(c) || c >= 128;
    }), chave.end());
    if (chave.empty()) {
        std::cout << "A chave precisa conter ao menos uma letra de A a Z.\n";
        return;
    }
    std::cout << "\nResultado: " << cifraVigenere(texto, chave, decifrar) << "\n";
}

} // namespace

int main() {
    std::cout << "========================================\n"
                 "    LABORATORIO DE CRIPTOGRAFIA\n"
                 "========================================\n"
                 "Simulacao didatica: cifras classicas nao protegem dados reais.\n";
    while (true) {
        std::cout << "\nEscolha uma operacao:\n"
                     "  1. Cifrar com cifra de Cesar\n"
                     "  2. Decifrar com cifra de Cesar\n"
                     "  3. Cifrar com cifra de Vigenere\n"
                     "  4. Decifrar com cifra de Vigenere\n"
                     "  0. Sair\n"
                     "Opcao: ";
        const int opcao = lerOpcao();
        switch (opcao) {
            case 1: executarCesar(false); break;
            case 2: executarCesar(true); break;
            case 3: executarVigenere(false); break;
            case 4: executarVigenere(true); break;
            case 0: std::cout << "Ate logo!\n"; return 0;
            default: std::cout << "Opcao desconhecida. Tente novamente.\n";
        }
    }
}
