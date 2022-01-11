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
