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

    if (denom == 4)
    {
        return 2;
    }
    if (denom == 2)
    {
        return 4;
    }

    return numer;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char n = note[0];
    char acc = '\0';
    int octive = note[1] - '0';
    double distance = 0.0, octHertz = 0.0;

// Determine the distance between notes from A and account for sharp or flat if strlen is 3

    if (strlen(note) == 3)
    {
        octive = note[2] - '0';
        acc = note[1];

        if (acc == '#')
        {
            distance += 1.0;
        }
        else if (acc == 'b')
        {
            distance -= 1.0;
        }
    }

    if (n == 'C')
    {
        distance -= 9.0;
    }
    else if (n == 'D')
    {
        distance -= 7.0;
    }
    else if (n == 'E')
    {
        distance -= 5.0;
    }
    else if (n == 'F')
    {
        distance -= 4.0;
    }
    else if (n == 'G')
    {
        distance -= 2.0;
    }
    else if (n == 'B')
    {
        distance += 2.0;
    }

// Determine octive hertz

    if (octive > 4)
    {
        octHertz = ((octive - 4.0) * 2.0) * 440.0;
    }
    else if (octive < 4)
    {
        octHertz = 440.0 / ((4.0 - octive) * 2.0);
    }
    else
    {
        octHertz = 440.0;
    }

// Return the final hertz

    return round(pow(2, distance / 12) * octHertz);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }

    return false;
}

