

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "mobilerobot.h"


using namespace::std;

namespace py = pybind11;

PYBIND11_MODULE(pybindRobot,m) {
	m.doc() = "I'm always beneath you, but nothing is beneath me!";

	py::class_<ARIA>(m, "ARIA")
		.def(py::init<const std::vector<std::string>, const std::string>())
		.def("robot_action", &ARIA::robot_action)
		.def("gripper_action", &ARIA::gripper_action)
		.def("speedChange", &ARIA::speedChange)
		.def("rotationChange", &ARIA::rotationChange);

}