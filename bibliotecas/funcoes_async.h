//Biblioteca Própria //
#ifndef FUNCOES_ASYNC_H
#define FUNCOES_ASYNC_H

void som_comecar_intro(void *infoVolumeMusica){
    int VolumeFundo = *((int*) infoVolumeMusica);
    audio_play("introsom",0);
    Sleep(3000);
    audio_fade_out("temainicial",2000,VolumeFundo,0);
    
    audio_play("selecaojogadores",1);
    audio_set_volume("selecaojogadores",0);
    audio_fade_in("selecaojogadores",2000,0,VolumeFundo);
}

void som_comecar_musicadejogo_1(void *infoVolumeMusica){
    int VolumeFundo = *((int*) infoVolumeMusica);

    audio_stop("temainicial");
    audio_stop("introsom");
    audio_fade_out("selecaojogadores",2000,VolumeFundo,0);
    audio_fade_in("musicadejogo1pt1",2000,0,VolumeFundo);
    Sleep(2000);
    audio_stop("selecaojogadores");
    Sleep(12200);
    audio_play("musicadejogo1pt2",1);
    audio_stop("musicadejogo1pt1");
}

void som_comecar_musicadejogo_2(void *infoVolumeMusica){
    int VolumeFundo = *((int*) infoVolumeMusica);

    audio_fade_out("musicadejogo1pt2",2000,VolumeFundo,0);
    audio_play("musicadejogo2",1);
    audio_set_volume("musicadejogo2",0);
    audio_fade_in("musicadejogo2",2000,0,VolumeFundo);
    Sleep(2000);
    audio_stop("musicadejogo1pt2");
}

void som_comecar_musicadejogo_3(void *infoVolumeMusica){
    int VolumeFundo = *((int*) infoVolumeMusica);

    audio_fade_out("musicadejogo2",2000,VolumeFundo,0);
    audio_fade_in("musicadejogo3pt1",2000,0,VolumeFundo);
    Sleep(2000);
    audio_stop("musicadejogo2");
    Sleep(8155);
    audio_play("musicadejogo3pt2",1);
    audio_stop("musicadejogo3pt1");
}

void som_comecar_musicadejogo_4(void *opcoes){
    int VolumeFundo = ((opc*) opcoes)->VolumeFundo;
    int *Ploop = &(((opc*)opcoes)->loopMusica);
    *Ploop=1;

    audio_fade_out("musicadejogo3pt2",2000,VolumeFundo,0);
    audio_fade_in("musicafinalpt1",2000,0,VolumeFundo);
    audio_set_volume("musicafinalpt2",VolumeFundo);
    
    while(1) {
        if (!audio_is_playing("musicafinalpt1")) {
            if (!*Ploop) break;
            else audio_play("musicafinalpt1",0);
        }
    }
    audio_play("musicafinalpt2",1);
}

#endif