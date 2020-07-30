#pragma once
#include <chrono>
#include <iostream>

class PerformanceTime
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
public:
	PerformanceTime() { std::chrono::high_resolution_clock::now(); }
	~PerformanceTime() { Stop(); }

	void Stop()
	{
		auto endTime = std::chrono::high_resolution_clock::now();	
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();
		auto ms = end - start;
		unsigned long long us = ms * 0.001;
		std::cout << "[PerformanceTime Tracker: " << us << " microseconds | " << ms << " miliseconds]\n";
	}
};
