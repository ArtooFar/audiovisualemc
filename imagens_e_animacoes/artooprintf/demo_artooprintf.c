#include <stdio.h>
#include "dependencias\configs_do_terminal.h"
#include "dependencias\ferramentas_de_terminal.h"

#include "elementosvisuais.h"

int main() {
    term_inicializar();
    term_setar_fonte(12);
    term_redimensionar(156,44);

    desenhar_luffio_gear5();
    
    term_pause("");
    // Volta o cursor para o inicio da tela
    printf("\e[H");

    term_setar_fonte(1);
    term_redimensionar(512,128);
    desenhar_luffygatito();
    term_pause("");
    


}