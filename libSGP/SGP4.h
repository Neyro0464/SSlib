#pragma once
#include<string>
#include<vector>
#include "Sgpsdp.h"


struct CoordDecart {
	double x;
	double y;
	double z;
};
struct CoordTopocentric {
	double azm;
	double elv;
};
struct CoordGeodetic {
	double Lat;
	double Lon;
	double Alt;
};
struct StationVision {
	double minAzm;
	double maxAzm;
	double minElv;
	double maxElv;
	double timeMinObserveSec;
};
struct Station {
	CoordDecart dec;
	CoordGeodetic geo;
	StationVision lim;
};
struct COORDS {
	CoordTopocentric topo;
	CoordGeodetic geo;
};
struct NORAD_DATA {
	std::string name;
	unsigned int noradNumber;
	std::string onTime;
	COORDS coords;
	double time;
	bool dirPositive;
};

class SetelliteSelect {
private:
	std::vector<CSGP4_SDP4> Satellites;
	Station station;
	std::string filename;

public:
	SetelliteSelect();
	SetelliteSelect(const std::string& filename, Station& param);

	void SetTLEFile(); 
	bool SetStationPos();
	bool SetFilter();

	//MAIN functions
	void dataPrepare();
	std::vector<NORAD_DATA> GetSatArray(); 
	//MAIN functions

	void showSat(std::vector<NORAD_DATA>& result);
	~SetelliteSelect(){};
};
