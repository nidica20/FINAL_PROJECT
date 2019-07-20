#ifndef RANDOMGENERATOR_H_
#define RANDOMGENERATOR_H_
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

struct Random {
    Random() {
        srand((unsigned int)std::time(0));
        //No arg constructor
    }

    //returns a double value at random for nextInt function to use
    double nextDouble()
    {
        return double( rand() ) / RAND_MAX;
    }

    //return random integer for probability of patient walking in
    int next_int(int n)
    {
        return int(nextDouble() * n);
    }
    
    int Random_Illness_Level() {
        int level = rand() % 10 + 1;
        int priority = 0;

        //Illnesses with priority 16 to 20 occur approximately 10% of the time with equal probability.
        if (level > 9)
        {
            priority = rand() % 5 + 16;
            return priority;
        }
        //Illnesses with priority 11 to 15 occur approximately 20% of the time with equal probability.
        else if (level > 7)
        {
            priority = rand() % 5 + 11;
            return priority;
        }

        else //Illnesses with priority 1 to 10 occur approximately 70% of the time with equal probability.
        {
            priority = rand() % 10 + 1;
            return priority;
        }
    }
}; 

#endif