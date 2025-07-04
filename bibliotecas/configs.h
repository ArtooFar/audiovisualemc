//Biblioteca Própria //
#ifndef CONFIGS_H
#define CONFIGS_H

typedef struct {
	int debug, modoDeSalvamento, nplayersdebug, VolumeFundo, VolumeEfeito, loopMusica, dinheiroInicial, apostaMinimaInicial,trilhaAlternativa;
}opc;

void arq_atualizarOpcoes (opc *opcoes) {
    // Função para gerar o conteudo de opcoes.txt com conteúdo obtido in-game
    FILE *arq;
    arq=fopen("opcoes.txt","w");
    if (arq) {
        fprintf(arq,"--- Opções ---\n\n");
        fprintf(arq,"//Volume da música de fundo ( 70 [Padrão])\n");
        fprintf(arq,"VolumeFundo = %d\n\n",opcoes->VolumeFundo);
        fprintf(arq,"//Volume dos efeitos sonoros ( 100 [Padrão])\n");
        fprintf(arq,"VolumeEfeito = %d\n\n",opcoes->VolumeEfeito);
        fprintf(arq,"//Com quanto dinheiro cada player começa? ( 1000 [Padrão])\n");
        fprintf(arq,"DinheiroInicial = %d\n\n",opcoes->dinheiroInicial);
        fprintf(arq,"//Qual o valor mínimo da primeira aposta do jogo? ( 10 [Padrão])\n");
        fprintf(arq,"ApostaMinimaInicial = %d\n\n",opcoes->apostaMinimaInicial);
        fprintf(arq,"// Seleciona como será formatado o .txt que salva o histórico cada partida ( 1 = Data e Hora [Padrão] / 0 = partida.txt )\n");
        fprintf(arq,"ModoDeSalvamento = %d\n\n",opcoes->modoDeSalvamento);
        
        fprintf(arq,"//Modo de debug ( 0 = Desativado [Padrão] / 1 = Simples / 2 = Facilita Testes)\n");
        fprintf(arq,"// Simples -> prinfs de avisos e monitoramento\n");
        fprintf(arq,"//Facilita Testes -> Simples + pula partes do jogo para facilitar os testes\n");
        fprintf(arq,"debug = %d\n\n",opcoes->debug);
        fprintf(arq,"//Número de Players do Modo Debug ( 6 = [Padrão])\n");
        fprintf(arq,"// Só é utilizado no modo debug 2\n");
        fprintf(arq,"NumeroDePlayersDebug = %d\n\n",opcoes->nplayersdebug);

        fprintf(arq,"//Trilha Sonora Alternativa [Secreta] ( 0 = Desativado [Padrão] / 1 = Ativado)\n");
        fprintf(arq,"TrilhaAlternativa = %d\n",opcoes->trilhaAlternativa);
        
        fprintf(arq,"\n\n\n\n\n\n//-->Esse código foi feito para rodar em sistemas Windows e é onde funciona normalmente\n");
        fclose(arq);
    }
}

void config_inverter(int *a) {
	//Inverte uma configuração/booleano entre 0 e 1
	if (*a==1) *a=0;
	else *a=1; 
}

void config_alternar(int *a,int numeroDeEstados) {
	//Alterna uma configuracão em inteiros entre 0 a numeroDeEstados
	if (((*a)+1)<numeroDeEstados) *a+=1;
	else *a=0; 
}

void config_alternar_semZero(int *a,int numeroDeEstados) {
	//Alterna uma configuracão em inteiros entre 0 a numeroDeEstados
	if (((*a)+1)<=numeroDeEstados) *a+=1;
	else *a=1; 
}

