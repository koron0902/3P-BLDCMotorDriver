/*
 * ControllerBase.cpp
 *
 *  Created on: 2016/12/11
 *      Author: Keita
 */

#include <ControllerBase.hpp>
#include <Trapezium.hpp>
#include <PIDControl.hpp>
#include <Timer.hpp>
#include <motor.hpp>
#include <Port.hpp>

namespace Middle {
	namespace Controller {
		ControlMode_e mMode;

		ControllerBase::ControllerBase(): mFreq(FREQ_DEFAULT) {

		}

		ControllerBase::~ControllerBase() {

		}

		std::string SwitchControlMode(ControlMode_e _mode){
			if(mMode == _mode)
				return "Already running as requested mode";

			std::string retStr = "";
			switch(_mode){
				case ControlMode_e::ModeTest:{
					Device::Port::Set(Device::Port::PWMEN, true);
					Middle::Motor::ModeAs(Middle::Motor::Type::DCMotor);
					Device::Timer::SetAction(ControllerBase::mControllerTaskPriority, 1, nullptr);
					retStr = "Succeeded in switching test mode";
					break;
				}
				case ControlMode_e::ModeTrapezium:{
					Trapezium* trap = new Trapezium();
					Device::Port::Set(Device::Port::PWMEN, true);
					Middle::Motor::ModeAs(Middle::Motor::Type::DCMotor);
					Controller::Trapezium::Reset();
					Device::Timer::SetAction(ControllerBase::mControllerTaskPriority, trap->GetFreq(), std::move(*trap));
					retStr = "Succeeded in switching trap. control";
					break;
				}case ControlMode_e::ModePID:{
					PID* pid = new PID();
					Device::Port::Set(Device::Port::PWMEN, true);
					Middle::Motor::ModeAs(Middle::Motor::Type::DCMotor);
					Controller::PID::Reset();
					Device::Timer::SetAction(ControllerBase::mControllerTaskPriority, pid->GetFreq(), std::move(*pid));
					retStr = "Succeeded in switching pid control";
					break;
				}default :{
					return "No such as control mode";
				}
			}
			mMode = _mode;
			return retStr;
		}
	
	} /* namespace Controller */
} /* namespace Middle */
