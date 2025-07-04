//Só funciona em windows

#include <stdio.h>
#include "async.h"

// Função sem argumento
void func_semArg() {
    puts("Olá de uma thread sem argumento!");
}

// Função com argumento
// Como parâmetro, se recebe um ponteiro para um tipo qualquer, q pode deve convertido para outros tipos (preferencialmente o original) na função
void func_comArg_EX_string(void *arg) {
    char *nome = (char*) arg; //Converte em ponteiro para char
    printf("Olá, %s!\n", nome);
}

// Função com argumento
// Como parâmetro, se recebe um ponteiro para um tipo qualquer, q pode deve convertido para outros tipos (preferencialmente o original) na função
void func_comArg_EX_inteiro(void *arg) {
    int *pnum = (int*) arg; //Converte em ponteiro para inteiro
    int num = *pnum;
    printf("Número: %d da thread com argumento!\n", num);
}


// Função sem argumento que pausa o programa por 10 segundos
void func_pausar10segundos () {
    printf("Iniciando função que pausa o programa por 10 segundos...\n");
    Sleep(10000);
    printf("Pause de 10 segundos finalizado.\n");
}

int main(void) {
    // Inicia uma thread sem argumento (função: async_run0)
    // A função async_run0 aceita como parâmetro uma outra função, mas sem os ()
    async_thread_t processo_um = async_run0(func_semArg);

    
    // Inicia uma thread com argumento (função: async_run)
    // A função async_run aceita como parâmetro uma outra função, mas sem os () e o endereço de memória de uma variável qualquer
    char nome[] = "Arthur";
    async_thread_t processo_dois = async_run(func_comArg_EX_string, nome);

    int num=4;
    async_thread_t processo_tres = async_run(func_comArg_EX_inteiro, &num);

    //Inicia uma thread sem argumento que pausa o programa por 10 segundos
    async_thread_t processo_quatro = async_run(func_pausar10segundos, NULL);
    //"Separa" a função da execução da main, tornando ela "independente", roda no seu proprio tempo, enquanto a main pode prosseguir
    async_detach(processo_quatro);

    // Espera os processos 1,2,3 terminarem
    async_join(processo_um);
    async_join(processo_dois);
    async_join(processo_tres);

    printf("Todas as threads importantes acabaram! Encerrando sem esperar a função func_pausar10segundos ...");
    return 0;
}
