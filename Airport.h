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
        vector<int> _delays;
        vector<double> _airlineDelays;
        vector<double> _delayTime;
        vector<double> _airlineDelayTime;
        double _arrivalsAvg, _delaysAvg, _airlineDelaysAvg, _delayTimeAvg, _airlineDelayTimeAvg;
        double _delayRatio;

        Airline(string airlineCode, string airlineName)
        {
            _airlineName = airlineName;
            _airlineCode = airlineCode;
        }

        void addAirlineEntry(int arrivals, int delays, double airlineDelays, double delayTime, double airlineDelayTime)
        {
            _arrivals.push_back(arrivals);
            _delays.push_back(delays);
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

    void calculateAverages();

public:
    //Constructor
    Airport(string airportName, string city, string stateCode);

    //Adds new flight delay data for a certain month and airline.
    void addFlightData(string month, string airlineCode, string airlineName, string arrivalsS, string totalDelaysS, string airlineDelaysS, string totalDelayTimeS, string airlineDelayTimeS);

    //Prints all airlines info for a particular month.
    void printAirlinesInfo(int month);
    vector<Airline*> sortByNumberOfDelayFlights();

    //
    void findAirlinesWithLeastDelayRatio(int month);

    void quickSort(vector<double>& values, int low, int high);
    int partition(vector<double>& values, int low, int high);

};