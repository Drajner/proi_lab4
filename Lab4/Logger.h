#pragma once
#include "ILoggerChannel.h"
#include "List.h"
#include "IMessage.h"
#include <string>
class ILogger
{
private:
	List<ILoggerChannel*> channels_;
public:
	ILogger(ILoggerChannel* first_channel);
	void add_channel(ILoggerChannel* new_channel);
	void remove_channel();
	List<ILoggerChannel*> channels();
	std::string log(int channel_number);
};

