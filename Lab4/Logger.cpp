#include "Logger.h"
#include <string>
ILogger::ILogger(ILoggerChannel* first_channel)
{
	channels_.add_element(first_channel);
}
void ILogger::add_channel(ILoggerChannel* new_channel)
{
	channels_.add_element(new_channel);
}
void ILogger::remove_channel()
{
	channels_.remove_element();
}
std::string ILogger::log(int channel_number)
{
	std::string the_log;
	int i=0;
	for (auto channel : channels_)
	{
		if (i == channel_number)
		{
			the_log = channel->write();
			break;
		}
		i++;
	}
	return the_log;
}

List<ILoggerChannel*> ILogger::channels()
{
	return channels_;
}