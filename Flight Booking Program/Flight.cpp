#include <iostream>
#include "Flight.h"       
using namespace std;

//constructores 
Flight::Flight(){
    d_id = 0;
    d_date = "";
    d_hour = "";
    d_price = 0;
    d_airplaneModel = "";
    d_fromTo = "";
    d_distance = 0;
    d_crew = "";
    d_fuel = 0;
    for (int i = 0; i < MAX_ASIENTOS; i++){
      arrDispAsientos[i] = true;
      arrPasajeros[i] = Passenger();
    }
    
}

Flight::Flight(int id, string date, string hour, float price, string airplaneModel, 
    string fromTo, float distance, string crew, float fuel){

    d_id = id; 
    d_date = date; 
    d_hour = hour; 
    d_price = price; 
    d_airplaneModel = airplaneModel; 
    d_fromTo = fromTo;
    d_distance = distance; 
    d_crew = crew; 
    d_fuel = fuel; 
    for (int i = 0; i < MAX_ASIENTOS; i++){
        arrDispAsientos[i] = true;
        arrPasajeros[i] = Passenger();
    }

}

//setters 
void Flight::setId(int id){
  d_id = id; 
}

void Flight::setDate(string date){
    d_date = date; 
}

void Flight::setHour(string hour){
    d_hour = hour; 
}

void Flight::setPrice(float price){
    d_price = price;
}

void Flight::setAirplaneModel(string airplaneModel){
    d_airplaneModel = airplaneModel;
}

void Flight::setFromTo(string fromTo){
    d_fromTo = fromTo;
}

void Flight::setDistance(float distance){
    d_distance = distance;
}

void Flight::setCrew(string crew){
    d_crew = crew;
}

void Flight::setFuel(float fuel){
    d_fuel = fuel; 
}

//getters 
int Flight::getId(){
  return d_id;
}

string Flight::getDate(){
    return d_date;
}

string Flight::getHour(){
    return d_hour;
}

float Flight::getPrice(){
    return d_price;
}

string Flight::getAirplaneModel(){
    return d_airplaneModel;
}

string Flight::getFromTo(){
    return d_fromTo;
}

float Flight::getDistance(){
    return d_distance; 
}

string Flight::getCrew(){
    return d_crew; 
}

float Flight::getFuel(){
    return d_fuel; 
}

// --------------

bool Flight::reservar(Passenger pasajero, int asiento){
  
  if (arrDispAsientos[asiento] == true){
    pasajero.setAsiento(asiento);

    arrDispAsientos[asiento] = false; 
    pasajero.setKilometraje(pasajero.getKilometraje() + d_distance);

    arrPasajeros[asiento] = pasajero;

    cout << "Nombre: " << pasajero.getName() << endl; 
    cout << "Numero: " << pasajero.getPhone() << endl;

    float t_pagar = 0;

    if (pasajero.getKilometraje() > 50000){
      t_pagar = d_price - (d_price * 0.1);
      cout << "Total a pagar: " << t_pagar << endl; 
    }
    
    pasajero.setKilometraje(pasajero.getKilometraje() + d_distance);

    return true; 
  } 
  else {
    cout << "Asiento ocupado. \nReserva no realizada. " << endl; 
    
    return false; 
  }
}

void Flight::cancelReserva(Passenger pasajero){

  if (pasajero.getAsiento() == -1){
    cout << "No has reservado ningun asiento. " << endl; 
    return;
  }
  arrDispAsientos[pasajero.getAsiento()] = false;
  pasajero.setAsiento(-1);
  arrPasajeros[pasajero.getAsiento()] = Passenger();

  pasajero.setKilometraje(pasajero.getKilometraje() - d_distance);

  cout << "Se ha cancelado con exito. " << endl; 

}

void Flight::imprimirAsientos(){
  cout << "Disponibles: o, Ocupado: x" << endl << endl; 
  for (int i = 0; i < MAX_ASIENTOS; i+=4){ 
    printf("%02d %02d   %02d %02d\n", i, i+1, i+2, i+3); 
    printf("%s  %s    %s  %s", (arrDispAsientos[i] ? "o" : "x"), (arrDispAsientos[i+1] ? "o" : "x"), (arrDispAsientos[i+2] ? "o" : "x"), (arrDispAsientos[i+3] ? "o" : "x"));
    cout << endl; 
  }
}

void Flight::imprimirVuelos(){
  cout << endl << "Numero de vuelo: " << d_id << endl
  << "Fecha: " << d_date << endl
  << "Hora de salida: " << d_hour << endl
  << "Destino: " << d_fromTo << endl
  << "Precio: " << d_price << endl;
}