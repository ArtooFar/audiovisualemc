//Biblioteca Própria //
#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <stdio.h>
#include <time.h>

int str_iniciaCom(char stringA[],char stringB[]) {
// Função que compara se stringA inicia com stringB e retorna 1 caso seja verdade;
// EXEMPLO: str_iniciaCom("TesteEscrito","Teste")
    if(strncmp(stringA, stringB, strlen(stringB)) == 0 ) return 1; 
    else return 0;

}

int arq_gerar(char principal[], char arqmontado[],int modo) {
// A partir de um nome, arq_gerar gera o nome de arquivo em "arquivo.txt"
// arq_gerar (string contendo o nome, string que receberá o nome de arquivo, modo de operação)
// Modos de operação:
// 1 -> gera o nome do arquivo sem nenhuma mudança
// 2 -> gera o nome do arquivo considerando se o arquivo já existe. Se já existir o arquivo "exemplo.txt" será criado "exemplo1.txt"

    // Modo 1
    if (modo==1) {
        sprintf(arqmontado,"saves/%s.txt",principal);
        return 1;
    }

    // Modo 2
    else if (modo==2) {
        int cont=0; char scont[20];

        do {
            sprintf(arqmontado,"saves/%s%d.txt",principal,cont);

            cont++;
            sprintf(scont,"%d",cont);

        } while ((fopen(arqmontado,"r") != NULL));
        return 1;
    }

    else return 0;

}

int arq_ler(int limite, char arq_nome[]) {
// Função que lê todo um arquivo txt linha por linha
// Recebe uma string que armazenará o conteúdo até o caractere [limite] da linha atual, do arquivo arq_nome.

    char linha[limite+1];
    FILE *arquivo;
    arquivo=fopen(arq_nome,"r");

    if (arquivo) {
        while  (fgets(linha, limite, arquivo) ) printf("%s",linha); 
        fclose(arquivo); 
        return 1;

    } else return 0;

}

void arq_obterData(char arq_nome[]) {
    // Ele retorna em arq_nome DD-MM-YYYY-HH-MM-SS

    // Essa função é de uma biblioteca externa, não influencia diretamente a lógica do jogo
    time_t agora = time(NULL);
    struct tm infoTempo;
    char buffer[20];  // Espaço para "DD-MM-YYYY-HH-MM-SS" + '\0'

    // No windows, usa gmtime_s e ajusta para GMT-3.
    gmtime_s(&infoTempo, &agora);
    infoTempo.tm_hour -= 3;
    // Normaliza se necessário (mktime ajusta os campos)
    mktime(&infoTempo);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y-%H-%M-%S", &infoTempo);
    strcpy(arq_nome, buffer);
}


int arq_gerarcData(char arq_nome[]) {
//Função que coloca na string "arq_nome" uma string no formato DD-MM-YYYY-HH-MM-SS.txt e gera esse arquivo

    arq_obterData(arq_nome);
    if (strcmp(arq_nome,"") == 0) {
        printf("\x1b[1;91m// ERRO // ERRO // ERRO // ERRO //\n");
        printf("-> Erro na geração de arquivo para salvamento de histórico.\n");
        printf("-> O programa ainda funcionará.\n");
        printf("-> Caso o problema persista:\n");
        printf("-> Troque 'ModoDeSalvamento' para '0' em 'opcoes.txt'\x1b[22;39m\n");
        return 0;
    }
    
    char arq_sub[strlen(arq_nome)+10];
    strcpy(arq_sub,arq_nome);
    arq_gerar(arq_sub,arq_nome,1);

    FILE *arquivo;
    arquivo=fopen(arq_nome,"a");
    if (arquivo) fclose(arquivo);
    else return 0;

    return 1;
}

int arq_gerarCopia(char arq_nome[], char arq_nomeCopia[]) {
// Função que copia arq_nome para o arq_nomeCopia, que é criado no modo write
// Debug: caso debug seja 1, printfs de aviso e visualização dos resultados serão mostrados

    int limite=300;
    char linha[limite+1];

    FILE *arquivo;
    FILE *arquivo2;
    arquivo=fopen(arq_nome,"r");
    arquivo2=fopen(arq_nomeCopia,"w");

    if (arquivo) {
        if (arquivo2) {

            while  (fgets(linha, limite, arquivo) ) fprintf(arquivo2,"%s",linha); 
            fclose(arquivo); 
            fclose(arquivo2); 

        } else return 0;

    } else return 0;

    return 1;
}

