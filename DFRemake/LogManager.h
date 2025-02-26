#pragma once

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__
#define LM df::LogManager::getInstance()

//includes
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "Manager.h"

//Namespace def
namespace df {

	const std::string LOGFILE_NAME = "dragonfly.log";

	//Start of class definition
	class LogManager : public Manager {
	private:
		//Constructor
		LogManager();
		//Prevent copies
		LogManager(LogManager const&);
		//Prevent assignment
		void operator=(LogManager const&);
		//Whether text should be flushed on write
		bool m_do_flush;
		//Pointer to the file
		FILE *m_p_f;

	public:
		//Destructor
		~LogManager();

		//Get the only instance of the LogManager
		static LogManager& getInstance() {
			static LogManager instance;
			return instance;
		};

		//Start the LogManager
		int startUp();

		//Shutdown the LogManager
		void shutDown();

		//Set the flush state of the logfile, default flushes
		void setFlush(bool do_flush = true);

		//Write to the logfile
		int writeLog(const char *fmt, ...) const;
	};

}

#endif __LOG_MANAGER_H__