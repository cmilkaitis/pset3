// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numer = fraction[0] - '0';
    int denom = fraction[2] - '0';

    // TODO
    if (strlen(fraction) > 1)
    {
        if (fraction[2] == 8)
        {
            return numer;
        }
        if (fraction[2] == 4)
        {
            return 2;
        }
        if (fraction[2] == 2)
        {
            return 4;
        }
    }
    return 8;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char n = note[0];
    //int o = atoi(note[1]);
    printf("%c", n);

   /* if (strlen(note) == 3)
    {
        char a = note[1];
        o = atoi(note[2]);

        if (n == 'A')
        {

        }
    }

    if (n == 'A')
    {
        int diff = o - 4;

        if (diff != 0)
        {
            if (diff >= 1)
            {
                return 440 * (diff * 2);
            }

            return 440 / (abs(diff) * 2);
        }
        return 440;
    }*/
    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return s == NULL;
}


/*

A4 is 440

For every semitone UP we move, we MULTIPLY the freq by 2 ^ 1/12

For every semitone DOWN we move, we DIVIDE the freq by 2 ^ 1/12

A  B  C  D  E  F  G
65 66 67 68 69 70 71

*/