int arq_criarOpcoes () {
// Função para gerar o conteudo de opcoes.txt
    FILE *arq;
    arq=fopen("opcoes.txt","w");
    if (arq) {
        fprintf(arq,"--- Opções ---\n\n");
        fprintf(arq,"//Volume da música de fundo ( 70 [Padrão])\n");
        fprintf(arq,"VolumeFundo = 70\n\n");
        fprintf(arq,"//Volume dos efeitos sonoros ( 100 [Padrão])\n");
        fprintf(arq,"VolumeEfeito = 100\n\n");
        fprintf(arq,"//Com quanto dinheiro cada player começa? ( 1000 [Padrão])\n");
        fprintf(arq,"DinheiroInicial = 1000\n\n");
        fprintf(arq,"//Qual o valor mínimo da primeira aposta do jogo? ( 10 [Padrão])\n");
        fprintf(arq,"ApostaMinimaInicial = 10\n\n");
        fprintf(arq,"// Seleciona como será formatado o .txt que salva o histórico cada partida ( 1 = Data e Hora [Padrão] / 0 = partida.txt )\n");
        fprintf(arq,"ModoDeSalvamento = 1\n\n");

        fprintf(arq,"//Modo de debug ( 0 = Desativado [Padrão] / 1 = Simples / 2 = Facilita Testes)\n");
        fprintf(arq,"// Simples -> prinfs de avisos e monitoramento\n");
        fprintf(arq,"//Facilita Testes -> Simples + pula partes do jogo para facilitar os testes\n");
        fprintf(arq,"debug = 0\n\n");
        fprintf(arq,"//Número de Players do Modo Debug ( 6 = [Padrão])\n");
        fprintf(arq,"// Só é utilizado no modo debug 2\n");
        fprintf(arq,"NumeroDePlayersDebug = 6\n\n");
        
        fprintf(arq,"//Trilha Sonora Alternativa [Secreta] ( 0 = Desativado [Padrão] / 1 = Ativado)\n");
        fprintf(arq,"TrilhaAlternativa = 0\n");

        fprintf(arq,"\n\n\n\n\n\n//-->Esse código foi feito para rodar em sistemas Windows, mas tem compatibilidade quase completa para LINUX\n");
        
        fclose(arq);
        return 1;
    }
    else return 0;
}


int arq_lerOpcoes (int *variavel, char scan[], char formato[]){
// Função para obter valores para uma variável cujos valores estão dentro deu um opcoes.txt
// Parametros: end.de memória da variável cujo valor será obtido / string a ser comparada com a linha escaneada / formatação da string q a variável tá inserida
// EXEMPLO DE USO: arq_lerOpcoes(&modoJogo,"Modo_de_Jogo =","Modo de Jogo = %d");
    FILE *arq;
    char linha[100];
    arq=fopen("opcoes.txt","r");
    if (arq) {
        while((fgets(linha,100,arq) != NULL)) {
            if (str_iniciaCom(linha,scan)) {
                sscanf(linha,formato,variavel);
                break;
            }
        }
    } else {
        printf("Erro na abertura de arquivo opcoes.txt\n");
        return 0;
    }
    return 1;
}

int arq_verificarOpcoes () {
//Função que verifica se opcoes.txt já foi criado. Se sim, retorna 0, se não, retorna 1
    FILE *arq;
    arq=fopen("opcoes.txt","r");
    if (!arq) {

        printf(" - Gerando arquivos necessários - \n");
        if (arq_criarOpcoes()) {
            printf("Configurações padrão foram aplicadas\n");
            printf("\n Geração concluida\n");
            
            printf("\nAperte qualquer tecla para iniciar o programa\n");
        
            //Função de detectar se algo for apertado [Função não autoral]
            int input=-1;
            while (input == -1) input = getch();

            return 0;
        } else {
            printf("->Falha na geração de arquivo\n");
            printf("O programa ainda poderá ser rodado, mas nenhuma informação poderá ser salva em arquivo.\n\n");

            printf("Configurações padrão foram aplicadas\n");

            printf("\nAperte qualquer tecla para iniciar o programa\n");
            //Função de detectar se algo for apertado [Função não autoral]
            int input=-1;
            while (input == -1) input = getch();
        }
    }
    return 1;
}

#endif