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
    map<string, Airport*> airports;

    //this is a test

    string line;
    string year, month, airlineCode, airlineName, airportCode, city, state, airportName, arrivals, delayedArrivals, airlineCount, weatherCount, nasCount, securityCount, lateFlightCount, cancelled, diverted, delayTime, airlineDelay, weatherDelay, nasDelay, securityDelay, lateFlightDelay;

    //Get rid of first line
    getline(file, line);

    while(getline(file, line))
    {
        istringstream iss(line);

        getline(iss, year, ',');
        getline(iss, month, ',');
        getline(iss, airlineCode, ',');
        getline(iss, airlineName, ',');
        getline(iss, airportCode, ',');

        getline(iss, city, ',');
        getline(iss, state, ':');

        getline(iss, airportName, ',');
        getline(iss, arrivals, ',');
        getline(iss, delayedArrivals, ',');
        getline(iss, airlineCount, ',');
        getline(iss, weatherCount, ',');
        getline(iss, nasCount, ',');
        getline(iss, securityCount, ',');
        getline(iss, lateFlightCount, ',');
        getline(iss, cancelled, ',');
        getline(iss, diverted, ',');
        getline(iss, delayTime, ',');
        getline(iss, airlineDelay, ',');
        getline(iss, weatherDelay, ',');
        getline(iss, nasDelay, ',');
        getline(iss, securityDelay, ',');
        getline(iss, lateFlightDelay, ',');

        //Create Airport object
        Airport* airport = new Airport(airportName, city, state);

        //Add data to airport
        airport->addFlightData(month, airlineCode, airlineName, arrivals, delayedArrivals, airlineCount, delayTime, airlineDelay);

        //Check if airport already exists
        //If not add it to the map, otherwise add flight data to the existing airport.
        //Add airport to airports map
        airports[airportCode] = airport;
        break;
    }

    for(auto iter = airports.begin(); iter != airports.end(); iter++)
    {
        cout << "Airport Code: " << iter->first << endl;
        cout << "Month: " << month << endl;


    }


    vector<int> unordered = {-100,0,4,12,6,3,9,7,2345,-3,-6,35, 6000};
    Airport trial("MCO", "Orlando", "FL");

    trial.quickSort(unordered, 0, 12);
    for(int i = 0; i < unordered.size(); i++)
    {
        cout << ", " << unordered[i];
    }
    cout << endl;




    /*
      cout << "Year: " << year << endl;
    cout << "Airport name" << airportName << endl;
    cout << "Airport code: " << airportCode << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Arriving flights " <<  arrivals << endl;
    cout << "airline name: " << airlineName << endl;
    cout << "airline count: " << airlineCount << endl;
    cout << "delay time: " << delayTime << endl;

     */


    return 0;
}
