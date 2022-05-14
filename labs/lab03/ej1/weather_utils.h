#ifndef _WEATHER_UTILS
#define _WEATHER_UTILS
#include "array_helpers.h"

/**
 * @brief yo no tuve docu, vos tampoco
 * @param a array
 */
int minTempHistory(WeatherTable a);

/**
 * @brief yo no tuve docu, vos tampoco
 * @param a array
 * @param output array
 */
void maxTempPerYear(WeatherTable a, int output[YEARS]);

/**
 * @brief yo no tuve docu, vos tampoco
 * @param a array
 * @param output array
 */
void monthOfMaxPrecPerYear(WeatherTable a, char *output[YEARS]);

#endif