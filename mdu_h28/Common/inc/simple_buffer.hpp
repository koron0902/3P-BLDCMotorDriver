#pragma once
#include <stddef.h>
#include <stdint.h>
#include <string.h>

namespace common{

template <size_t _size>struct SimpleBuffer{
public:
	static constexpr size_t size=_size;

private:
	uint8_t buf[_size];
	size_t depth;
public:
	SimpleBuffer(){
		depth=0;
	}
	SimpleBuffer(const SimpleBuffer&)=delete;

	void Write(uint8_t c){
		buf[depth++]=c;
	}

	void Write(const uint8_t* inst,size_t sz){
		memcpy(&buf[depth],inst,sz);
		depth+=sz;
	}

	const uint8_t* GetData(){
		return buf;
	}

	const size_t GetDepth(){
		return depth;
	}

	void Reset(){
		depth=0;
	}
};

}
