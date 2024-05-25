#include "factory_directory.hpp"
#include <memory>

int main() {
	std::unique_ptr <Creator_FileCSV> file_csv1_factory = std::make_unique<Creator_FileCSV>();
	std::unique_ptr <Creator_FileTXT> file_txt1_factory = std::make_unique<Creator_FileTXT>();

	std::vector <Directory *> dir;
	dir.push_back(file_csv1_factory->factory_method());
	dir.push_back(file_txt1_factory->factory_method());

	for (auto &temp : dir) {
		temp->set_path(L"D:\\my_path"); //input directory path here
		temp->set_file(L"file_properties"); //input name of report file here
		temp->get_files_by_path();
		temp->output_report_to_file();
	}
	
	for (auto &temp : dir)
		delete temp;

	return 0;
}
