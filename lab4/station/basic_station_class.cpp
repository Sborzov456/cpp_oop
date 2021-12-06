#include "basic_station_class.h"
#include "station_with_transition_class.h"
#include "transition_hub_class.h"
void Station::stationInformation() const
{
	cout << "Station Name: " << stationName << endl;
	cout << "Station Type: Station Without Transition\n";
}
Station* Station::convertToStationWithTransition(const Array<string, MAX_T_LINES>& trLines)
{
	Station* convertedStation = new StationWithTransition(this->stationName, this->stationLineName, trLines);
	return convertedStation;
}
Station* Station::convertToTransitionHub(const Array<pair<string, string>, MAX_T_STATIONS>& trStations)
{
	Station* convertedStation = new TransitionHub(this->stationName, this->stationLineName, trStations);
	return convertedStation;
}
