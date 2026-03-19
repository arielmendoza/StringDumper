// StringDumper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>

std::vector<unsigned char>  ReadBinaryFileContent(const std::wstring& filePath) {
	std::ifstream binaryFile(filePath.c_str(), std::ios::binary);
	if (binaryFile.is_open()) {
		std::vector<unsigned char> FileContent(std::istreambuf_iterator<char>(binaryFile), {});
		binaryFile.close();
		return FileContent;
	}

	printf("Error when open file: %S.", filePath.c_str());
	std::vector<unsigned char> empty;
	return empty;
}
bool HasVisibleChars(const std::wstring& str) {
	for (auto ch : str) {
		if (ch != L' ' && ch != L'\t')
			return true;
	}
	return false;
}
bool HasVisibleChars(const std::string& str) {
	for (auto ch : str) {
		if (ch != ' ' && ch != '\t')
			return true;
	}
	return false;
}
int PrintStrings(const std::vector<unsigned char>& fileBytes) {
	std::string buffer;
	int offset = 0;
	int matchCount = 0;
	printf("--- ASCII Strings (min length: 4) ---\nOffset\t\tString\n-------------\t-----------------------------\n");
	for (int i = 0; i < fileBytes.size(); i++) {
		if ((fileBytes[i] > 31) && (fileBytes[i] < 127)) {
			if (buffer.size() == 0)
				offset = i;
			buffer.push_back(fileBytes[i]);
		}
		else {
			if (buffer.size() > 3) {
				if (HasVisibleChars(buffer)) {
					printf("0x%08x\t%s\n", offset, buffer.c_str());
					matchCount++;
				}
			}
			buffer.clear();
		}
	}
	return matchCount;
}
int PrintUnicodeStrings(const std::vector<unsigned char>& fileBytes) {
	std::wstring buffer;
	int offset = 0;
	int matchCount = 0;
	printf("\n\n--- Unicode Strings (min length: 4) ---\nOffset\t\tString\n-------------\t-----------------------------\n");
	for (int i = 0; i < fileBytes.size(); i++) {
		if (i + 1 >= fileBytes.size()) {
			if (buffer.size() > 3) {
				if (HasVisibleChars(buffer)) {
					printf("0x%08x\t%S\n", offset, buffer.c_str());
					matchCount++;
				}
			}
			break;
		}
		if ((fileBytes[i] > 31) && (fileBytes[i] < 127) && (fileBytes[i + 1] == 0)) {
			if (buffer.size() == 0)
				offset = i;
			buffer.push_back(fileBytes[i]);
			i++;
		}
		else {
			if (buffer.size() > 3) {
				if (HasVisibleChars(buffer)) {
					printf("0x%08x\t%S\n", offset, buffer.c_str());
					matchCount++;
				}
			}
			buffer.clear();
		}
	}
	return matchCount;
}
void PrintBanner() {
	std::cout << R"(
   ____       __    _ __  ____             __
  / __ \_____/ /_  (_) / / __ \___  ____  / /___  __  __
 / / / / ___/ __ \/ / __/ / / / _ \/ __ \/ / __ \/ / / /
/ /_/ / /  / /_/ / / /_/ /_/ /  __/ /_/ / / /_/ / /_/ /
\____/_/  /_.___/_/\__/_____/\___/ .___/_/\____/\__, /
                                /_/            /____/
========================================================
            StringDumper Utility v1.0
           https://www.orbitdeploy.com
========================================================
)" << '\n';
}

int wmain(int argc, wchar_t* argv[])
{
	PrintBanner();
	if (argc < 2) {
		printf("Usage: StringDumper.exe <file_path>\n");
		printf("Example: StringDumper.exe C:\\Windows\\System32\\notepad.exe\n");
		return 1;
	}
	printf("File: %S\n", argv[1]);
	printf("Size: %llu bytes\n\n", std::filesystem::file_size(argv[1]));
	std::vector<unsigned char>fileContent = ReadBinaryFileContent(argv[1]);
	if (fileContent.empty())
		return 2;
	int asciiCount = PrintStrings(fileContent);
	int unicodeCount = PrintUnicodeStrings(fileContent);
	printf("\n-------------------------------------\nASCII: %d strings found\nUnicode: %d strings found\n", asciiCount, unicodeCount);
	return 0;
}

