#include <iostream>

#include "EnvironmentalCondition.h"
using std::cout;
using std::endl;

int main()
{
  EnvironmentalCondition ec = EnvironmentalCondition(EnvironmentalCondition::SUNNY,
      EnvironmentalCondition::HIGH, 34.0, EnvironmentalCondition::MEDIUM);

  cout << "Precipitation: " << ec.getPrecipitation() << endl;
  cout << "Temperature: " << ec.getTemperature() << endl;
  ec.setTemperature(33.0);
  cout << "Temperature: " << ec.getTemperature() << endl;

  cout << "isItHot: " << ec.isItHot() << endl;
  cout << "isItRainy: " << ec.isItRainy() << endl;
  cout << "isItStormy: " << ec.isItStormy() << endl;

  return 0;
}
