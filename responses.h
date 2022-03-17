#pragma once

#include "query.h"

struct BusesForStopResponse {
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  string bus;
  BusStop StopBus;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  map<string, vector<string>> BusToStop;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
