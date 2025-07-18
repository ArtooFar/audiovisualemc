
/* ansi_sprite.h  —  single‑header version
 *
 * Minimal ANSI terminal sprite‑sheet renderer using 24‑bit colour.
 * Depends only on stb_image (already included below).
 *
 * Usage (in **one** .c file *before* including):
 *     #define ANSI_SPRITE_IMPLEMENTATION
 *     #include "ansi_sprite.h"
 *
 * In every other file:
 *     #include "ansi_sprite.h"
 *
 * SPDX‑License‑Identifier: MIT‑0 (public domain dedication)
 */
#define ANSI_SPRITE_IMPLEMENTATION
#ifndef ANSI_SPRITE_H
#define ANSI_SPRITE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SpriteSheet SpriteSheet;

/* Load sprite sheet laid out horizontally.
   frame_w/frame_h: sprite size in pixels (e.g., 15×15).
   Returns NULL on failure. */
SpriteSheet *sprite_sheet_load(const char *filename,
                               int frame_w,
                               int frame_h);

/* Free resources allocated by sprite_sheet_load(). */
void sprite_sheet_free(SpriteSheet *sheet);

/* Draw a single frame on the terminal.
   bg_rgb  : string "R;G;B" (e.g., "0;0;0").
   offset_x: 0‑based column where sprite left edge starts.
   offset_y: 0‑based row    where sprite top edge starts. */
void sprite_draw_frame(const SpriteSheet *sheet,
                       int frame_idx,
                       const char *bg_rgb,
                       int offset_x,
                       int offset_y);

/* Animate the whole sheet.
   iterations <= 0 → loop forever.
   delay_us  : micro‑seconds between frames. */
void sprite_animate(const SpriteSheet *sheet,
                    int iterations,
                    int delay_us,
                    const char *bg_rgb,
                    int offset_x,
                    int offset_y);

#ifdef __cplusplus
}
#endif

/* -------------------------------------------------------------------- */


#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)        /* ---------- Windows ---------- */
  #include <windows.h>
  /* usleep wrapper – aceita microssegundos  */
  static inline void usleep(__int64 usec) { Sleep((DWORD)(usec / 1000)); }
#else                                         /* ---------- POSIX ------------ */
  #include <unistd.h>
#endif


#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#define STBI_ONLY_JPEG
/*  STB image library – https://github.com/nothings/stb
    Tiny public‑domain image loader (PNG/JPG).             */
#include "stb_image.h"

struct SpriteSheet {
    int frame_w, frame_h;
    int frames;
    int img_w, img_h;
    unsigned char *pixels; /* RGBA */
};

SpriteSheet *sprite_sheet_load(const char *filename,
                               int frame_w,
                               int frame_h){
    int w,h,n;
    unsigned char *data = stbi_load(filename, &w,&h,&n, 4);
    if(!data){
        fprintf(stderr, "stb_image: failed to load %s\n", filename);
        return NULL;
    }
    if(w % frame_w != 0 || h != frame_h){
        fprintf(stderr, "Sprite sheet dimensions not multiple of frame size.\n");
        stbi_image_free(data);
        return NULL;
    }
    SpriteSheet *s = (SpriteSheet*)calloc(1,sizeof(SpriteSheet));
    if(!s){ stbi_image_free(data); return NULL; }
    s->frame_w = frame_w; s->frame_h = frame_h;
    s->img_w = w;        s->img_h = h;
    s->frames = w / frame_w;
    s->pixels = data;
    return s;
}

void sprite_sheet_free(SpriteSheet *s){
    if(!s) return;
    stbi_image_free(s->pixels);
    free(s);
}

void sprite_draw_frame(const SpriteSheet *s,
                       int idx,
                       const char *bg_rgb,
                       int off_x,
                       int off_y){
    if(!s || idx<0 || idx>=s->frames) return;
    int fw=s->frame_w, fh=s->frame_h;
    int start_x = idx*fw;
    const unsigned char *px = s->pixels;
    for(int y=0;y<fh;++y){
        printf("\033[%d;%dH", off_y+y+1, off_x+1); /* move cursor */
        for(int x=0;x<fw;++x){
            int img_x = start_x + x;
            size_t pos = (size_t)(img_x + s->img_w*y)*4;
            unsigned char r=px[pos], g=px[pos+1], b=px[pos+2], a=px[pos+3];
            if(a<128){
                printf("\033[48;2;%sm  ", bg_rgb); /* two spaces w/ background */
            }else{
                printf("\033[38;2;%d;%d;%dm██", r,g,b);
            }
        }
        printf("\033[0m"); /* reset row */
    }
    fflush(stdout);
}

void sprite_animate(const SpriteSheet *s,
                    int iterations,
                    int delay_us,
                    const char *bg_rgb,
                    int off_x,
                    int off_y){
    if(!s) return;
    if(delay_us<0) delay_us=0;
    int loop=0;
    while(iterations<=0 || loop<iterations){
        for(int i=0;i<s->frames;++i){
            sprite_draw_frame(s,i,bg_rgb,off_x,off_y);
            usleep(delay_us);
        }
        ++loop;
    }

    sprite_draw_frame(s, 0, bg_rgb, off_x, off_y);

    printf("\033[0m\e[H");
}

#endif /* ANSI_SPRITE_H */
