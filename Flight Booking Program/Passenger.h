#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
using namespace std; 

class Passenger{
    private: 
        string d_name; 
        int d_phone; 
        float d_kilometraje; 
        int d_asiento; 

    public: 
        Passenger();
        Passenger(string name, int phone, float d_kilometraje);

        void setName(string name);
        void setPhone(int phone);
        void setKilometraje(float kilometraje);
        void setAsiento(int asiento);

        string getName();
        int getPhone();
        float getKilometraje();
        int getAsiento();

};


#endif