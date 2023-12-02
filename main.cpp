#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include "Airport.h"

using namespace std;
int main()
{
    cout << "Airline Delay Finder" << endl;

    //Read all data
    string filePath = "Airline_Delay_Cause.csv";

    //Open CSV file
    ifstream file(filePath);

    //Check if file is open
    if(!file.is_open())
    {
        cout << "Error opening file: " << filePath << endl;
    }

    //Create map to store all airports. Key is airport code, value is airport object.
    map<string, vector<Airport*>> airports;

    //this is a test

    string line;
    string year, month, carrierCode, carrierName, airportCode, city, state, airportName, arrivals, delayedArrivals, carrierCount, weatherCount, nasCount, securityCount, lateFlightCount, cancelled, diverted, delayTime, carrierDelay, weatherDelay, nasDelay, securityDelay, lateFlightDelay;

    //Get rid of first line
    getline(file, line);

    while(getline(file, line))
    {
        istringstream iss(line);

        getline(iss, year, ',');
        getline(iss, month, ',');
        getline(iss, carrierCode, ',');
        getline(iss, carrierName, ',');
        getline(iss, airportCode, ',');

        getline(iss, city, ',');
        getline(iss, state, ':');

        getline(iss, airportName, ',');
        getline(iss, arrivals, ',');
        getline(iss, delayedArrivals, ',');
        getline(iss, carrierCount, ',');
        getline(iss, weatherCount, ',');
        getline(iss, nasCount, ',');
        getline(iss, securityCount, ',');
        getline(iss, lateFlightCount, ',');
        getline(iss, cancelled, ',');
        getline(iss, diverted, ',');
        getline(iss, delayTime, ',');
        getline(iss, carrierDelay, ',');
        getline(iss, weatherDelay, ',');
        getline(iss, nasDelay, ',');
        getline(iss, securityDelay, ',');
        getline(iss, lateFlightDelay, ',');

        //Create Airport object
        Airport* airport = new Airport(airportName);

        //Add data to airport
        airport->addFlightData(month, carrierCode, carrierName, airportCode, airportName, arrivals, delayedArrivals, carrierCount, delayTime, carrierDelay);

        //Add airport to airports map
        airports[airportCode].push_back(airport);
    }




    /*
    cout << "Year: " << year << endl;
    cout << "Airport name" << airportName << endl;
    cout << "Airport code: " << airportCode << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Arriving flights " <<  arrivals << endl;
    cout << "Carrier name: " << carrierName << endl;
    cout << "carrier count: " << carrierCount << endl;
    cout << "delay time: " << delayTime << endl;
     */


    return 0;
}
