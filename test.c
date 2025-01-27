#include <stdio.h>
#include "uprintf.h"

void put_char(char c)
{
    fputc(c, stdout);
}

int main(void)
{
    p("Hello %s!\n", "ALL");
    p("1: |%4i:%4i:%4i|\n", 1, -2, 3);
    p("2: |%-4i:%-4i:%-4i|\n", 1, -2, 3);
    p("3: |%' 4i:%'.4i:%''4i|\n", 1, -2, 3);
    p("4: |%' -4i:%'.-4i:%''-4i|\n", 1, -2, 3);

    p("5: |%4s:%4s:%4s|\n", "a", "b", "c");
    p("6: |%-4s:%-4s:%-4s|\n", "a", "b", "c");

    p("7: |%*s|\n", 5, "s");
    p("8: |%'-*s|\n", -5, "s");

    p("9: |%016ulx|\n", 0x55555555AAAAAAAAll);

    /* TODO more tests */

    return 0;
}
