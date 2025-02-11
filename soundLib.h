#ifndef SOUNDLIB_H
#define SOUNDLIB_H

#include "myLib.h"

typedef struct
{
    unsigned char *data;
    int length;
    int frequency;
    bool isPlaying;
    bool shouldLoop;
    int duration;
} SOUND;

SOUND soundA;
SOUND soundB;
int vbCountA;
int vbCountB;

void setupSound();
void soundInterruptHandler();
void playSoundA(const unsigned char *sound, int length, int frequency, int shouldLoop);
void playSoundB(const unsigned char *sound, int length, int frequency, int shouldLoop);
void muteSound();
void unmuteSound();
void stopSound();

#define REG_SOUNDCNT_X *(volatile u16 *)0x04000084

// register definitions
#define REG_SOUNDCNT_L        *(u16*)0x04000080
#define REG_SOUNDCNT_H        *(volatile u16*)0x04000082

// flags
#define SND_ENABLED           (1<<7)
#define SND_OUTPUT_RATIO_25   0
#define SND_OUTPUT_RATIO_50   (1<<0)
#define SND_OUTPUT_RATIO_100  (1<<1)
#define DSA_OUTPUT_RATIO_50   (0<<2)
#define DSA_OUTPUT_RATIO_100  (1<<2)
#define DSA_OUTPUT_TO_RIGHT   (1<<8)
#define DSA_OUTPUT_TO_LEFT    (1<<9)
#define DSA_OUTPUT_TO_BOTH    (3<<8)
#define DSA_TIMER0            (0<<10)
#define DSA_TIMER1            (1<<10)
#define DSA_FIFO_RESET        (1<<11)
#define DSB_OUTPUT_RATIO_50   (0<<3)
#define DSB_OUTPUT_RATIO_100  (1<<3)
#define DSB_OUTPUT_TO_RIGHT   (1<<12)
#define DSB_OUTPUT_TO_LEFT    (1<<13)
#define DSB_OUTPUT_TO_BOTH    (3<<12)
#define DSB_TIMER0            (0<<14)
#define DSB_TIMER1            (1<<14)
#define DSB_FIFO_RESET        (1<<15)

// FIFO address defines
#define REG_FIFO_A          0x040000A0
#define REG_FIFO_B          0x040000A4

#endif
