#include "MainForm.h"
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include "MemUtil.h"
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm> 
#include <string> 
#include <windows.h>

using namespace std;
using namespace FearPE;

struct PoePacket
{
	DWORD Socket; //0x00

	DWORD unk[34];

	DWORD Addr1; //0x8C
	DWORD Addr2; //0x90

	DWORD unk_2[7];

	BYTE unk_3 = 1;

	BYTE one = 1; //0xA9

	SHORT unk_4 = 0;

	//DWORD unk_5[2];

	//DWORD zero = 0; //0xB4
	DWORD len; //0xB8

	DWORD unk_6[4];

	unsigned char* dataPtr;
	unsigned char Data[4096]; //0xC8
};


typedef void(__stdcall* sendPacket)(int one);

bool checkHeader = true;

DWORD GameSend = FindPattern("PathOfExile.exe", "\x55\x8D\x6C\x24\xC8\x83\xEC\x38\x6A\xFF\x68\xE3\x9A\xB4\x01\x64\xA1\x00\x00\x00\x00\x50\x64\x89\x25\x00\x00\x00\x00\x81\xEC\xB4\x01\x00\x00\x53\x56\x8B\xF1\xC7\x45\x34\x00\x00\x00\x00", "xxxxxxxxxxx????xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
DWORD hookAddr = FindPattern("PathOfExile.exe", "\x55\x8B\xEC\x83\xE4\xF8\x83\xEC\x10\x56\x8B\xF1\x57\x8B\x7D\x0C", "xxxxxxxxxxxxxxxx");
DWORD nextPacketAddr = FindPattern("PathOfExile.exe", "\x85\xC9\x0F\x95\xC0\x84\xC0\x74\x13\x85\xFF\x74\x0F\x8B\x86\xC8\x00\x00\x00", "xxxxxxxxxxxxxxxxxx");

DWORD contAddr;
DWORD contAddr_2;
DWORD contAddr_3;

DWORD stackPtr;
DWORD retAddr;

unsigned int* base;
unsigned int* esiPtr;
unsigned int* ecx;
DWORD sawk;

USHORT modHeaders[10];

string formattedPacket;
string rawPacket;


ref struct Main {
	static MainForm^ gui;
};

void print(string str) {
	Main::gui->Log(gcnew String(str.c_str()));
}

void print(BYTE b) {
	stringstream ss;
	ss << b;
	string str = ss.str();
	print(str);
}

void print(USHORT s) {
	stringstream ss;
	ss << s;
	string str = ss.str();
	print(str);
}

void print(DWORD i) {
	stringstream ss;
	ss << i;
	string str = ss.str();
	print(str);
}

void printPacket(void) {
	formattedPacket = formattedPacket.substr(0, formattedPacket.length() - 1);
	rawPacket = rawPacket.substr(0, rawPacket.length() - 1);
	Main::gui->printPacket(gcnew String(formattedPacket.c_str()), gcnew String(rawPacket.c_str()));
	formattedPacket = "";
	rawPacket = "";
}

bool PoeSend(unsigned int pLen, unsigned char* pData)
{
	sendPacket Send = (sendPacket)(GameSend);
	PoePacket packet;

	//unsigned int static1 = 0x017A7424;
	//unsigned int static2 = 0x01610AA8;

	for (DWORD i = 0; i < 34; ++i)
	{
		packet.unk[i] = 0;
	}
	for (DWORD j = 0; j < 7; ++j)
	{
		packet.unk_2[j] = 0;
	}
	for (DWORD k = 0; k < 4; ++k)
	{
		packet.unk_6[k] = 0;
	}

	packet.unk_4 = 0;
	packet.Socket = sawk;
	packet.Addr1 = *ecx; //
	packet.Addr2 = *esiPtr;
	packet.len = pLen;

	for (unsigned int i = 0; i < pLen; i++)
	{
		packet.Data[i] = pData[i];
	}

	packet.dataPtr = packet.Data;
	unsigned int pPointer = (unsigned int)&packet;

	__asm
	{
		MOV ECX, pPointer
	}


	Send(0);
	return true;
}


void modifyPacket(BYTE* buffer, BYTE index, BYTE value) {
	buffer[index] = value;
}

bool arrContains(USHORT arr[], USHORT element) {
	for (DWORD i = 0; i < sizeof(arr) / 2; i++) {
		if (arr[i] == element) {
			return true;
		}
	}
	return false;
}

void appendValue(DWORD esp) {
	DWORD *newEsp = (DWORD*) esp + 1; //after this newEsp is pointing to the value pointer
	DWORD bufAddr = *newEsp; //now the value pointer is formatted properly and placed into an integer 
	BYTE* buf = (BYTE*) bufAddr; //now we cast that integer (address) to a char pointer so we can read the buffer

	DWORD *len = (DWORD*) esp + 2;

	if (checkHeader) {
		USHORT header = 0;
		header += 256 * (USHORT) buf[0];
		header += (USHORT) buf[1];

		if (arrContains(modHeaders, header)) {
			// you want a map of maps
			/*
			 * a map contains key, value pairs
			 * your first map is a map with key=header, value=map#2
			 * map#2 is a map with key=byteIndexToChange, value=byteToChangeItTo
			 * so now, every element in your first map will look like this:
			 * [HEADER --> [BYTE INDEX --> [BYTE TO CHANGE IT TO]]]
			*/
		}
		//print((USHORT) buf[0]);
		//print((USHORT) buf[1]);
		//print((USHORT) buf[2]);
		//print((USHORT) buf[3]);
		//print((USHORT) buf[4]);
		//print((USHORT) buf[5]);
		checkHeader = false;
	}
	string packetData = "";
	

	for (DWORD i = 0; i < *len; i++) { //*len will be the actual integer len 
		if (buf[i] < 16) {
			packetData += "0";
		}
		ostringstream stream;
		stream << hex << (DWORD) buf[i];
		string str = stream.str();
		transform(str.begin(), str.end(), str.begin(), ::toupper);
		packetData += str;
	}
	formattedPacket += "[";
	formattedPacket += packetData;
	formattedPacket += "] ";
	for (int i = 0; i < packetData.length(); i += 2) {
		rawPacket += packetData.substr(i, 2);
		rawPacket += " ";
	}
}

void copyPacketObj(unsigned int* packet)
{
	unsigned int* length = packet + 45;
	ecx = packet + 35;
	esiPtr = packet + 36;
	sawk = *packet;
	DWORD* dataAddr = (DWORD*)(packet + 50);
	unsigned char* data = (unsigned char*)dataAddr;
}


void __declspec(naked) logHook(void) {
	__asm {
		mov stackPtr, esp
			pushad
	}
	appendValue(stackPtr);
	__asm {
		popad
			push ebp
			mov ebp, esp
			push - 1
			jmp[contAddr]
	}
}

void __declspec(naked) grabPacketObj(void)
{
	__asm
	{
		PUSHAD
			MOV base, ECX
	}
	copyPacketObj(base);
	__asm
	{
		POPAD
			PUSH EBP
			LEA EBP, [ESP - 0x38]
			jmp[contAddr_3]
	}
}

void __declspec(naked) newPacket(void) {
	__asm {
		pushad
	}
	printPacket();
	checkHeader = true;
	__asm {
		popad
			test ecx, ecx
			setne al
			jmp[contAddr_2]
	}
}

void initializeHook() {
	contAddr = hookAddr + 5;
	contAddr_2 = nextPacketAddr + 5;
	contAddr_3 = GameSend + 5;

	PlaceJMP((BYTE*) hookAddr, (DWORD) logHook, 5);
	PlaceJMP((BYTE*) nextPacketAddr, (DWORD) newPacket, 5);
	PlaceJMP((BYTE*) GameSend, (DWORD) grabPacketObj, 5);
}

void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Main::gui = gcnew MainForm;
	initializeHook();
	Application::Run(Main::gui);
	Application::Exit();
}

