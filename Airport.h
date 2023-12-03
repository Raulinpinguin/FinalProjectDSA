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
        double _airlineDelayRatio;

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
    string _airportCode;

    //Airlines map has pair of month and airline-code as key and airline object as value.
    map<pair<int, string>, Airline*> _airlines;

    //Private Helper Methods
    //Calculates averages throughout the different years for all airlines data (arrivals, delays, etc)
    void calculateAverages();
    int partition(vector<double>& values, int low, int high);

public:
    //Constructor
    Airport(string airportCode, string airportName, string city, string stateCode);

    //Print Airport Info
    void printAirportInfo();

    //Adds new flight delay data for a certain month and airline.
    void addFlightData(string monthS, string airlineCode, string airlineName, string arrivalsS, string totalDelaysS, string airlineDelaysS, string totalDelayTimeS, string airlineDelayTimeS);

    //Prints all airlines' info for a particular month.
    void printAirlinesInfo(int month);

    //Returns a vector with the name of the Airlines with the least delay ratio. Delay ratio = delays/arrivals.
    vector<string> findAirlinesWithLeastDelayRatio(int month);

    //Returns a vector with the name of the Airlines with the least airline delay ratio. Airline Delay ratio = airline delays/delays.
    vector<string> findAirlinesWithLeastAirlineDelayRatio(int month);

    void quickSort(vector<double>& values, int low, int high);

    void heapSort(vector<double>& values, int size);

    void extractMin();

    void heapify(vector<double>& values, int size, int node);
};