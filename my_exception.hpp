#pragma once

#include <iostream> 
#include <windows.h>

class my_exception : public std::exception {
public:
	my_exception(DWORD _error_num) : error_num(_error_num) {}
	~my_exception() = default;
	void get_error() const;
private:
	DWORD error_num;
};