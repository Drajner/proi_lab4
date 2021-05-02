#pragma once
#include <string>

enum Severity 
{
	None,
	Trace,
	Info,
	Warn,
	Error
};
class IMessage
{
	std::string text;
	int severity;
	IMessage(int sev, std::string message);
	IMessage();
public:
	void set_severity(int new_severity);
	void set_text(std::string new_text);
};

