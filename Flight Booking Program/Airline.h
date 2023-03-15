#ifndef AIRLINE_H
#define AIRLINE_H
#include <string>
#include "Flight.h"
using namespace std;

class Airline{
    private: 
        string d_name;
        string d_boardingCity;
        string d_shortName;
      
    public: 
        Airline();
        Airline(string name, string boardingCity, string shortName);

        void setBoardingCity(string boardingCity);
        void setShortName(string shortName);
        void setName(string name);

        string getBoardingCity();
        string getShortName();
        string getName();

};

#endif 