#include <iostream>
#include "Airline.h"       
using namespace std;

//constructores 
Airline::Airline(){
    d_boardingCity = "";
    d_shortName = "";
    d_name = "";
}

Airline::Airline(string name, string boardingCity, string shortName){
    d_name = name;
    d_boardingCity = boardingCity;
    d_shortName = shortName;
}

//setters 
void Airline::setBoardingCity(string boardingCity){
    d_boardingCity = boardingCity; 
}

void Airline::setShortName(string shortName){
    d_shortName = shortName; 
}

void Airline::setName(string name){
  d_name = name;
}

//getters 
string Airline::getBoardingCity(){
    return d_boardingCity;
}

string Airline::getShortName(){
    return d_shortName;
}

string Airline::getName(){
  return d_name;
}