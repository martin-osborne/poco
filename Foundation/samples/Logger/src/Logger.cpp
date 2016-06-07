//
// Logger.cpp
//
// $Id: //poco/1.4/Foundation/samples/Logger/src/Logger.cpp#1 $
//
// This class demonstrates the Logger, PatternFormatter, FormattingChannel,
// ConsoleChannel and FileChannel classes.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/Logger.h"
#include "Poco/AutoPtr.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/Message.h"


using Poco::Logger;
using Poco::AutoPtr;
using Poco::PatternFormatter;
using Poco::FormattingChannel;
using Poco::ConsoleChannel;
using Poco::FileChannel;
using Poco::Message;


int main(int argc, char** argv)
{
	// set up two channel chains - one to the
	// console and the other one to a log file.
	AutoPtr<PatternFormatter> pPatternFormatter(new PatternFormatter("%s: %p: %t"));
	AutoPtr<FormattingChannel> pFCConsole(new FormattingChannel(pPatternFormatter));
	AutoPtr<ConsoleChannel> pConsoleChannel(new ConsoleChannel());
	pFCConsole->setChannel(pConsoleChannel);
	pFCConsole->open();
	
	AutoPtr<PatternFormatter> pPatternFormatter2(new PatternFormatter("%Y-%m-%d %H:%M:%S.%c %N[%P]:%s:%q:%t"));
	AutoPtr<FormattingChannel> pFCFile(new FormattingChannel(pPatternFormatter2));
	AutoPtr<FileChannel> pFileChannel(new FileChannel("sample.log"));
	pFCFile->setChannel(pFileChannel);
	pFCFile->open();

	// create two Logger objects - one for
	// each channel chain.
	Logger& consoleLogger = Logger::create("ConsoleLogger", pFCConsole, Message::PRIO_INFORMATION);
	Logger& fileLogger    = Logger::create("FileLogger", pFCFile, Message::PRIO_WARNING);
	
	// log some messages
	consoleLogger.error("An error message");
	fileLogger.error("An error message");
	
	consoleLogger.warning("A warning message");
	fileLogger.error("A warning message");
	
	consoleLogger.information("An information message");
	fileLogger.information("An information message");
	
	poco_information(consoleLogger, "Another informational message");
	poco_warning_f2(consoleLogger, "A warning message with arguments: %d, %d", 1, 2);
	
	Logger::get("ConsoleLogger").error("Another error message");
	Logger::shutdown();
	
	return 0;
}
