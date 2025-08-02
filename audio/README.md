# audio.h — Mini-engine de áudio assíncrono

## Visão geral
`audio.h` reúne **miniaudio** (para decodificar/reproduzir WAV / MP3) e **async.h** (threads assíncronas) para que você controle sons em C com duas ou três chamadas.

> Carregar, dar play e seguir em frente, sem travar a _main thread_.

---

## Dependências

| Header            | Função no projeto |
|-------------------|-------------------|
| `async.h`         | Lança threads assíncronas  |
| `miniaudio.h`     | Backend de áudio single-file |

Basta manter ambos na pasta `dependencias/` (ou ajustar `#include`).

---

## API essencial (audio.h)

| Função                      | O que faz                                              |
| --------------------------- | ------------------------------------------------------ |
| `audio_init()`              | Inicializa engine global (chame **antes** de tudo).    |
| `audio_load(alias, file)`   | Carrega `.wav`, `.mp3`, etc., associado a `alias`.     |
| `audio_play(alias, loop)`   | Toca faixa; `loop=true` => reproduz para sempre.       |
| `audio_stop(alias)`         | Para imediatamente.                                    |
| `audio_set_volume(alias,v)` | Ajusta volume (0–100%).                                |
| `audio_fade_in(alias,duração(ms), vi,vf)`        | Fade assíncrono de volume usando thread assíncrona (vi = volume Inicial) (vf = volume final)|
| `audio_fade_out(...)`       | Idem, mas para saída.                                  |
| `audio_is_playing(alias)`   | Retorna `1` se estiver tocando.                        |
| `audio_shutdown()`          | Libera todos os recursos.                              |

### Sobre *threads assíncronas*

As funções de audio criam uma thread com `async_run()` e imediatamente a soltam com `async_detach()`. Ou seja, **dispare, "toca e vaza" e esqueça**, o programa não é pausado para executar tocar audios em loop, tocar um audio único, e nem aplicar um fade in ou fade out

---

## Conceito de **alias**

* **Pode ser qualquer string curta** que ajude a lembrar da faixa — “fundo”, “explosao1”, “tema_boss”…  
* **Precisa ser única**: cada áudio é identificado exclusivamente por seu alias (campo `Track.alias` na struct interna) :contentReference[oaicite:1]{index=1}.  
* Todas as funções (`audio_play`, `audio_stop`, etc.) procuram o alias em um laço simples se houver duplicatas, apenas a primeira será considerada.

---

## Exemplo rápido

O arquivo `exemploaudio.c` mostra o ciclo completo: inicializar, carregar, tocar, esperar e desligar.

```c
#include "audio.h"

int main(void) {
    audio_init();                                     // 1. liga engine

    audio_load("fundo", "assets/tema.mp3");           // 2. alias único
    audio_load("tiro",  "assets/pew.wav");

    audio_play("fundo", true);                        // 3. loop eterno
    audio_play("tiro",  false);                       // efeito pontual

    Sleep(5000);                                      // 4. curte o som
    audio_fade_out("fundo", 2000, 100, 0);            // fade-out 2 s

    audio_shutdown();                                 // 5. encerra
    return 0;
}
```
## Boas práticas

* Invoque **`audio_init()`** uma única vez no início e **`audio_shutdown()`** antes de sair.
* Para *resource packs* grandes, carregue tudo no início para evitar travamentos durante gameplay.
* Use alias curtos e únicos (máx. 31 chars).
* Lembre‑se de lidar com caminhos relativos/absolutos de áudio.

---