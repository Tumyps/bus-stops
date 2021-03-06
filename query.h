#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

using BusStop = vector<pair<string, vector<string>>>;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q);