#include <iostream>

#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"
#include "HTMLWriter.h"
#include "HTMLWriterBalance.h"
#include "HTMLWriterEnvironment.h"

using std::cout;
using std::endl;

int main2()
{
  //EnvironmentalCondition *ec = new EnvironmentalCondition(EnvironmentalCondition::SUNNY,
  //    EnvironmentalCondition::HIGH, 34.0, EnvironmentalCondition::MEDIUM);

  EnvironmentalEngine ee = EnvironmentalEngine();
  EnvironmentalCondition *ec = ee.createCondition();

  cout << "Precipitation: " << ec->getPrecipitation() << endl;
  cout << "Temperature: " << ec->getTemperature() << endl;

  //ec.setTemperature(33.0);
  //cout << "Temperature: " << ec.getTemperature() << endl;

  cout << "isItHot: " << ec->isItHot() << endl;
  cout << "isItRainy: " << ec->isItRainy() << endl;
  cout << "isItStormy: " << ec->isItStormy() << endl;

  HTMLWriter writer = HTMLWriter("test.html");
  writer.writeFile("asdf");
  HTMLWriterBalance writer2 = HTMLWriterBalance("balance.html");
  writer2.writeFile(1,2,3,-5);
  HTMLWriterEnvironment writer3 = HTMLWriterEnvironment("environment.html");
  writer3.writeFile(*ec);

  delete ec;

  return 0;
}
