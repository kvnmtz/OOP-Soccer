#pragma once
#include <cstdlib>
#include <ctime>

namespace Random
{
	/**
	 * \brief Seeded den RNG
	 */
	inline void Initialize()
	{
		srand(time(nullptr));
	}

	inline int GetRandomNumber(const int min, const int max)
	{
		return rand() % max + min;
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
