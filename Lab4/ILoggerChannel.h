#pragma once
#include "IMessage.h"
#include <string>
class ILoggerChannel
{
protected:
	int max_severity_{};
	int min_severity_{};
	std::string log;
public:
	ILoggerChannel(int max_sev, int min_sev);
	ILoggerChannel();
	char console_or_file;
	virtual std::string minimumSeverity();
	virtual std::string maximumSeverity();
	virtual std::string write();
};

class ILoggerChannelConsole : public ILoggerChannel
{
public:
	ILoggerChannelConsole(int max_sev, int min_sev);
	std::string write() override;
};

class ILoggerChannelFile : public ILoggerChannel
{
private:
	std::string filename;
public:
	ILoggerChannelFile(int max_sev, int min_sev, std::string new_filename);
	std::string write() override;
};



