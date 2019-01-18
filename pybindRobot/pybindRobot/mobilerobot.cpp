#include "mobilerobot.h"
#include "Aria.h"
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

ARIA::ARIA(std::vector<std::string> s_argv, std::string com){
	robot = new ArRobot;
	gripper = new ArGripper(robot);
	Aria::init();
	int argc;
	char **argv;
	argc = s_argv.size();
	argv = (char **)malloc(argc);
	for (int i = 0; i < argc; i++){
		argv[i] = new char[s_argv[i].size() + 1];
		std::char_traits<char>::copy(argv[i], s_argv[i].c_str(), s_argv[i].size() + 1);
	}

	char* arg1 = (char*)"-rp";
	char* arg2 = (char*)com.c_str();
	char* arg3 = (char*)"-rb";
	char* arg4 = (char*)"9600";
	char* _argv[] = { argv[0], arg1, arg2, arg3, arg4 };
	int _argc = 5;

	ArArgumentParser parser(&_argc, _argv);
	parser.loadDefaultArguments();
	robotConnector = new ArRobotConnector(&parser, robot);
	if (!robotConnector->connectRobot())
	{
		ArLog::log(ArLog::Terse, "gripperExample: Could not connect to the robot.");
		if (parser.checkHelpAndWarnUnparsed())
		{
			// -help not given
			Aria::logOptions();
			Aria::exit(1);
		}
	}
	robot->runAsync(true);

	robot->lock();
	robot->enableMotors();
	robot->comInt(ArCommands::ENABLE, 1);
	robot->unlock();
}

void ARIA::robot_action(int i){
	switch (i)
	{
	case 0:
		robot->setVel(double(speed));
		ArUtil::sleep(500);
		break;
	case 1:
		robot->setVel(-1 * double(speed));
		ArUtil::sleep(500);
		break;
	case 2:
		robot->setRotVel(double(rotation));
		ArUtil::sleep(500);
		break;
	case 3:
		robot->setRotVel(-1*double(rotation));
		ArUtil::sleep(500);
		break;
	case 4:
		robot->setVel(0);
		robot->setRotVel(0);
		break;
	default:
		robot->stop();
		break;
	}

}

void ARIA::gripper_action(int i){
	switch (i)
	{
	case 0:
		gripper->gripOpen();
		break;
	case 1:
		gripper->gripClose();
		break;
	case 2:
		gripper->liftUp();
		break;
	case 3:
		gripper->liftDown();
		break;
	case 4:
		gripper->gripperHalt();
		break;
	default:
		break;
	}
}

ARIA::~ARIA(){
	robot->stop();
	robot->disconnect();
}