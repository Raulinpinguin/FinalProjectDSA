#include <iostream>
#include "Airport.h"


Airport::Airport(string airportCode, string airportName, string city, string stateCode)
{
    _airportCode = airportCode;
    _airportName = airportName;
    _city = city;
    _stateCode = stateCode;
}

void Airport::printAirportInfo()
{
    cout << "Airport Name: " << _airportName << "(" << _airportCode << ")" <<  ". City: " << _city << ". State: " << _stateCode << endl;
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
        if(iter->second->_airlineCode == "AA" && iter->first.first == 7)
        {
            for(int i = 0; i < iter->second->_arrivals.size(); i++)
            {
                cout << "Year: " << i + 1 << endl;
                cout << "Airline: " << iter->second->_airlineName << ", ";
                cout << "Code: " << iter->second->_airlineCode << ", ";
                cout << "Arrivals: " << iter->second->_arrivals[i] << ", ";
                cout << "Delayed Arrivals: " << iter->second->_delays[i] << ", ";
                cout << "Airline Delayed Arrivals:  " << iter->second->_airlineDelays[i] << ", ";
                cout << "Delay time: " << iter->second->_delayTime[i] << ", ";
                cout << "Airline Delay time: " << iter->second->_airlineDelayTime[i] << ", ";
                cout << endl;
            }
            cout << endl;
            cout << "Avg Arrivals: " << iter->second->_arrivalsAvg << ", ";
            cout << "Avg Delays: " << iter->second->_delaysAvg << ", ";
            cout << "Avg Delay Ratio: " << iter->second->_delayRatio << ", ";
            cout << endl;
        }
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
        iter->second->_airlineDelayRatio = iter->second->_airlineDelaysAvg / iter->second->_delaysAvg;
    }
}

vector<string> Airport::findAirlinesWithLeastDelayRatio(int month)
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

    //cout << "Delay ratios size:  " << delayRatios.size() << endl;
    quickSort(delayRatios, 0, delayRatios.size() - 1);

    cout << "Airport: " << _airportName << ", month: " << month << endl;
    cout << "Sorted Delay ratios" << endl;
    for(int i = 0; i < delayRatios.size(); i++)
    {
        cout << delayRatios[i] << ", ";
    }
    cout << endl;

    vector<string> efficientAirlines;
    cout << "Most efficient airlines: " << endl;

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
    cout << endl;
    return efficientAirlines;
}

vector<string> Airport::findAirlinesWithLeastAirlineDelayRatio(int month)
{
    //Calculate averages for arrivals and delays.
    calculateAverages();

    //Sort by delayRatio
    vector<double> airlineDelayRatios;
    for(auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
    {
        if(iter->first.first == month)
        {
            double tempDelayRatio = iter->second->_airlineDelayRatio;
            airlineDelayRatios.push_back(tempDelayRatio);
        }
    }

    //cout << "Delay ratios size:  " << delayRatios.size() << endl;
    quickSort(airlineDelayRatios, 0, airlineDelayRatios.size() - 1);

    cout << "Sorted Delay ratios" << endl;
    for(int i = 0; i < airlineDelayRatios.size(); i++)
    {
        cout << airlineDelayRatios[i] << ", ";
    }
    cout << endl;

    vector<string> efficientAirlines;
    cout << "Most efficient airlines: " << endl;

    for(int i = 0; i < airlineDelayRatios.size(); i++)
    {
        for(auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
        {
            if(iter->second->_airlineDelayRatio == airlineDelayRatios[i])
            {
                string airlineName = iter->second->_airlineName;
                efficientAirlines.push_back(airlineName);
                cout << airlineName << ", ";
            }
        }
    }
    cout << endl;
    return efficientAirlines;
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

void Airport::heapSort(vector<double>& values, int size) // keep editing later
{
    // Building heap (max heap)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(values, size, i);
 
    // Take top element from heap
    for (int i = size - 1; i >= 0; i--) {
        // Move current root to end
        swap(values[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(values, i, 0);
    }
}

void Airport::extractMin( )
{
   values[0] = values[--currentSize];
    heapifyDown(0);
}
void Airport::heapify(vector<double>& values, int size, int node)
{
    int max = node; // Initialize largest as root Since we are using 0 based indexing
    int left = 2 * node + 1; // left child
    int right = 2 * node + 2; // right child

    // If left child is larger than root
    if (l < size && values[left] > values[max])
        max = l;
 
    // If right child is larger than largest so far
    if (r < size && values[right] > values[max])
        max = r;
 
    // If largest is not root
    if (max != node) {
        swap(values[node], values[max]);
        
        // Recursively heapify the affected sub-tree
        heapify(values, size, max);
    }
 
}

