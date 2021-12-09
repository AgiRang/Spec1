// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


//winsock2 code
#pragma comment(lib, "wa2_32.lib")
#include <Winsock2.h>
#include <iostream>
#include <map>
#include"Runtime/Core/public/HAL/Runnable.h"

class ASpec1GameMode;

using namespace std;

#define MAX_BUFFER		4096
#define SERVER_PORT		8000
#define SERVER_IP		"172.30.1.52"
#define MAX_CLIENTS		1000

struct stSocketinfo
{
	WSAOVERLAPPED	overlapped;
	WSABUF			dataBuf;
	SOCKET			socket;
	char			messageBuffer[MAX_BUFFER];
	int				recvBytes;
	int				sendBytes;
};

enum EPacketType
{
	LOGIN,
	LOGOUT_PLAYER,
	ENROLL_PLAYER,
	SEND_PLAYER,
	RECV_PLAYER,
	HIT_PLAYER,
	DAG_PLAYER,
	CHAT,
	ENTER_NEW_PLAYER,
	SIGNUP,
	HIT_MONSTER,
	SUNC_MONSTER,
	SPAWN_MONSTER,
	DESTROY_MONSTER
};

//Player Info

class cCharacter 
{
public:
	cCharacter() {};
	~cCharacter() {};

	//section ID
	int Sectionid;
	//locate
	float x;
	float y;
	float z;
	//Rotation
	float Yaw;
	float Pitch;
	float Roll;
	//Speed
	float VX;
	float VY;
	float VZ;
	//attribute
	bool IsAlive;
	bool Heath;
	bool IsAttack;

	friend ostream& operator<<(ostream& stream, cCharacter& info)
	{
		stream << info.Sectionid << endl;
		stream << info.x << endl;
		stream << info.y << endl;
		stream << info.z << endl;
		stream << info.Pitch << endl;
		stream << info.Roll << endl;
		stream << info.Yaw << endl;
		stream << info.VX << endl;
		stream << info.VY << endl;
		stream << info.VZ << endl;
		stream << info.Heath << endl;
		stream << info.IsAlive << endl;
		stream << info.IsAttack << endl;

		return stream;
	}
	friend istream& operator<<(istream& stream, cCharacter& info)
	{
		stream >> info.Sectionid;
		stream >> info.x;
		stream >> info.y;
		stream >> info.z;
		stream >> info.Pitch;
		stream >> info.Roll;
		stream >> info.Yaw;
		stream >> info.VX;
		stream >> info.VY;
		stream >> info.VZ;
		stream >> info.Heath;
		stream >> info.IsAlive;
		stream >> info.IsAttack;

		return stream;
	}
	class cCharacterInfo
	{
	public:
		cCharacterInfo() {};
		~cCharacterInfo() {};

		map<int, cCharacter>players;

		friend ostream& operator<<(ostream& stram, cCharacterInfo& info) {

		}
	private:

	};
};


class SPEC1_API ClientSocket
{
public:
	ClientSocket();
	~ClientSocket();
};
