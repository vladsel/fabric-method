#include "directory.hpp"
#include "my_exception.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>

void Directory::get_files_by_path() {
	if (path.empty())
		return;
	if (!files_vec.empty())
		files_vec.clear();
	file_properties file_prop_temp;
	try {
		for (const auto &entry : std::filesystem::directory_iterator(path)) {
			std::wstring temp = entry.path();
			file_prop_temp.name = temp.substr(path.size() + 1);
			file_prop_temp.size = entry.file_size();
			file_prop_temp.link_count = entry.hard_link_count();
			files_vec.push_back(file_prop_temp);
		}
	}
	catch (...) {
		try {
			throw std::runtime_error("\nerror path\n");
		}
		catch (std::runtime_error &ex) {
			std::cout << ex.what();
			exit(1);
		}
	}
}

std::wstring Directory::get_path() const {
	return path;
}

void Directory::set_path(const std::wstring _path) {
	if (!_path.empty())
		path = _path;
}

void FileCSV::output_report_to_file() const {
	if (files_vec.empty() || file_csv.empty())
		return;
	std::wofstream file_out_csv;
	try {
		file_out_csv.open(path + L"\\" + file_csv, std::ios::out);
		if (!file_out_csv.is_open())
			throw my_exception(GetLastError());
	}
	catch (const my_exception &ex) {
		ex.get_error();
		std::cout << ex.what();
	}
	file_out_csv << "Directory;is:;" << path.substr(path.rfind(L"\\") + 1) + L";" << std::endl;
	for (auto &val : files_vec) {
		file_out_csv << "______;______;______;______;______;______;" << std::endl;
		file_out_csv << "file;name:;" << val.name + L";" << std::endl;
		file_out_csv << val.name + L";" << "size:;" << std::to_wstring(val.size) + L";" << std::endl;
		file_out_csv << val.name + L";" << "link count:;" << std::to_wstring(val.link_count) + L";" << std::endl;
	}
	file_out_csv.close();
}

std::wstring FileCSV::get_file() const {
	return file_csv;
}

void FileCSV::set_file(const std::wstring _file_csv) {
	if (!_file_csv.empty())
		file_csv = _file_csv + L".csv";
}

void FileTXT::output_report_to_file() const {
	if (files_vec.empty() || file_txt.empty())
		return;
	std::wofstream file_out_txt;
	try {
		file_out_txt.open(path + L"\\" + file_txt, std::ios::out);
		if (!file_out_txt.is_open())
			throw my_exception(GetLastError());
	}
	catch (const my_exception &ex) {
		ex.get_error();
		std::cout << ex.what();
	}
	file_out_txt << "\nDirectory is: " << path.substr(path.rfind(L"\\") + 1) << std::endl;
	for (auto &val : files_vec) {
		file_out_txt << "_______________________________________" << std::endl;
		file_out_txt << "file name: " << val.name << std::endl;
		file_out_txt << val.name << " size: " << val.size << std::endl;
		file_out_txt << val.name << " link count: " << val.link_count << std::endl;
	}
	file_out_txt.close();
}

std::wstring FileTXT::get_file() const {
	return file_txt;
}

void FileTXT::set_file(const std::wstring _file_txt) {
	if (!_file_txt.empty())
		file_txt = _file_txt + L".txt";
}
