#pragma once
#include <random>

template<class T>
std::uniform_real_distribution<T> get_random_real_number_generator(T min, T max);

std::uniform_real_distribution<float> get_random_0_1_float = get_random_real_number_generator<float>(0,1);