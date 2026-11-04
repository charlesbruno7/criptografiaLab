# Laboratorio de Criptografia

Aplicacao interativa de terminal em C++ para explorar as cifras classicas de Cesar e Vigenere. Permite cifrar e decifrar mensagens; espacos, pontuacao e caracteres fora de A-Z sao mantidos.

## Compilar

Com um compilador C++17:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o laboratorio_criptografia
```

No Windows, o executavel gerado sera `laboratorio_criptografia.exe`. Tambem e possivel compilar com CMake:

```sh
cmake -S . -B build
cmake --build build
```

Execute o programa e siga o menu. Na cifra de Cesar, use o mesmo deslocamento para decifrar. Na cifra de Vigenere, use a mesma chave.

> OBS: Estas cifras servem para fins didaticos e nao devem ser usadas para proteger informacoes reais.
