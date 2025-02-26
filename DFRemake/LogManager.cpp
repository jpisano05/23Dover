#pragma once

//Includes
#include "LogManager.h"
#include <stdio.h>
#include <stdarg.h>
#include "Clock.h"


using namespace df;

//Constructor
LogManager::LogManager() {
	m_do_flush = true;
}

//Destructor
LogManager::~LogManager() {
	if (m_p_f == NULL) {
		shutDown();
	}
}

//Opens log file for editing and sets m_is_started to true
int LogManager::startUp() {
	fopen_s(&m_p_f, LOGFILE_NAME.c_str(), "w");
	//Check if there were errors opening
	if (m_p_f == NULL) {
		return -1;
	}
	return 0;
}

//Closes log file and sets m_is_started to false
void LogManager::shutDown() {
	fclose(m_p_f);
}

//Write log to file m_p_f
int LogManager::writeLog(const char *fmt, ...) const {
	//If a file isn't opened to write to, then error
	if (m_p_f == NULL) {
		return -1;
	}

	Clock* logClock = new Clock();
	//Get the current time the log was written at
	char* tn = logClock->getTimeString();

	//Print time stamp before log
	fprintf(m_p_f, "[%s]: ", tn);


	va_list args;
	va_start(args, fmt);

	//Write the arguments to file
	vfprintf(m_p_f, fmt, args);
	va_end(args);

	fprintf(m_p_f, "\n");

	//If flush is enabled, flush input
	if (m_do_flush) {
		fflush(m_p_f);
	}

	return 0;
}

//Sets whether text should be flushed
//Default: True
void LogManager::setFlush(bool do_flush) {
	m_do_flush = do_flush;
}