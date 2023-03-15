#ifndef AIRPORT_H
#define AIRPORT_H
#include <string>
#include "Airline.h"
using namespace std;


class Airport{
    private: 
        string d_id;
        string d_date;
        string d_city;
        string d_country;
        int d_totalTransactions;
        float d_totalDailyIncomes;
        
        
    public: 
        Airport();
        Airport(string id, string date, string city, string country,
                int totalTransactions, float totalDailyIncomes);

        void setId(string id);
        void setDate(string date);
        void setCity(string city);
        void setContry(string country);
        void setTotalTrasactions(int totalTransactions);
        void setTotalDailyIncomes(float totalDailyIncomes);

        string getId();
        string getDate();
        string getCity();
        string getContry();
        int getTotalTransactions();
        float getTotalDailyIncomes();

        void startOperations(string date);
        void closeOperations(int totalTransactions, float totalDailyIncomes);

};


#endif