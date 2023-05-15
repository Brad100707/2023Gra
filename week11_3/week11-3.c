#include <windows.h>

///要先到 setting-compiler 到linker setting加上winmm

int main()
{
    PlaySoundA("do_re_mi\\do,wav", NULL, SND_SYNC);
    PlaySoundA("do_re_mi\\do,wav", NULL, SND_SYNC);
    PlaySoundA("do_re_mi\\do,wav", NULL, SND_SYNC);
    PlaySoundA("do_re_mi\\re,wav", NULL, SND_SYNC);
}
