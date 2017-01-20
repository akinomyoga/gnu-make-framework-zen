#include <stdio.h>
#include <unistd.h>
#include "sample_spinner_progressbar.h"

int sample_progressbar(unsigned int wait_sec)
{
    unsigned int i, j;

    for (i = 1; i <= wait_sec; i++) {
        (void) sleep(1);

        printf("\033[2K");
        putchar('[');
        for (j = 0; j < i; j++)
            putchar('#');
        for (; j < wait_sec; j++)
            putchar(' ');
        putchar(']');
        puts("");

        printf("\033[2K\033[G %d sec\n", i);
        printf("\033[2F");
        fflush(stdout); // �o�b�t�@�������I�ɏo��.
    }

    puts(""); // ���s�\��.
    return 0;
}
