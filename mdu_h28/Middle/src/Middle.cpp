/*
 * Middle.cpp
 *
 *  Created on: 2016/11/12
 *      Author: hamus
 */

#include <HallSensor.hpp>
#include <motor.hpp>
#include "ff.hpp"
#include "Middle.hpp"
#include "ControllerBase.hpp"
#include <cstring>
namespace Middle {

void Init(){
	HallSensor::Init();
	Motor::Init();
	Controller::SwitchControlMode(Controller::ControlMode_e::ModePID);
}


}
