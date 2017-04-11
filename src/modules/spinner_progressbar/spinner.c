#include <stdio.h>
#include <unistd.h>
#include "spinner_progressbar.h"

int sample_spinner(unsigned int wait_sec)
{
    static const int spinner_c[] = {'/', '-', '\\', '|'};
    static const int spinner_len = sizeof(spinner_c) / sizeof(spinner_c[0]);
    unsigned int i;

    for (i = 0; i < wait_sec; i++) {
        (void) sleep(1);
        printf("\rwating %d sec... %c", wait_sec, spinner_c[i % spinner_len]);
        fflush(stdout); // �o�b�t�@�������I�ɏo��.
    }

    puts(""); // ���s�\��.
    return 0;
}