std::string tokenize(const std::string& s) {
	if (!s.size()) {
		return "";
	}
	
}

void MainForm::button_sendPacket_Click(System::Object^  sender, System::EventArgs^  e) {

	std::string packet = msclr::interop::marshal_as<std::string>(textBox_sendPacket->Text);
	packet.erase(std::remove(packet.begin(), packet.end(), '['), packet.end());
	packet.erase(std::remove(packet.begin(), packet.end(), ']'), packet.end());
	packet.erase(std::remove(packet.begin(), packet.end(), ' '), packet.end());
	std::stringstream ss1;
	ss1 << packet[0];
	ss1 << packet[1];
	for (int i = 2; i < packet.size(); i+=2) {
		ss1 << ' ' << packet[i] << packet[i+1];
	}
	packet = ss1.str();
	print(packet);
	if (!(packet.find_first_not_of("0123456789ABCDEF ") == std::string::npos)
		|| (packet.find("  ") != std::string::npos)) {
		MessageBox::Show("Invalid Packet Format!", "Packet Sender", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	std::stringstream ss(packet);
	std::vector<std::string> tokens;
	std::string item;
	int len = 0;
	while (getline(ss, item, ' ')) {
		if (item.length() != 2) {
			MessageBox::Show("Invalid Packet Format!", "Packet Sender", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
		tokens.push_back(item);
		len += 1;
	}

	std::string* strBytes = &tokens[0];
	BYTE* byteArr = new BYTE[len];
	for (int i = 0; i < len; i++) {
		int x;
		std::stringstream ss2;
		ss2 << std::hex << strBytes[i];
		ss2 >> x;
		byteArr[i * sizeof(BYTE)] = (BYTE)x;
	}
	PoeSend(len, byteArr);
}