#include <stdio.h>
#include "..\dependencias\configs_do_terminal.h"
#include "..\dependencias\ferramentas_de_terminal.h"

int main() {
    term_inicializar();

    int hori=20;
    int vert=20;
    int atu=1;
    int input=-1;
    int fonte=16;

    while (1) {

        input = term_ferr_tecla_pressionada();
        switch (input) {
            
            case 'd':
                hori++;
                atu=1;
                break;
            case 'D':
                hori++;
                atu=1;
                break;

            case 'a':
                if(hori!=0) hori--;
                atu=1;
                break;
            case 'A':
                if(hori!=0) hori--;
                atu=1;
                break;

            case 's':
                vert++;
                atu=1;
                break;
            case 'S':
                vert++;
                atu=1;
                break;
                
            case 'w':
                if(vert!=0) vert--;
                atu=1;
                break;
            case 'W':
                if(vert!=0) vert--;
                atu=1;
                break;

            case 'g':
                fonte++;
                atu=1;
                break;
            case 'G':
                fonte++;
                atu=1;
                break;
                
            case 'f':
                if(fonte!=0) fonte--;
                atu=1;
                break;
            case 'F':
                if(fonte!=0) fonte--;
                atu=1;
                break;

            case -1:
            break;
        }


        if (atu) {
            term_ferr_limparTela();
            term_setar_fonte(fonte);


            printf("█");
            for(int i=0;i<hori;i++) printf(" ");
            printf("█\n");

            for (int i=0;i<vert;i++) printf("\n");
            
            printf("█");
            for(int i=0;i<hori;i++) printf(" ");
            printf("█");

            printf("\e[H\e[2CHorizontal: %d\n\e[2CVertical: %d\n\e[2CFonte: %d\n\e[2CWASD = Alterar Tamanho da Área\n\e[2CF e G = Alterar Fonte",hori+2,vert+2,fonte);
            atu=0;
        }
    }
term_pause(NULL);
}