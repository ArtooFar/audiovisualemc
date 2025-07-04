//Biblioteca Própria //
#ifndef MISCELANEA_H
#define MISCELANEA_H
#include <stdio.h>
#include <time.h>

//pro getch
#include <conio.h>

void console_cursor_invisivel(){
    printf("\e[?25l"); // cursor invisivel
}

void console_cursor_visivel(){
    printf("\e[?25h");
}

int aleatorio(int min, int max) {
    //Obter numero aleatorio e retornar
    int aleat = (rand() % ((max+1) - min)) + min;
    return aleat;
}

void limparTela() {
//Funciona tipo um system("clear") mas com ANSII Escape Code
//Vai funcionar tanto em LINUX (replit) quanto em WINDOWS
    printf("\e[H\e[0J\e[H");
}

int getch() {
// Essa função é de uma biblioteca externa, não influencia diretamente a lógica do jogo
//Serve pra ler um input do usuário sem esperar pelo enter
// while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada

	if (_kbhit()) {
        return _getch();
	}
    return -1; 
}

void programa_finalizar () {
    
    int input;
    printf("\n\n\n");
    printf("Aperte F para encerrar o programa\n");
    
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);


}

void programa_pausar () {
    
    int input;
    printf("Aperte F para continuar...\n");
    
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);


}

void programa_iniciar () {

    FILE *arq;
    arq=fopen("ignore.txt","w");

    if(arq==NULL) printf("-> Erro - Não é possível alterar arquivos\n--> O jogo poderá ser jogado, mas nada será salvo em disco.\n");
	else fprintf(arq,"Esse é um arquivo de teste, ignore");
    int input;
    printf("Se possível, use a resolução 1280 x 720p\n");
    printf("Por favor coloque o programa em tela cheia\n");
    printf("Aperte F para continuar\n");
    
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);
}

#endif
