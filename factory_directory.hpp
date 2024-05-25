#pragma once

#include "directory.hpp"

class Creator {
public:
	virtual ~Creator() = default;
	virtual Directory *factory_method() const = 0;
};

class Creator_FileCSV : public Creator {
public:
	Directory *factory_method() const;
};

class Creator_FileTXT : public Creator {
public:
	Directory *factory_method() const;
};