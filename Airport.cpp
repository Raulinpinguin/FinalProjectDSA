#include "Airport.h"

Airport::Airport(string airportName)
{
    _airportName = airportName;
}

void Airport::addFlightData(string month, string carrierCode, string carrierName, string airportCode, string airportName, string arrivals, string delayedArrivals, string carrierDelays, string delayTime, string carrierDelayTime)
{
    Carrier* carrier = new Carrier(carrierName, arrivals, delayedArrivals, carrierDelays, delayTime, carrierDelayTime);
    //Consider storing a vector of arrival values, delayedArrivals, carrierDelays etc. Each entry in vector corresponds to a year (same month different years).
    //Once data is read, average values.
    //Other option is to create maps (key: month, value: vector of values) for each value when reading data,  calculate  averages, and then pass them to Airport object.

    _airlines.find(month)->second;

    _airlines[month].push_back(carrier);
}

void Airport::quickSort(vector<int>& values, int low, int high)
{
    if(low < high)
    {
        //int pivot = partition();
        //dfghjkl
    }

}

vector<Airport::Carrier*> Airport::sortByNumberOfDelayFlights()
{

}