void config_inicializacao(opc *opcoes) {
    //Definir Seed como Tempo
    srand(time(NULL));
    //Obter variáveis guardadas em opcoes.txt
    if (!arq_lerOpcoes(&opcoes->debug,"debug = ","debug = %d")) opcoes->debug = 0;

    if (!arq_lerOpcoes(&opcoes->modoDeSalvamento,"ModoDeSalvamento = ","ModoDeSalvamento = %d")) opcoes->modoDeSalvamento = 1;

    if (!arq_lerOpcoes(&opcoes->nplayersdebug,"NumeroDePlayersDebug = ","NumeroDePlayersDebug = %d")) opcoes->nplayersdebug = 6;

    if (!arq_lerOpcoes(&opcoes->VolumeFundo,"VolumeFundo = ","VolumeFundo = %d")) opcoes->VolumeFundo = 70;

    if (!arq_lerOpcoes(&opcoes->VolumeEfeito,"VolumeEfeito = ","VolumeEfeito = %d")) opcoes->VolumeEfeito = 100;

    if (!arq_lerOpcoes(&opcoes->dinheiroInicial,"DinheiroInicial = ","DinheiroInicial = %d")) opcoes->dinheiroInicial = 1000;

    if (!arq_lerOpcoes(&opcoes->apostaMinimaInicial,"ApostaMinimaInicial = ","ApostaMinimaInicial = %d")) opcoes->apostaMinimaInicial = 10;

    if (!arq_lerOpcoes(&opcoes->trilhaAlternativa,"TrilhaAlternativa = ","TrilhaAlternativa = %d")) opcoes->trilhaAlternativa = 0;
}

void config_impressao(opc *opcoes,int pos,tp_carta baralho[]) {
	//Imprime o menu de configuração
	limparTela();
	int cor[6]={39,39,39,39,39,39};
	cor[pos] = 31;

	printf("===================================================================\n");
	printf("=----------------------------\e[1mOPÇÕES\e[22m-------------------------------=\n");
	printf("===================================================================\n");
	printf("=        0 = Falso/Desativado | 1 = Verdadeiro/Ativado            =\n");
	printf("===================================================================\n");
	printf("=           Use WASD para navegar e F para selecionar             =\n");
	printf("===================================================================\n");
	printf("\e[%dm => \e[1mVolume da música de fundo = <- %d ->\e[39m\e[22m\n",cor[0],opcoes->VolumeFundo);
	printf("\e[33m// Varia de 0-100 \e[3m( \e[93m70 [Padrão]\e[33m )\e[39m\e[23m\n");
    printf("\e[33m// Use A e D para aumentar/diminuir o valor\e[39m\n");
	printf("===================================================================\n");
	printf("\e[%dm => \e[1mVolume dos efeitos sonoros = <- %d ->\e[39m\e[22m\n",cor[1],opcoes->VolumeEfeito);
	printf("\e[33m// Varia de 0-100 \e[3m( \e[93m100 [Padrão]\e[33m )\e[39m\e[23m\n");
    printf("\e[33m// Use A e D para aumentar/diminuir o valor\e[39m\n");
	printf("===================================================================\n");
	printf("\e[%dm => \e[1mDinheiro Inicial de cada Player = <- %d ->\e[39m\e[22m\n",cor[2],opcoes->dinheiroInicial);
	printf("\e[33m// Varia de 0-10000 \e[3m( \e[93m1000 [Padrão]\e[33m )\e[39m\e[23m\n");
    printf("\e[33m// Use A e D para aumentar/diminuir o valor\e[39m\n");
	printf("===================================================================\n");
	printf("\e[%dm => \e[1mAposta Mínima do Primeiro Round = <- %d ->\e[39m\e[22m\n",cor[3],opcoes->apostaMinimaInicial);
	printf("\e[33m// Varia de 0-10000 \e[3m( \e[93m10 [Padrão]\e[33m )\e[39m\e[23m\n");
    printf("\e[33m// Use A e D para aumentar/diminuir o valor\e[39m\n");
	printf("===================================================================\n");
    printf("\e[%dm => \e[1mModo de Salvamento = %d\e[39m\e[22m\n",cor[4],opcoes->modoDeSalvamento);
	printf("\e[33m// Seleciona a formatação do .txt que salva o histórico\e[39m\n");
	printf("\e[33m//\e[3m ( \e[93m1 = Data e Hora [Padrão]\e[33m / 0 = partida.txt)\e[39m\n\e[23m");

	printf("===================================================================\n");

	printf("\n\n\e[%dmSalvar configurações e reiniciar o programa\e[39m\n",cor[5]);
}

