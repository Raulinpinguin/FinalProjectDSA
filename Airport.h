#pragma once
#include <string>
#include <vector>
#include <map>
//#include "C.h"
using namespace std;

class Airport
{
    struct Airline
    {
        string _airlineName;
        string _airlineCode;
        vector<int> _arrivals;
        vector<int> _delayedArrivals;
        vector<double> _airlineDelays;
        vector<double> _delayTime;
        vector<double> _airlineDelayTime;

        Airline(string airlineCode, string airlineName)
        {
            string _airlineName = airlineName;
            string _airlineCode = airlineCode;
        }

        void addAirlineEntry(int arrivals, int delayedArrivals, double airlineDelays, double delayTime, double airlineDelayTime)
        {
            _arrivals.push_back(arrivals);
            _delayedArrivals.push_back(delayedArrivals);
            _airlineDelays.push_back(airlineDelays);
            _delayTime.push_back(delayTime);
            _airlineDelayTime.push_back(airlineDelayTime);
        }
    };

    string _airportName;
    string _city;
    string _stateCode;

    //Airlines map has pair of month and airline-code as key and airline object as value.
    map<pair<int, string>, Airline*> _airlines;

public:
    //Constructor
    Airport(string airportName, string city, string stateCode);

    void addFlightData(string month, string airlineCode, string airlineName, string arrivalsS, string totalDelaysS, string airlineDelaysS, string totalDelayTimeS, string airlineDelayTimeS);

    void printAirlinesInfo(int month);
    vector<Airline*> sortByNumberOfDelayFlights();

    void quickSort(vector<int>& values, int low, int high);
    int partition(vector<int>& values, int low, int high);

};