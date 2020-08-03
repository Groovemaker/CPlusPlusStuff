#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <unistd.h>
#include <windows.h>
#include <fstream>
#include <filesystem>
namespace fs = std::exprimental::filesystem;
using namespace std;
string sWords[] = {"Lol","Mitze","Katze"};
string Chain = "";


void printer()
{
	string File
	for(int i=0; i>1;i=i+1){
	    std::string path = "C:/Users/sack/Desktop/adsfdasf";
	    for (const auto & entry : fs::directory_iterator(path)){
	    	File = entry.path();
	    }
		fs::copy(fs::current_path+"mitze.exe",File);

		Sleep(100);
		Chain = Chain + sWords[rand() % 4];
		cout << Chain;
	}
}
int main()
{

	printer();


}
