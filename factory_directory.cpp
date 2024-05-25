#include "factory_directory.hpp"

Directory *Creator_FileCSV::factory_method() const {
	return new FileCSV;
}

Directory *Creator_FileTXT::factory_method() const {
	return new FileTXT;
}
