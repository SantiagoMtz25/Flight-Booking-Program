#include <iostream>
#include "Passenger.h"       
using namespace std;

//constructores 
Passenger::Passenger(){
    d_name = "";
    d_phone = 0; 
    d_kilometraje = 0; 
    d_asiento = -1; 
}

Passenger::Passenger(string name, int phone, float kilometraje){
    d_name = name;
    d_phone = phone; 
    d_kilometraje = kilometraje;
    d_asiento = -1;

}

//setters 
void Passenger::setName(string name){
    d_name = name; 
}

void Passenger::setPhone(int phone){
    d_phone = phone; 
}

void Passenger::setKilometraje(float kilometraje){
  d_kilometraje = kilometraje;
}

void Passenger::setAsiento(int asiento){
  d_asiento = asiento;
}

//getters 
string Passenger::getName(){
    return d_name;
}

int Passenger::getPhone(){
    return d_phone;
}

float Passenger::getKilometraje(){
  return d_kilometraje;
}

int Passenger::getAsiento(){
  return d_asiento;
}