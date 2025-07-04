//Defines
#define PRE_ROUND 0
#define PRIMEIRO_ROUND 1
#define SEGUNDO_ROUND 2
#define TERCEIRO_ROUND 3
#define MOSTRAR_CARTAS 4

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include <windows.h>
#include "bibliotecas/async.h"
#include "bibliotecas/audio.h"
#include "bibliotecas/miscelanea.h"
#include "bibliotecas/elementosvisuais.h"
#include "bibliotecas/arquivo.h"
#include "bibliotecas/cartasejogador.h"
#include "bibliotecas/configs.h"
#include "bibliotecas/extradebug.h"
#include "bibliotecas/combinacoes.h"
#include "bibliotecas/funcoes_async.h"
#include "bibliotecas/arvore.h"
#include "bibliotecas/saves.h"
#include "bibliotecas/historico.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main_filho()
{
    //////////////////////////// INICIALIZAÇÃO - ARQUIVOS - CONFIGURAÇÕES ////////////////////////////////
    
	//Variáveis das configurações -> opcoes.txt
    opc opcoes;
    //Verifica se o opcoes.txt já foi criado, se não foi, tenta criá-lo
    arq_verificarOpcoes();
    limparTela();
    
    //Obter variáveis guardadas em opcoes.txt e inicializa srand
    config_inicializacao(&opcoes);
    console_cursor_invisivel(); //deixa cursor invisível

    //Audio
    audio_setar_audios(opcoes.trilhaAlternativa);
    audio_setar_volume_efeito(opcoes.VolumeEfeito);
    audio_setar_volume_fundo(opcoes.VolumeFundo);
    
    //////////////////////////// ------- DECLARAÇÃO DE VARIÁVEIS ------- ////////////////////////////////

    int iniciarJogo,fechar=0,continuarUltimo=-1,iniciarConfig,etapa=PRE_ROUND, poker_vencedor=-1,loopMusicaFinal=1,continua=1;
    tp_jogador jogador[6];

    ArvoreComb arvore = arv_comb_inicializar();
    EstatisticasComb estat;
    iniciar_estatisticas(&estat);

    tp_pilhaSEcarta *baralhoJogo;       //BARALHO PARA OS JOGADORES
	tp_carta baralhoReferencia[52];
    tp_listasecarta *mao_mesa;
    tp_cursor cursor;

    tp_pote pote;
    pote.pote=0;
    pote.maiorApostaJogadorID=-1;
    pote.quantidadeJogadores=0;

    tp_combinacaoMaior aux_ID_maior_combinacao;
    aux_ID_maior_combinacao.ID=-1;
    aux_ID_maior_combinacao.valorMaisAlto=-1;
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    //Inicializa os baralhos
	baralhoReferencia_inicializar(baralhoReferencia);
    baralhoJogo=pilhaSEcarta_inicializar();
    baralho_embaralhar(baralhoReferencia,baralhoJogo);
    mao_mesa=listaSEcarta_inicializar();

    //Menu inicial e configurações

    do {
        programa_iniciar();
        if (!audio_is_playing("temainicial")) audio_play("temainicial",1);
        
        limparTela();

        cursor_zerarCursor(&cursor);
        desenhar_fundoinicial();
        desenhar_fichainicial();

        audio_setar_volume_efeito(opcoes.VolumeEfeito);
        audio_setar_volume_fundo(opcoes.VolumeFundo);

        while(1) {
            fechar = menuinicial_navegar(&cursor);
            if (fechar > 0) {
                if (fechar==3) return 2;
                break;
            }
        }

        audio_play("botao",0);
        
        if (cursor.navegador==1){
            audio_setar_volume_efeito(opcoes.VolumeEfeito);
            audio_setar_volume_fundo(opcoes.VolumeFundo);
            async_thread_t comecarintro = async_run(som_comecar_intro,&opcoes.VolumeFundo);
            if (opcoes.debug!=2) Sleep(1000);
            if (opcoes.debug!=2) desenhar_fundo_espiral_com_cor("0;0;0");
        }

        if(cursor.navegador==2) {
            limparTela();
            cursor_zerarCursor(&cursor);
            while(1) if (config_navegar(&cursor,&opcoes,baralhoReferencia)) break;
            limparTela();
    
        } 

    } while (cursor.navegador!=1);

    //Mostrar baralhos se debug for 1
    if (opcoes.debug == 1) debug_mostrarBaralhos(baralhoReferencia, opcoes, baralhoJogo);
    
    desenhar_fundotipojogo();
    desenhar_tutorial("43;43;43");
    cursor_setarCursor(&cursor,-1);

    while (continuarUltimo == -1) continuarUltimo = menuinicial_tipoJogo_navegar(&cursor);

    if (continuarUltimo==0) {
        //Se debug estiver desligado, escolhe quantidade de players
        if (opcoes.debug>1) pote.quantidadeJogadores=opcoes.nplayersdebug;
        else pote.quantidadeJogadores=jogador_escolherQuantidade(&cursor);

        jogadores_setar_dinheiroInicial(jogador,pote.quantidadeJogadores,opcoes.dinheiroInicial);

        //Se debug for diferente de 2, escolhe os nomes dos players
        if (opcoes.debug==2) debug_jogador_escolherNomes(jogador, pote.quantidadeJogadores);
        else {
            desenhar_fundopreto();
            jogador_escolherNomes(jogador, pote.quantidadeJogadores);
        }

        programa_pausar();
    }
    else {
        if (!saves_carregar_partida(jogador,&pote)) return 10;
        saves_imprimir(jogador,&pote);
        programa_pausar();
    }

    pote.maiorAposta=opcoes.apostaMinimaInicial;

    jogador_inicializar_mao(jogador, pote.quantidadeJogadores);

    async_thread_t musicadejogo1 = async_run(som_comecar_musicadejogo_1,&opcoes.VolumeFundo);
    
    limparTela();

    //Distribuição de cartas para os jogadores
    if(!baralho_distribuirCartas_jogadores(baralhoJogo, jogador, pote.quantidadeJogadores)) {
        printf("Erro na distribuição de cartas.\n");
        printf("O programa será encerrado.\n");

        programa_finalizar();
        return 22;
    }

    if (opcoes.debug==1) debug_mostrarMaos (baralhoJogo, jogador, pote.quantidadeJogadores);

    while(continua) {
        switch(etapa){
            case PRE_ROUND:
                historico_iniciar();
                animacao_animar_round1();
                desenhar_fundo();
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                desenhar_mesaapoiodamesa();

                jogo_rodada_round_completo (jogador,&pote,&mao_mesa,&cursor);

                etapa = PRIMEIRO_ROUND;

            break;

            case PRIMEIRO_ROUND:
                animacao_animar_round2();

                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);

                if(condicao_rodada(jogador,&mao_mesa,pote.quantidadeJogadores)) {
                    desenhar_fundo();
                    
                    desenhar_mesaapoiodamesa();
                }
                
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                
                jogo_zerar_apostas(jogador, &pote, pote.quantidadeJogadores);
                
                jogo_rodada_round_completo (jogador,&pote,&mao_mesa,&cursor);
            
                etapa = SEGUNDO_ROUND;
            
            break;

            case SEGUNDO_ROUND:
                async_thread_t musicadejogo2 = async_run(som_comecar_musicadejogo_2,&opcoes.VolumeFundo);
                animacao_animar_round3();
                
                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);

                if(condicao_rodada(jogador,&mao_mesa,pote.quantidadeJogadores)) {
                    desenhar_fundo();
                    
                    desenhar_mesaapoiodamesa();
                }

                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                
                jogo_zerar_apostas(jogador, &pote, pote.quantidadeJogadores);
                
                jogo_rodada_round_completo (jogador,&pote,&mao_mesa,&cursor);

                etapa = TERCEIRO_ROUND;

            break;

            case TERCEIRO_ROUND:
                async_thread_t musicadejogo3 = async_run(som_comecar_musicadejogo_3,&opcoes.VolumeFundo);
                animacao_animar_round4();

                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                if(condicao_rodada(jogador,&mao_mesa,pote.quantidadeJogadores)) {
                    desenhar_fundo();
                    
                    desenhar_mesaapoiodamesa();
                }
                
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                
                jogo_zerar_apostas(jogador, &pote, pote.quantidadeJogadores);

                jogo_rodada_round_desistencia (jogador,&pote,&mao_mesa,&cursor);

                etapa = MOSTRAR_CARTAS;
                continue;
            
            break;

            case MOSTRAR_CARTAS:
                async_thread_t musicadejogo4 = async_run(som_comecar_musicadejogo_4,&opcoes);
                combinacoes_verificar_jogadores(jogador,mao_mesa,&pote);
                
                combinacao_valor_mais_alto(jogador,pote.quantidadeJogadores);
                jogador_encontrar_maior_combinacao(jogador, &aux_ID_maior_combinacao, pote.quantidadeJogadores);
                poker_vencedor = jogador_vencedor(jogador, pote.quantidadeJogadores, aux_ID_maior_combinacao);
                int total = 0;

                for (int i = 0; i < pote.quantidadeJogadores; i++) {
                    if (jogador[i].desistir) continue; // Ignora quem desistiu

                    atualizar_estatisticas(&estat, &jogador[i].combinacoes);

                    if (jogador[i].combinacoes.par.quant > 0) total++;
                    if (jogador[i].combinacoes.trinca.quant > 0) total++;
                    if (jogador[i].combinacoes.straight.quant > 0) total++;
                    if (jogador[i].combinacoes.flush.quant > 0) total++;
                    if (jogador[i].combinacoes.fullHouse.quant > 0) total++;
                    if (jogador[i].combinacoes.quadra.quant > 0) total++;
                    if (jogador[i].combinacoes.straightFlush.quant > 0) total++;
                    if (jogador[i].combinacoes.royalFlush.quant > 0) total++;
                }

                arvore = arv_comb_inserir(arvore, etapa, total);

                jogador[poker_vencedor].dinheiro += pote.pote;
                jogo_telaFinal_misterio();
                opcoes.loopMusica=0;
                audio_play("finalselect",0);
                while(audio_is_playing("musicafinalpt1"));
                jogo_telaFinal_principal(jogador,&pote,mao_mesa,&cursor,poker_vencedor,opcoes.debug);

                salvar_estatisticas(&estat, "saves/ultimaPartida_estatisticas.txt");
            
                audio_stop_total();

                continua=0;

            break;

            default:
            break;
        }
    }
    arv_comb_salvar_em_arquivo(arvore, "saves/ultimaPartida_combinacoes.txt");
    arv_comb_destruir(arvore);

    char arqnome[100];

    if (opcoes.modoDeSalvamento==1) arq_gerarcData(arqnome);
    else arq_gerar("partida",arqnome,2);

    saves_salvar_partida(jogador,&pote,arqnome,poker_vencedor);

    saves_salvar_partida(jogador,&pote,"saves/ultimaPartida_save.txt",poker_vencedor);
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    //Configura o console para windows (liga cores e outros caracteres)
	windowsconfig();

    //Configuração de audio

    int info=-1;
    int conti=1;
    while (conti){
        audio_init();
        info = main_filho();
        audio_shutdown();
        limparTela();
        switch (info){
            case 2:
                printf("Obrigado por jogar!\n- Filhos do Limoeiro\e[H");
                programa_finalizar();
                return 1;
            break;

            case 10:
            printf("Erro no carregamento de save\n->Save Corrompido");
            break;

        }
        programa_pausar();
    }
}