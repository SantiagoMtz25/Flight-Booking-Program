#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
#include "Passenger.h"
#include <cstdio>
using namespace std;

const int MAX_ASIENTOS = 80;

class Flight{
    private: 
        int d_id;
        string d_date; 
        string d_hour; 
        float d_price; 
        string d_airplaneModel;
        string d_fromTo; 
        float d_distance; 
        string d_crew; //clave de la tripulacion 
        float d_fuel; 
        bool arrDispAsientos[MAX_ASIENTOS];
        Passenger arrPasajeros[MAX_ASIENTOS];

    public: 
        Flight();
        Flight(int id, string date, string hour, float price, string airplaneModel, string formTo, float distance, string crew, float fuel);

        void setId(int id);
        void setDate(string date);
        void setHour(string hour);
        void setPrice(float price);
        void setAirplaneModel(string);
        void setFromTo(string fromTo);
        void setDistance(float distance);
        void setCrew(string crew);
        void setFuel(float fuel);

        int getId();
        string getDate();
        string getHour();
        float getPrice();
        string getAirplaneModel();
        string getFromTo();
        float getDistance();
        string getCrew();
        float getFuel();

        bool reservar(Passenger, int);
        void cancelReserva(Passenger);
        void imprimirAsientos();
        void imprimirVuelos();
        

};

#endif