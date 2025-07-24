#include <stdio.h>
#include "dependencias\configs_do_terminal.h"
#include "dependencias\ferramentas_de_terminal.h"

#include "elementosvisuais.h"

int main() {
    //Configura o terminal para funcionar com os ansi escape sequence
    term_inicializar();
    //Seta a fonte do terminal para 12, se possível
    term_setar_fonte(12);
    //Redimensiona o terminal para 156x44 caracteres, se possível
    term_redimensionar(156,44);

    //Imprime o luffy
    desenhar_luffio_gear5();
    
    // Função de ferramentas_de_terminal.h -> pausa o programa enquanto nenhuma tecla é apertada
    // (Parâmetro = string)
    term_pause("Pressione alguma tecla");

    // Volta o cursor para o inicio da tela
    printf("\e[H");

    term_setar_fonte(1);
    term_redimensionar(512,128);
    desenhar_luffygatito();
    term_pause("");
    


}