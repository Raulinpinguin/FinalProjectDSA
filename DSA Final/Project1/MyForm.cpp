
//This code is based on this tutorial for setting up WinFrame:
//https://www.youtube.com/watch?v=s7q0M4gJyB0&list=PL2i17lRog5pBe7t9zJdFdugQ6bxgjntJD&index=3

#include "MyForm.h"
//Begin reference 
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array <String^>^ args) 
{

//End reference here
    //Read all data
    std::string filePath = "Airline_Delay_Cause.csv";

    //Open CSV file
    std::ifstream file(filePath);

    //Check if file is open
    if (!file.is_open())
    {
        std::cout << "Error opening file: " << filePath << std::endl;
    }

    //Create map to store all airports. Key is airport code, value is airport object.
    std::map<std::string, Airport*> airports;

    std::string line;
    std::string year, month, airlineCode, airlineName, airportCode, city, state, airportName, arrivals, delayedArrivals, airlineCount, weatherCount, nasCount, securityCount, lateFlightCount, cancelled, diverted, delayTime, airlineDelay, weatherDelay, nasDelay, securityDelay, lateFlightDelay;

    //Get rid of first line
    getline(file, line);

    while (getline(file, line))
    {
        std::istringstream iss(line);

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
        if (arrivals == "" || delayedArrivals == "")
        {
            continue;
        }

        //If airport does not exist
        if (airports.find(airportCode) == airports.end())
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

	//Continue reference here
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project1::MyForm frm(&airports);//Non default constructor 
	Application::Run(% frm);
	// End reference here
}
