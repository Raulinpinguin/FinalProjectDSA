#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
//#include "C.h"
 


class Airport
{
    struct Airline
    {
        std::string _airlineName;
        std::string _airlineCode;
        std::vector<int> _arrivals;
        std::vector<int> _delays;
        std::vector<double> _airlineDelays;
        std::vector<double> _delayTime;
        std::vector<double> _airlineDelayTime;
        double _arrivalsAvg, _delaysAvg, _airlineDelaysAvg, _delayTimeAvg, _airlineDelayTimeAvg;
        double _delayRatio;
        double _onTimePercentage;
        double _airlineOnTimePercentage;
        double _airlineDelayRatio;

        Airline(std::string airlineCode, std::string airlineName)
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

    std::string _airportName;
    std::string _city;
    std::string _stateCode;
    std::string _airportCode;

    //Airlines std::map has std::pair of month and airline-code as key and airline object as value.
    std::map<std::pair<int, std::string>, Airline*> _airlines;

    //Private Helper Methods
    //Calculates averages throughout the different years for all airlines data (arrivals, delays, etc)
    void calculateAverages()
    {
        for (auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
        {
            std::vector<int> arrivals = iter->second->_arrivals;
            double addArrivals = 0.0, addDelays = 0.0, addAirlineDelays = 0.0, addDelayTime = 0.0, addAirlineDelayTime = 0.0;
            for (int i = 0; i < arrivals.size(); i++)
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
            iter->second->_airlineDelayRatio = iter->second->_airlineDelaysAvg / iter->second->_arrivalsAvg;
        }
    }
    int partition(std::vector<double>& values, int low, int high)
    {
        double pivot = values[low];
        int up = low, down = high;

        while (up < down)
        {
            for (int j = up; j < high; j++) {
                if (values[up] > pivot) {
                    break;
                }
                up++;
            }
            for (int j = high; j > low; j--)
            {
                if (values[down] < pivot) {
                    break;
                }
                down--;
            }

            if (up < down)
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

public:
    //Constructor
    Airport(std::string airportCode, std::string airportName, std::string city, std::string stateCode)
    {
        _airportCode = airportCode;
        _airportName = airportName;
        _city = city;
        _stateCode = stateCode;
    }


    //Adds new flight delay data for a certain month and airline.
    void addFlightData(std::string monthS, std::string airlineCode, std::string airlineName, std::string arrivalsS, std::string totalDelaysS, std::string airlineDelaysS, std::string totalDelayTimeS, std::string airlineDelayTimeS)
    {
        //Convert std::strings to integer or doubles accordingly.
        int month = stoi(monthS);
        int arrivals = stoi(arrivalsS);
        int totalDelays = stoi(totalDelaysS);
        double airlineDelays = stod(airlineDelaysS);
        double totalDelayTime = stod(totalDelayTimeS);
        double airlineDelayTime = stod(airlineDelayTimeS);

        //Search for month-airline std::pair in std::map
        if (_airlines.find(make_pair(month, airlineCode)) == _airlines.end())
        {
            //Create new airline data.
            Airline* newAirline = new Airline(airlineCode, airlineName);
            //Create new std::pair and add it to the std::map
            std::pair<int, std::string> key = make_pair(month, airlineCode);
            newAirline->addAirlineEntry(arrivals, totalDelays, airlineDelays, totalDelayTime, airlineDelayTime);
            _airlines[key] = newAirline;
        }
        else //Airline exists. Add Airline entry.
        {
            auto iter = _airlines.find(make_pair(month, airlineCode));
            iter->second->addAirlineEntry(arrivals, totalDelays, airlineDelays, totalDelayTime, airlineDelayTime);
        }

    }


    //Returns a std::vector with the name of the Airlines with the least delay ratio Quicksort. Delay ratio = delays/arrivals.
    std::pair<std::vector<std::string>, std::vector<std::string>> QuicksortByDelayRatio(int month)
    {
        //Calculate averages for arrivals and delays.
        calculateAverages();

        //Sort by delayRatio
        std::vector<double> delayRatios;
        std::vector<std::string> onTimeRatios;
        for (auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
        {
            if (iter->first.first == month)
            {
                double tempDelayRatio = iter->second->_delayRatio;
                delayRatios.push_back(tempDelayRatio);
            }
        }

        quickSort(delayRatios, 0, delayRatios.size() - 1);

        for (int i = 0; i < delayRatios.size(); i++)
        {
            double onTimeRatio = (1 - delayRatios[i]) * 100;
            std::string onTimeRatioStr = std::to_string(onTimeRatio);
            onTimeRatioStr = onTimeRatioStr.substr(0, onTimeRatioStr.size() - 4);
            onTimeRatios.push_back(onTimeRatioStr);
        }

        std::vector<std::string> efficientAirlinesNames;
        std::set<std::string> visited;
        for (int i = 0; i < delayRatios.size(); i++)
        {

            for (auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
            {

                if (iter->second->_delayRatio == delayRatios[i])
                {
                    std::string airlineName = iter->second->_airlineName;
                    if (visited.count(airlineName) == 0) {
                        visited.insert(airlineName);
                        efficientAirlinesNames.push_back(airlineName);
                    }


                }
            }
        }

        std::pair<std::vector<std::string>, std::vector<std::string>> efficientAirlines = make_pair(efficientAirlinesNames, onTimeRatios);
        return efficientAirlines;
    }

    //Returns a std::vector with the name of the Airlines with the least airline delay ratio Quicksort. Airline Delay ratio = airline delays/delays.
    std::pair<std::vector<std::string>, std::vector<std::string>> QuicksortByAirlineDelayRatio(int month)
    {
        
        //Calculate averages for arrivals and delays.
        calculateAverages();
      

        //Sort by delayRatio
        std::vector<double> airlineDelayRatios;
        std::vector<std::string> airlineOnTimeRatios;
        for (auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
        {
            if (iter->first.first == month)
            {
                double tempairlineDelayRatio = iter->second->_airlineDelayRatio;
                airlineDelayRatios.push_back(tempairlineDelayRatio);
            }
        }

        quickSort(airlineDelayRatios, 0, airlineDelayRatios.size() - 1);

        
        for (int i = 0; i < airlineDelayRatios.size(); i++)
        {
            double airlineOnTimeRatio = (1 - airlineDelayRatios[i]) * 100;
            std::string airlineOnTimeRatioStr = std::to_string(airlineOnTimeRatio);
            airlineOnTimeRatioStr = airlineOnTimeRatioStr.substr(0, airlineOnTimeRatioStr.size() - 4);
            airlineOnTimeRatios.push_back(airlineOnTimeRatioStr);

        }

        std::vector<std::string> efficientAirlinesNames;
        std::set<std::string> visited;
        for (int i = 0; i < airlineDelayRatios.size(); i++)
        {
            for (auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
            {
                if (iter->second->_airlineDelayRatio == airlineDelayRatios[i])
                {
                    std::string airlineName = iter->second->_airlineName;
                    if (visited.count(airlineName) == 0) {
                        visited.insert(airlineName);
                        efficientAirlinesNames.push_back(airlineName);
                    }


                }
            }
        }


        std::pair<std::vector<std::string>, std::vector<std::string>> efficientAirlines = make_pair(efficientAirlinesNames, airlineOnTimeRatios);
        
        return efficientAirlines;
    }


    //Returns a std::vector with the name of the Airlines with the least delay ratio using Heapsort. Delay ratio = delays/arrivals.
    std::pair<std::vector<std::string>, std::vector<std::string>> HeapsortByDelayRatio(int month)
    {
        //Calculate averages for arrivals and delays.
        calculateAverages();

        //Sort by delayRatio
        std::vector<double> delayRatios;
        std::vector<std::string> onTimeRatios;
        for (auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
        {
            if (iter->first.first == month)
            {
                double tempDelayRatio = iter->second->_delayRatio;
                delayRatios.push_back(tempDelayRatio);
            }
        }

        heapSort(delayRatios, delayRatios.size());

        for (int i = 0; i < delayRatios.size(); i++)
        {
            double onTimeRatio = (1 - delayRatios[i]) * 100;
            std::string onTimeRatioStr = std::to_string(onTimeRatio);
            onTimeRatioStr = onTimeRatioStr.substr(0, onTimeRatioStr.size() - 4);
            onTimeRatios.push_back(onTimeRatioStr);
        }

        std::vector<std::string> efficientAirlinesNames;
        std::set<std::string> visited;
        for (int i = 0; i < delayRatios.size(); i++)
        {
            for (auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
            {
                if (iter->second->_delayRatio == delayRatios[i])
                {
                    std::string airlineName = iter->second->_airlineName;
                    if (visited.count(airlineName) == 0) {
                        visited.insert(airlineName);
                        efficientAirlinesNames.push_back(airlineName);
                    }


                }
            }
        }

        std::pair<std::vector<std::string>, std::vector<std::string>> efficientAirlines = make_pair(efficientAirlinesNames, onTimeRatios);
        return efficientAirlines;
    }

    //Returns a std::vector with the name of the Airlines with the least airline delay ratio using Heapsort. Airline Delay ratio = airline delays/delays.
    std::pair<std::vector<std::string>, std::vector<std::string>> HeapsortByAirlineDelayRatio(int month)
    {
        //Calculate averages for arrivals and delays.
        calculateAverages();

        //Sort by delayRatio
        std::vector<double> airlineDelayRatios;
        std::vector<std::string> airlineOnTimeRatios;
        for (auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
        {
            if (iter->first.first == month)
            {
                double tempairlineDelayRatio = iter->second->_airlineDelayRatio;
                airlineDelayRatios.push_back(tempairlineDelayRatio);
            }
        }

        heapSort(airlineDelayRatios, airlineDelayRatios.size());

        for (int i = 0; i < airlineDelayRatios.size(); i++)
        {
            double airlineOnTimeRatio = (1 - airlineDelayRatios[i]) * 100;
            std::string airlineOnTimeRatioStr = std::to_string(airlineOnTimeRatio);
            airlineOnTimeRatioStr = airlineOnTimeRatioStr.substr(0, airlineOnTimeRatioStr.size() - 4);
            airlineOnTimeRatios.push_back(airlineOnTimeRatioStr);

        }


        std::vector<std::string> efficientAirlinesNames;
        std::set<std::string> visited;
        for (int i = 0; i < airlineDelayRatios.size(); i++)
        {
            for (auto iter = _airlines.begin(); iter != _airlines.end(); iter++)
            {
                if (iter->second->_airlineDelayRatio == airlineDelayRatios[i])
                {
                    std::string airlineName = iter->second->_airlineName;
                    if (visited.count(airlineName) == 0) {
                        visited.insert(airlineName);
                        efficientAirlinesNames.push_back(airlineName);
                    }


                }
            }
        }


        std::pair<std::vector<std::string>, std::vector<std::string>> efficientAirlines = make_pair(efficientAirlinesNames, airlineOnTimeRatios);
        return efficientAirlines;
    }


    void quickSort(std::vector<double>& values, int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partition(values, low, high);
            quickSort(values, low, pivotIndex - 1);
            quickSort(values, pivotIndex + 1, high);
        }
        

    }

    void heapSort(std::vector<double>& values, int size)
    {
        // Building heap (max heap)
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(values, size, i);

        // Extract min value and swap it to the end of the std::vector
        for (int i = size - 1; i >= 0; i--) {

            std::swap(values[0], values[i]);

            // max heapify on the rest of the heap
            heapify(values, i, 0);
        }
    }

    void heapify(std::vector<double>& values, int size, int node)
    {
        int max = node; // Initialize largest as root Since we are using 0 based indexing
        int left = 2 * node + 1; // left child
        int right = 2 * node + 2; // right child

        // check if left child is larger than root and update max value index
        if (left < size && values[left] > values[max])
            max = left;

        // check if right child larger than largest and update max value index
        if (right < size && values[right] > values[max])
            max = right;

        // Is largest not root?
        if (max != node) {
            std::swap(values[node], values[max]);

            // Recursively heapify the sub-tree
            heapify(values, size, max);
        }
    }
};