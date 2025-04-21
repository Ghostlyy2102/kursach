#pragma once

using namespace System;

ref class Taxi {
public:
	String^ number;
	String^ brand;
	String^ driverName;
	bool isAvailable;

	Taxi^ prev;
	Taxi^ next;

	Taxi(String^ num, String^ br, String^ dr, bool avail) : number(num), brand(br), driverName(dr), isAvailable(avail), prev(nullptr), next(nullptr) {
	}
};