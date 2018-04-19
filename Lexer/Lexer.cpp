// Lexer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MowStateMachine.h"

// https://github.com/bjornmp/Men-of-War-Blender-Importer


int main()
{
	int filePtr;
	errno_t err = _wsopen_s(&filePtr, L"material1.mtl", _O_RDONLY, _SH_DENYNO, _S_IREAD);
	if (err) {
		std::cout << "error " << EACCES << std::endl;
	}

	long fileSize = _lseek(filePtr, 0, SEEK_END);
	auto buf = std::make_unique<char[]>(fileSize);
	_lseek(filePtr, 0, SEEK_SET);
	int readed = _read(filePtr, buf.get(), fileSize);
	if (!readed) {
		err = errno;
		std::cout << err << std::endl;
	}

	////char sep[] = " \t\r\n";
	//char sep[] = "{}";
	//char* curToken = nullptr;
	//char* nextToken = nullptr;
	//curToken = strtok_s(buf.get(), sep, &nextToken);
	//while (curToken) {
	//	std::cout << curToken << std::endl;
	//	curToken = strtok_s(nullptr, sep, &nextToken);
	//}


	MowStateMachine parser;
	MemoryReader reader(buf.get(), fileSize);
	parser.Process(&reader);

	std::cout << parser << std::endl;

	_close(filePtr);
	_getch();

	return 0;
}

