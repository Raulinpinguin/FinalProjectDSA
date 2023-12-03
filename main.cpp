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
        city = city.substr(1, city.size());

        getline(iss, state, ':');
        state = state.substr(1, state.size());

        getline(iss, airportName, ',');
        airportName = airportName.substr(1, airportName.size() - 2);

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

        //Check if data exists (some rows in data set are empty)
        if(arrivals == "" || delayedArrivals == "")
        {
            continue;
        }

        //If airport does not exist
        if(airports.find(airportCode) == airports.end())
        {
            //Create Airport object
            Airport* airport = new Airport(airportCode, airportName, city, state);

            //Add airport to airports map
            airports[airportCode] = airport;

            //Add data to airport
            airports[airportCode]->addFlightData(month, airlineCode, airlineName, arrivals, delayedArrivals, airlineCount, delayTime, airlineDelay);
        }
        else //airport exists in map
        {
            //Add flight data to the existing airport.
            airports[airportCode]->addFlightData(month, airlineCode, airlineName, arrivals, delayedArrivals, airlineCount, delayTime, airlineDelay);
        }
    }

    //airports["ATL"]->printAirportInfo();
    //airports["ATL"]->printAirlinesInfo(7);

    //User requests to see the airlines with least delays/arrivals percentage (How many of the arrivals were delayed).
    //airports["PWM"]->findAirlinesWithLeastDelayRatio(7);
    airports["ATL"]->findAirlinesWithLeastAirlineDelayRatio(1);


    //airports["ATL"]->findAirlinesWithLeastAirlineDelayRatio(7);

    /*
     *
    vector<double> unordered = {-100,0,4,12,6,3,9,7,2345,-3,-6,35, 6000};
    Airport trial("MCO", "Orlando", "FL");

    trial.quickSort(unordered, 0, 12);
    for(int i = 0; i < unordered.size(); i++)
    {
        cout << ", " << unordered[i];
    }

        Airport* dorado = new Airport("Dorado", "Bogota", "Col");

        dorado->addFlightData("1", "AV", "Avianca", "12", "4", "3", "100", "50");
        dorado->addFlightData("1", "AV", "Avianca", "13", "1", "1", "130", "90");
        dorado->addFlightData("1", "AV", "Avianca", "14", "5", "4", "160", "100");

        dorado->printAirlinesInfo(1);
        cout << "Year: " << year << endl;
        cout << "Month: " << month << endl;
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
