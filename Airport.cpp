#include <iostream>
#include "Airport.h"


Airport::Airport(string airportName, string city, string stateCode)
{
    _airportName = airportName.substr(1, airportName.size() - 2);
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
    calculateAverages();
    cout << "Airport: " << _airportName << endl;
    cout << "Month: " << month << endl;
    for(auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
    {

        for(int i = 0; i < iter->second->_arrivals.size(); i++)
        {
            cout << "Year: " << i + 1 << endl;
            cout << "Airline: " << iter->second->_airlineName << ", ";
            cout << "Arrivals: " << iter->second->_arrivals[i] << ", ";
            cout << "Delayed Arrivals: " << iter->second->_delays[i] << ", ";
            cout << "Airline Delayed Arrivals:  " << iter->second->_airlineDelays[i] << ", ";
            cout << "Delay time: " << iter->second->_delayTime[i] << ", ";
        }

        cout << "Avg Arrivals: " << iter->second->_arrivalsAvg << ", ";
        cout << "Avg Delays: " << iter->second->_delaysAvg << ", ";
        cout << "Avg Delay Ratio: " << iter->second->_delayRatio << ", ";
        cout << endl;
    }
    cout << endl;
}

void Airport::calculateAverages()
{
    for(auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
    {
        vector<int> arrivals = iter->second->_arrivals;
        double addArrivals = 0.0, addDelays = 0.0, addAirlineDelays = 0.0, addDelayTime = 0.0, addAirlineDelayTime = 0.0;
        for(int i = 0; i < arrivals.size(); i++)
        {
            addArrivals += iter->second->_arrivals[i];
            addDelays += iter->second->_delays[i];
            addAirlineDelays += iter->second->_airlineDelays[i];
            addDelayTime += iter->second->_delayTime[i];
            addAirlineDelayTime += iter->second->_airlineDelayTime[i];
        }
        iter->second->_arrivalsAvg = addArrivals / iter->second->_arrivals.size();
        iter->second->_delaysAvg = addDelays / iter->second->_delays.size();
        iter->second->_airlineDelaysAvg = addAirlineDelays / iter->second->_airlineDelays.size();
        iter->second->_delayTimeAvg = addDelayTime / iter->second->_delayTime.size();
        iter->second->_airlineDelayTimeAvg = addAirlineDelayTime / iter->second->_airlineDelayTime.size();
        iter->second->_delayRatio = iter->second->_delaysAvg / iter->second->_arrivalsAvg;
    }
}

void Airport::findAirlinesWithLeastDelayRatio(int month)
{
    //Calculate averages for arrivals and delays.
    calculateAverages();

    //Sort by delayRatio
    vector<double> delayRatios;
    for(auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
    {
        if(iter->first.first == month)
        {
            double tempDelayRatio = iter->second->_delayRatio;
            delayRatios.push_back(tempDelayRatio);
        }
    }

    cout << "Delay ratios size:  " << delayRatios.size() << endl;
    quickSort(delayRatios, 0, delayRatios.size() - 1);

    cout << "Sorted Delay ratios" << endl;
    for(int i = 0; i < delayRatios.size(); i++)
    {
        cout << delayRatios[i] << ", ";
    }
    cout << endl;

    vector<string> efficientAirlines;
    cout << "Most efficient airlines: " << endl;
    int i = 0, j = 0;

    for(int i = 0; i < delayRatios.size(); i++)
    {
        for(auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
        {
            if(iter->second->_delayRatio == delayRatios[i])
            {
                string airlineName = iter->second->_airlineName;
                efficientAirlines.push_back(airlineName);
                cout << airlineName << ", ";
            }
        }
    }
    cout << endl;
}



void Airport::quickSort(vector<double>& values, int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(values, low, high);
        quickSort(values, low, pivotIndex - 1);
        quickSort(values, pivotIndex + 1, high);
    }
}

int Airport::partition(vector<double>& values, int low, int high)
{
    double pivot = values[low];
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
            double temp = values[up];
            values[up] = values[down];
            values[down] = temp;
            //swap(values[up], values[down]);
        }
    }
    double temp = values[low];
    values[low] = values[down];
    values[down] = temp;
    //swap(values[low], values[down]);
    return down;
}

vector<Airport::Airline*> Airport::sortByNumberOfDelayFlights()
{

}
