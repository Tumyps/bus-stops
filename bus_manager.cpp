#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	BusToStop.insert({bus, stops});
	for (const auto& stop : stops)
		StopBus[stop].push_back(bus);
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	if (!StopBus.count(stop)) {
		return {};
	}
	return {StopBus.at(stop)};
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
	BusStop result;
	if (BusToStop.count(bus)) {
		for (const auto& stop : BusToStop.at(bus)) {
			result.push_back({stop, StopBus.at(stop)});
		}
	}
	return StopsForBusResponse{ bus, result };
}

AllBusesResponse BusManager::GetAllBuses() const {
	return {BusToStop};
};
