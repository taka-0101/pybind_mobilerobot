import pybindRobot
from pybindRobot import ARIA

import sys
args_ = sys.argv
args = []
for i in args_:
    args.append(str(i))


print("a")

robot = ARIA(args,str("COM7"))


print("a")
while True:
    print("a")
    robot.speedChange(float(10))
    robot.robot_action(int(0))