#include "weather_utils.h"

//  Estaba aburrido y técnicamente no está mal xd
char *MONTH_NAME[MONTHS] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

int minTempHistory(WeatherTable a) {
  int minTemp;
  int _minTemp;
  
  for (unsigned int year = 0; year < YEARS; year++) {
    // Al empezar un año la temperatura mínima es la del 1er día
    minTemp = a[year][0][0]._min_temp;

    for (unsigned int month = 1; month < MONTHS; month++) {
      for (unsigned int day = 0; day < DAYS; day++) {
        _minTemp = a[year][month][day]._min_temp;
        
        // Si la mínima diaria es mayor a la histórica, actualizamos
        if (_minTemp < minTemp) minTemp = _minTemp;
      }
    }
  }

  return minTemp;
}

void maxTempPerYear(WeatherTable a, int output[YEARS]) {
  int _maxTemp;

  for (unsigned int year = 0; year < YEARS; year++) {
    // Al empezar un año la temperatura máxima es la del 1er día
    output[year] = a[year][0][0]._max_temp;

    for (unsigned int month = 0; month < MONTHS; month++) {
      for (unsigned int day = 0; day < DAYS; day++) {
        _maxTemp = a[year][month][day]._max_temp;
        
        // Si la máxima diaria es mayor a la histórica, actualizamos
        if (_maxTemp > output[year]) output[year] = _maxTemp;
      }
    }
  }
}

void monthOfMaxPrecPerYear(WeatherTable a, char *output[YEARS]) {
  unsigned int _qPrec;
  unsigned int _qPrecMax;

  for (unsigned int year = 0; year < YEARS; year++) {
    // Al empezar un año el máximo de precipitaciones mensuales es 0
    _qPrecMax = 0u;

    for (unsigned int month = 0; month < MONTHS; month++) {
      // Al empezar un mes las precipitaciones están en 0
      _qPrec = 0u;

      // Conteo de precipitaciones
      for (unsigned int day = 0; day < DAYS; day++) {
        _qPrec = _qPrec + a[year][month][day]._rainfall;
      }

      // Si las precipitaciones de este mes son mayores a la del máximo
      // registrado, actualizamos el mes guardado al actual.
      if (_qPrec > _qPrecMax) {
        output[year] = MONTH_NAME[month];
        _qPrecMax = _qPrec;
      }
    }
  }
}