#include "random.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

template<class T>
std::uniform_real_distribution<T> get_random_real_number_generator(T min, T max)
{
    const std::uniform_real_distribution<T> distr(min,max);
    return distr;
}


/**
 * \brief 
 * \param min min number inclusive
 * \param max max number inclusive
 * \return a random int between min and max
 */
int get_random_int(const int& min, const int& max)
{
    return static_cast<int>((max - min + 1) * get_random_float_from_0_to_1(gen) + min);
}
