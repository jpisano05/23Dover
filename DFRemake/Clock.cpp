#pragma once

//includes
#include "Clock.h"
#include <stdio.h>
#include <Windows.h>

using namespace df;

Clock::Clock() {
	//Get the current time in ms
	SYSTEMTIME current_st;
	GetSystemTime(&current_st);

	long int to_msc = (current_st.wDay * 24 * 60 * 60 * 1000000) + (current_st.wHour * 60 * 60 * 1000000) + (current_st.wMinute * 60 * 1000000) + (current_st.wSecond * 1000000) + (current_st.wMilliseconds * 1000);

	m_previous_time = to_msc;
}

//Produces a human-readable time string
char* Clock::getTimeString() {
	//to be returned
	static char time_str[30];

	//Get the current time
	time_t current_time;
	time(&current_time);

	//Allocate a section of memory to store the formatted time
	struct tm* p_time = new tm;
	localtime_s(p_time , &current_time);

	//Format the time into a string
	sprintf_s(time_str, "%02d:%02d:%02d", p_time->tm_hour, p_time->tm_min, p_time->tm_sec);

	return time_str;
}

//Return time elapsed since delta() was last called
long int Clock::delta() {
	//Get the current time in ms
	SYSTEMTIME current_st;
	GetSystemTime(&current_st);

	long int to_msc = (current_st.wDay * 24 * 60 * 60 * 1000000) + (current_st.wHour * 60 * 60 * 1000000) + (current_st.wMinute * 60 * 1000000) + (current_st.wSecond * 1000000) + (current_st.wMilliseconds * 1000);

	//Create a temporary way to store m_previous_time
	long int temp = m_previous_time;

	//Reset m_previous_time to the current_time
	m_previous_time = to_msc;

	//Return the time difference
	return to_msc - temp;
}

//Return time elapsed since last delta() was called, does not reset m_previous_time
long int Clock::split() const {
	//Get the current time in ms
	SYSTEMTIME current_st;
	GetSystemTime(&current_st);

	long int to_msc = (current_st.wDay * 24 * 60 * 60 * 1000000) + (current_st.wHour * 60 * 60 * 1000000) + (current_st.wMinute * 60 * 1000000) + (current_st.wSecond * 1000000) + (current_st.wMilliseconds * 1000);


	//Return the time difference
	return to_msc - m_previous_time;
}