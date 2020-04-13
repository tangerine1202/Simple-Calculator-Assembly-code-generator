#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "lexer_parser.h"
#include "code_gen.h"
#include "helpful.h"

int DEBUG_MODE = 0;

int main(void)
{
    if (!DEBUG_MODE)
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    while (1)
    {
        // init XYZ
        for (int i = 0; i < 3; i++)
        {
            char c[2];
            c[0] = 'x' + i;
            c[1] = '\0';
            strcpy(sbtable[sbcount].name, c);
            sbtable[sbcount].val = 0;
            sbcount++;
        }

        statement();
    }
    return 0;
}
