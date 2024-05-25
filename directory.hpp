#pragma once

#include <vector>
#include <string>

struct file_properties {
	std::wstring name;
	unsigned __int64 size = 0;
	uintmax_t link_count = 0;
};

class Directory {
public:
	Directory() : path(L"empty") {}
	Directory(std::wstring _path) : path(_path) {}
	void get_files_by_path();
	virtual ~Directory() = default;
	virtual void output_report_to_file() const = 0;
	virtual std::wstring get_file() const = 0;
	virtual void set_file(const std::wstring _file_csv) = 0;
	std::wstring get_path() const;
	void set_path(const std::wstring _path);
protected:
	std::vector <file_properties> files_vec;
	std::wstring path;
};

class FileCSV : public Directory {
public:
	FileCSV() : file_csv(L"empty") {}
	FileCSV(std::wstring _path, std::wstring file_name) : Directory(_path), file_csv(file_name + L".csv") {}
	void output_report_to_file() const override;
	std::wstring get_file() const override;
	void set_file(const std::wstring _file_csv) override;
private:
	std::wstring file_csv;
};

class FileTXT : public Directory {
public:
	FileTXT() : file_txt(L"empty") {}
	FileTXT(std::wstring _path, std::wstring file_name) : Directory(_path), file_txt(file_name + L".txt") {}
	void output_report_to_file() const override;
	std::wstring get_file() const override;
	void set_file(const std::wstring _file_txt) override;
private:
	std::wstring file_txt;
};
