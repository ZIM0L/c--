#include <cstdlib>
#include <iostream>
using namespace std;


class RideReport
{
public:
  RideReport(const char *fileName);
  ~RideReport();
  bool readData();
  bool processData();
  int getSpeedUpCount();
  int getSlowDownCount();
  int getLeftTurnCount();
  int getRightTurnCount();
  bool saveCleanedData(const char *fileName);
  bool saveAsText(const char *fileName);
  bool saveAsXML(const char *fileName);
private:
  const char *fileName;
};



int main()
{
  RideReport report("dane.txt");
  if(report.readData())
  {
    if(report.processData())
    {
      cout << "\nPrzyspieszenia: " << report.getSpeedUpCount();
      cout << "\nHamowania: " << report.getSlowDownCount();
      cout << "\nW lewo: " << report.getLeftTurnCount();
      cout << "\nW prawo: " << report.getRightTurnCount();
      if(report.saveCleanedData("dane_czyste.txt"))
        cout << "\nOczyszczone dane zapisane";
      if(report.saveAsText("raport.txt"))
        cout << "\nRaport tekstowy zapisany";
      if(report.saveAsXML("raport.xml"))
        cout << "\nPlik XML zapisany";
     }
  }
  return EXIT_SUCCESS;
}
