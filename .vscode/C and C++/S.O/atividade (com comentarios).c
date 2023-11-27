// o operador de pipe (|), o operador de redirecionamento de saída (>) e o operador de execução
// em segundo plano (&). junto com um exemplo de codigo em C que faz uma chamada de sistema

#include <stdio.h>
#include <unistd.h>

int main() {
    char *arquivo = "exemplo.txt";

    if (access(arquivo, F_OK) == 0) {
        printf("O arquivo '%s' existe.\n", arquivo);
    } else {
        printf("O arquivo '%s' nao existe.\n", arquivo);
    }

    return 0;
}

/*Neste exemplo, é utilizada a função access() da biblioteca <unistd.h>, que é uma chamada de 
sistema que verifica se um arquivo existe e se o programa tem permissão para acessá-lo.
O primeiro argumento da função é o nome do arquivo a ser verificado, e o segundo argumento F_OK 
indica que queremos verificar a existência do arquivo.

No código acima, definimos a variável arquivo com o nome "exemplo.txt". Em seguida, utilizamos a 
função access() para verificar se o arquivo existe. Se a chamada de sistema retornar 0, significa
que o arquivo existe, e exibimos a mensagem "O arquivo 'exemplo.txt' existe.". Caso contrário, 
exibimos a mensagem "O arquivo 'exemplo.txt' não existe.".

Agora, vamos ver a execução desse código:

ruby
Copy code
$ gcc arquivo.c -o arquivo
$ ./arquivo
O arquivo 'exemplo.txt' não existe.
Neste exemplo, o arquivo "exemplo.txt" não existe no diretório em que o programa foi executado, 
então a mensagem "O arquivo 'exemplo.txt' não existe." é exibida.

Você pode modificar o valor da variável arquivo para testar a existência de outros arquivos no 
seu sistema.

Espero que isso tenha sido útil! Se você tiver mais dúvidas ou precisar de mais exemplos, fique 
à vontade para perguntar. Estou aqui para ajudar!
*/