int config_navegar (tp_cursor *cursor,opc *opcoes,tp_carta baralho[]) {
	//Função para permitir a navegação no menu de configuração usando W,S e F
	// W = 119
	// S = 115
	// F = 102
    // A = 97
    // D = 100
	// Conforme navegador muda de valor, é como se indicasse qual opção ta com o mouse em cima
	// O F serve pra confirmar a seleção
	// A posição 0 é a mais alta
	int numeroDeOpcoes=6;
	config_impressao(opcoes,cursor->navegador,baralho);

    audio_setar_volume_efeito(opcoes->VolumeEfeito);
    audio_setar_volume_fundo(opcoes->VolumeFundo);

    
    int input;
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 119 && input != 115 && input != 102 && input != 120 && input != 97 && input != 100);

    audio_stop("selecao");
    audio_play("selecao",0);

    switch(input) {
        case 97:
            switch(cursor->navegador){
                case 0:
                if ((opcoes->VolumeFundo-5)>=0) opcoes->VolumeFundo-=5;
                break;

                case 1:
                if ((opcoes->VolumeEfeito-5)>=0) opcoes->VolumeEfeito-=5;
                break;

                case 2:
                if ((opcoes->dinheiroInicial-10)>=0) opcoes->dinheiroInicial-=10;
                break;

                case 3:
                if ((opcoes->apostaMinimaInicial-5)>=0) opcoes->apostaMinimaInicial-=5;
                break;
            }
        break;

        case 100:
            switch(cursor->navegador){
                case 0:
                if ((opcoes->VolumeFundo+5)<=100) opcoes->VolumeFundo+=5;
                break;

                case 1:
                if ((opcoes->VolumeEfeito+5)<=100) opcoes->VolumeEfeito+=5;
                break;

                case 2:
                if ((opcoes->dinheiroInicial+10)<=10000) opcoes->dinheiroInicial+=10;
                break;

                case 3:
                if ((opcoes->apostaMinimaInicial+5)<=10000) opcoes->apostaMinimaInicial+=5;
                break;
            }
        break;
        
        case 119:
        	if ((cursor->navegador - 1)>=0) cursor->navegador-=1;
			else cursor->navegador=(numeroDeOpcoes-1);
        break;

        case 115:
        	if ((cursor->navegador + 1) < numeroDeOpcoes) cursor->navegador+=1;
			else cursor->navegador=0;
        break;

        case 102:
			switch (cursor->navegador) {

				case 4:
					config_inverter(&opcoes->modoDeSalvamento);
				break;

				case 5:
					arq_atualizarOpcoes(opcoes);
					return 1;
				break;
			}
        break;

        case 120:
        arq_atualizarOpcoes(opcoes);
        return 1;
    }

	return 0;
}


//CONFIGURAÇÕES TERMINAL--------------------------------------------------------------------------------------

void windowsconfig() {
    // Essa função é de uma biblioteca externa, não influencia diretamente a lógica do jogo
    // Configuração de Console pro Windows (Cores, ANSI Escape Code e Tamanho) -------------

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    // Habilita processamento de ANSI Escape Sequences
    if (GetConsoleMode(hOut, &dwMode)) {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }

    // Define código de página UTF‑8
    SetConsoleOutputCP(CP_UTF8);

    // Redimensiona buffer e janela para 100 colunas × 40 linhas
    COORD newSize = { 156, 44 };
    // Ajusta o tamanho do buffer de tela
    SetConsoleScreenBufferSize(hOut, newSize);

    // Define a área visível da janela igual ao tamanho do buffer
    SMALL_RECT displayArea = {
        0,               // Left
        0,               // Top
        newSize.X - 1,   // Right
        newSize.Y - 1    // Bottom
    };
    SetConsoleWindowInfo(hOut, TRUE, &displayArea);
}


#endif