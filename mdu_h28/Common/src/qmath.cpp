/*
 * qmath.cpp
 *
 *  Created on: 2016/11/11
 *      Author: hamus
 */

#include <qmath.hpp>

namespace common {

constexpr int fact(int n) {
	// ループには再帰を使用する
	return n == 0 ? 1 : n * fact(n - 1);
}

constexpr fix32 pow(fix32 x,uint n){
	fix32 temp=fix32::One;
	for (uint i=0;i<n;i++){
		temp*=x;
	}
	return x;
}






fix32 exp(fix32 x){
	fix32 y;
	return 0;//stub
}

fix32 sin(fix32 x) {
	return 0;//stub
}

fix32 cos(fix32 x) {
	return 0;//stub
}

} /* namespace Device */
