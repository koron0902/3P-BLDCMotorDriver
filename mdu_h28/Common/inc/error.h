/*
 * error.h
 *
 *  Created on: 2016/12/10
 *      Author: hamus
 */

#ifndef COMMON_ERROR_H_
#define COMMON_ERROR_H_

namespace common {

struct error {

enum:int{
	OK=0,
	Unknown=-1,
	PtrErr=-100,
	FoundOut,
	Empty,
	AccessErr,

	MissMatch=-10000
};
const char* GetMessage(int);
};

} /* namespace common */

#endif /* COMMON_ERROR_H_ */