#pragma once
#include <string>
#include <vector>
#include <map>
//#include "Carrier.h"
using namespace std;

class Airport
{
    struct Carrier
    {
        string carrierName;
        string arrivals;
        string delayedArrivals;
        string carrierDelays;
        string delayTime;
        string carrierDelayTime;

        Carrier(string carrierName, string arrivals, string delayedArrivals, string carrierDelays, string delayTime, string carrierDelayTime)
        {
            string _carrierName = carrierName;
            string _arrivals = arrivals;
            string _delayedArrivals = delayedArrivals;
            string _carrierDelays = carrierDelays;
            string _delayTime = delayTime;
            string _carrierDelayTime = carrierDelayTime;
        }
    };

    string _airportName;
    //Airlines map has months as key and a vector of all carriers that offer flights to the airport.
    map<string, vector<Carrier*>> _airlines;
public:
    //Constructor
    Airport(string airportName);

    void addFlightData(string month, string carrierCode, string carrierName, string airportCode, string airportName, string arrivals, string delayedArrivals, string carrierCount, string delayTime, string carrierDelay);

    vector<Carrier*> sortByNumberOfDelayFlights();

    //TODO: Implement quickSort algorithm for any set of values given as a vector
    void quickSort(vector<int>& values, int low, int high);


};