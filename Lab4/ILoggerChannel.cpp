#include "ILoggerChannel.h"
#include <iostream>
#include <fstream>
#include <string>

ILoggerChannel::ILoggerChannel(int max_sev, int min_sev)
{
	if (max_sev == 0) 
	{
		max_severity_ = 9;
	}
	else
	{
		max_severity_ = max_sev;
	}
	min_severity_ = min_sev;
	console_or_file = 'n';
	log = "";
}

ILoggerChannel::ILoggerChannel()
{
	max_severity_ = 9;
	min_severity_ = 0;
	console_or_file = 'n';
	log = "";
}

std::string ILoggerChannel::maximumSeverity()
{
	switch (max_severity_)
	{
		case 0:
			return "none";
		case 1:
			return "trace";
		case 2:
			return "info";
		case 3:
			return "warn";
		case 4:
			return "error";
		default:
			return "none";
	}
		
}

std::string ILoggerChannel::minimumSeverity()
{
	switch (min_severity_)
	{
	case 0:
		return "none";
	case 1:
		return "trace";
	case 2:
		return "info";
	case 3:
		return "warn";
	case 4:
		return "error";
	default:
		return "something is wrong";
	}

}

ILoggerChannelConsole::ILoggerChannelConsole(int max_sev, int min_sev)
{
	if (max_sev == 0)
	{
		max_severity_ = 9;
	}
	else
	{
		max_severity_ = max_sev;
	}
	min_severity_ = min_sev;
	console_or_file = 'c';
	log = "";
}

ILoggerChannelFile::ILoggerChannelFile(int max_sev, int min_sev, std::string new_filename)
{
	if (max_sev == 0)
	{
		max_severity_ = 9;
	}
	else
	{
		max_severity_ = max_sev;
	}
	min_severity_ = min_sev;
	console_or_file = 'f';
	filename = new_filename;
	log = "";
}

std::string ILoggerChannelConsole::write()
{
	std::ofstream log_file;
	bool logging_not_finished = true;
	int log_severity;
	std::string input;
	std::string the_log;
	while (logging_not_finished)
	{
		std::cout << "Choose log severity:" << std::endl;
		std::cout << "0. None" << std::endl;
		std::cout << "1. Trace" << std::endl;
		std::cout << "2. Info" << std::endl;
		std::cout << "3. Warn" << std::endl;
		std::cout << "4. Error" << std::endl;
		std::cin >> input;
		if (input != "0" && input != "1" && input != "2" && input != "3" && input != "4")
		{
			std::cout << "Wrong input" << std::endl;
			continue;
		}
		else if (stoi(input) > max_severity_)
		{
			std::cout << "Severity too high!" << std::endl;
			continue;
		}
		else if (stoi(input) < min_severity_)
		{
			std::cout << "Severity too low!" << std::endl;
			continue;
		}
		else
		{
			log_severity = stoi(input);
			std::cout << "Please write your message:" << std::endl;
			std::cin >> input;
			switch (log_severity)
			{
				case 0:
					the_log = "None " + input;
					break;
				case 1:
					the_log = "Trace " + input;
					break;
				case 2:
					the_log = "Info " + input;
					break;
				case 3:
					the_log = "Warn " + input;
					break;
				case 4:
					the_log = "Error " + input;
					break;
			}
			logging_not_finished = false;
		}
	}
	log = the_log;
	return the_log;
}

std::string ILoggerChannel::write()
{
	return "";
}

std::string ILoggerChannelFile::write()
{
	std::string log_severity;
	std::string the_log = "";
	int log_severity_value = 11;
	char whole_log[1000];
	std::ifstream readfile;
	readfile.open(filename);
	readfile >> log_severity;
	if (log_severity == "None")
	{
		log_severity_value = 0;
	}
	else if (log_severity == "Trace")
	{
		log_severity_value = 1;
	}
	else if (log_severity == "Info")
	{
		log_severity_value = 2;
	}
	else if (log_severity == "Warn")
	{
		log_severity_value = 3;
	}
	else if (log_severity == "Error")
	{
		log_severity_value = 4;
	}
	readfile.close();
	readfile.open(filename);
	if (log_severity_value < min_severity_ || log_severity_value > max_severity_)
	{

	}
	else
	{
		readfile.getline(whole_log, 1000);
		for (auto c : whole_log)
		{
			if (c >= ' ')
			{
				the_log += c;
			}
			
		}
	}
	readfile.close();
	log = the_log;
	return the_log;
}

