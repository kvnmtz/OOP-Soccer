#pragma once

#include <ctime>

/*-----------------------------------------------------------------------------
    Utility-Namespace f�r Zufallszahlen
-----------------------------------------------------------------------------*/

namespace Random
{
    /**
     * \brief Seedet den RNG
     */
    inline void Initialize()
    {
        srand(time(nullptr));
    }

    /**
     * \param min Untere Grenze des Ergebnisses
     * \param max Obere Grenze des Ergebnisses
     * \return Eine zuf�llige Zahl die in den angegebenen Grenzen liegt (inklusive)
     */
    inline int GetRandomNumber(const int min, const int max)
    {
        return rand() % (max + 1) + min;
    }

    /**
     * \param probability Die Wahrscheinlichkeit daf�r, dass der zur�ckgegebene Wert true ist
     * \return True, wenn ein zuf�llig generierter Wert (1 - 100) kleiner oder gleich der angegebenen Wahrscheinlichkeit ist, sonst false
     */
    inline bool Success(const int probability)
    {
        return GetRandomNumber(1, 100) <= probability;
    }
}