#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.buses.empty()) {
    os << "No stop" << endl;
  } else {
    for (const auto& bus : r.buses) {
      os << bus << " ";
    }
    os << endl;
  }
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if (r.StopBus.empty())
    os << "No bus" << endl;
  else {
    for (const auto& item : r.StopBus) {
      os << "Stop " << item.first << ":";
      if (item.second.size() == 1)
        os << " no interchange" << endl;
      else
        for (const auto& bus : item.second)
          if (bus != r.bus)
            os << " " << bus;
      os << endl;
    }
  }
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.BusToStop.empty())
    os << "No buses" << endl;
  else {
    for (const auto& bus_and_stops : r.BusToStop) {
      os << "Bus " << bus_and_stops.first << ":";
      for (const auto& stop : bus_and_stops.second)
        os << " " << stop;
      os << endl;
    }
  }
  return os;
}
