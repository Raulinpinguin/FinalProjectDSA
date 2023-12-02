#include "Airport.h"

Airport::Airport(string airportName, string city, string stateCode)
{
    _airportName = airportName;
    _city = city;
    _stateCode = stateCode;
}

void Airport::addFlightData(string monthS, string airlineCode, string airlineName, string arrivalsS, string totalDelaysS, string airlineDelaysS, string totalDelayTimeS, string airlineDelayTimeS)
{
    //Convert strings to integer or doubles accordingly.
    int month = stoi(monthS);
    int arrivals = stoi(arrivalsS);
    int totalDelays = stoi(totalDelaysS);
    double airlineDelays = stod(airlineDelaysS);
    double totalDelayTime = stod(totalDelayTimeS);
    double airlineDelayTime = stod(airlineDelayTimeS);

    //Search for month-airline pair in map
    if(_airlines.find(make_pair(month, airlineCode)) == _airlines.end())
    {
        //Create new airline data.
        Airline* newAirline = new Airline(airlineCode, airlineName);
        //Create new pair and add it to the map
        pair<int, string> key = make_pair(month, airlineCode);
        newAirline->addAirlineEntry(arrivals, totalDelays, airlineDelays, totalDelayTime, airlineDelayTime);
        _airlines[key] = newAirline;
    }
    else //Airline exists. Add Airline entry.
    {
        auto iter = _airlines.find(make_pair(month, airlineCode));
        iter->second->addAirlineEntry(arrivals, totalDelays, airlineDelays, totalDelayTime, airlineDelayTime);
    }

}

void Airport::printAirlinesInfo(int month)
{


}

void Airport::quickSort(vector<int>& values, int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(values, low, high);
        quickSort(values, low, pivotIndex - 1);
        quickSort(values, pivotIndex + 1, high);
    }
}

int Airport::partition(vector<int>& values, int low, int high)
{
    int pivot = values[low];
    int up = low, down = high;

    while(up < down)
    {
        while(values[up] <= pivot)
        {
            up++;
        }
        while(values[down] > pivot)
        {
            down--;
        }
        /*
        for(int i = up; i < high; i++)
        {
            if(values[up] > pivot)
                break;
            up++;
        }
        for(int i = high; i > low; i--)
        {
            if(values[down] < pivot)
                break;
            down--;
        }
         */

        if(up < down)
        {
            int temp = values[up];
            values[up] = values[down];
            values[down] = temp;
            //swap(values[up], values[down]);
        }
    }
    int temp = values[low];
    values[low] = values[down];
    values[down] = temp;
    //swap(values[low], values[down]);
    return down;
}

vector<Airport::Airline*> Airport::sortByNumberOfDelayFlights()
{

}
