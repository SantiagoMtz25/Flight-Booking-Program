#include <iostream>
#include "Airport.h"       
using namespace std;

//constructores 
Airport::Airport(){
    d_id = "";
    d_date = "";
    d_city = "";
    d_country = "";
    d_totalTransactions = 0;
    d_totalDailyIncomes = 0; 
}

Airport::Airport(string id, string date, string city, string country,
                int totalTransactions, float totalDailyIncomes){
    d_id = id;
    d_date = date;
    d_city = city;
    d_country = country;
    d_totalTransactions = totalTransactions;
    d_totalDailyIncomes = totalDailyIncomes; 
}

//setters 
void Airport::setId(string id){
    d_id = id; 
}

void Airport::setDate(string date){
    d_date = date;
}

void Airport::setCity(string city){
    d_city = city;
}

void Airport::setContry(string country){
    d_country = country; 
}

void Airport::setTotalTrasactions(int transactions){
    d_totalTransactions = transactions;
}

void Airport::setTotalDailyIncomes(float totalDailyIncomes){
    d_totalDailyIncomes = totalDailyIncomes;
}

//getters 
string Airport::getId(){
    return d_id;
}

string Airport::getDate(){
    return d_date;
}

string Airport::getCity(){
    return d_city;
}

string Airport::getContry(){
    return d_country; 
}

int Airport::getTotalTransactions(){
    return d_totalTransactions;
}

float Airport::getTotalDailyIncomes(){
    return d_totalDailyIncomes;
}