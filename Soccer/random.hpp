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
	 * \param probability Die Wahrscheinlichkeit dafür, dass der zurückgegebene Wert true ist
	 * \return True, wenn ein zufällig generierter Wert (1 - 100) kleiner oder gleich der angegebenen Wahrscheinlichkeit ist, sonst false
	 */
	inline bool Success(const int probability)
	{
		return GetRandomNumber(1, 100) <= probability;
	}

}
