#include <stdio.h>
#include "..\dependencias\configs_do_terminal.h"
#include "..\dependencias\ferramentas_de_terminal.h"


int main (){
    int input=-1;
    int ultimoinput=-1;
    int atualizar=0;
    while (1) {
        ultimoinput=-1;
        input = term_ferr_tecla_pressionada();

        atualizar = (ultimoinput == input) ? 0 : 1; //Se ultimoinput == input, atualizar = 0, se não, = 1

        if (atualizar) {
            term_ferr_limparTela();
            if (input > -1) printf("Tecla pressionada: %c | Ascii: %d",input,input);
            else printf("Nenhuma tecla pressionada"); //"\e[H" reseta o cursor pro inicio;
        }

    }
}