#include<iostream>
#include<string>
#include "SGP4.h"
#include <vector>

#include<thread>

//пример реализации
int main() {
	
	std::vector<NORAD_DATA> Satellites;
	const std::string file = "TLE.txt";
	Station st;
	st.geo.Lat = 56.14717;
	st.geo.Lon = 37.76275;

	st.geo.Alt = 100; 
	st.lim.minAzm = 120.0;
	st.lim.maxAzm = 200.0;
	st.lim.minElv = 10.0;
	st.lim.maxElv = 80.0;
	st.lim.timeMinObserveSec = 50;
	SetelliteSelect tmp(file, st);
	tmp.dataPrepare();
	for (int i = 0; i < 50; i++) {
		tmp.GetSatArray();
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
	return 0;
}