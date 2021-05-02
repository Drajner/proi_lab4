#include "IMessage.h"

IMessage::IMessage(int sev, std::string message)
{
	text = message;
	severity = sev;
}

IMessage::IMessage()
{
	severity = 0;
	text = "";
}

void IMessage::set_severity(int new_severity)
{
	severity = new_severity;
}
void IMessage::set_text(std::string new_text)
{
	text = new_text;
}