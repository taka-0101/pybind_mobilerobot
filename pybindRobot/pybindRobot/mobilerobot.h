#include <vector>
#include <string>

class ArRobot;
class ArGripper;
class ArRobotConnector;

class ARIA{
private:
	ArRobot *robot;
	ArGripper *gripper;
	ArRobotConnector* robotConnector;
	float speed = 100;
	float rotation = 60;


public:
	ARIA(std::vector<std::string> s_argv, std::string com);
	~ARIA();
	void robot_action(int i);
	void gripper_action(int i);
	void speedChange(float par){ speed = par; }
	void rotationChange(float par){ rotation = par; }

};