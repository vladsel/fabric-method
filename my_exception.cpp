#include "my_exception.hpp"

void my_exception::get_error() const {
	std::cerr << "system error: " << error_num << std::endl;
}
