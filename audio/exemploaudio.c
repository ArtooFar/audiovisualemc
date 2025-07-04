#include "audio.h"

int main(void)
{
    // Inicializa o engine global da audio.h
    audio_init();

    // Carrega as faixas – alias é como vamos referenciar depois
    audio_load("wow","pastaexemplo\\wow.mp3"); //carrega wow.mp3, sob o alias wow
    audio_load("swoosh","pastaexemplo\\swoosh.wav"); //carrega swoosh.wav sob o alias swoosh
    
    // OBS: o alias pode ser qualquer coisa, só precisa ser único para cada som

    // Inicia a reprodução
    audio_play("wow",  true); // Loop = True 
    audio_play("swoosh", false); //Loop = False

    // Aplica fade in no audio "wow", o efeito demora 4000ms (4s)
    // e vai do volume 0 até 100
    audio_fade_in("wow",4000,0,100);

    // Pausa o programa para o audio poder ser ouvido (ele roda num processo separado da main)
    Sleep(10000);

    // Encerra a engine de audio
    audio_shutdown();
    return 0;
}