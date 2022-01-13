#pragma once
#include <random>

template<class T>
std::uniform_real_distribution<T> get_random_real_number_generator(T min, T max);

float get_random_float_from_0_1();
int get_random_int(const int& min, const int& max);