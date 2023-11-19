#if defined( _MSC_VER )
#if !defined( _CRT_SECURE_NO_WARNINGS )
#define _CRT_SECURE_NO_WARNINGS		// This file is not intended to be secure.
#endif
#endif

#include "graphics.h"
#include "tinyxml2.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace tinyxml2;
#include<iostream>
using namespace std;

#ifndef READNBA_H
#define READNBA_H

void ndatetime(char buffer[30])
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%dT%I:%M:%SZ+00:00", timeinfo);
}

void xmlnba()
{
	int i = 0;
	char buf[30];
	ndatetime(buf);
	tinyxml2::XMLDocument doc;
	doc.LoadFile("resultNBA.xml");
	int check;
	check = doc.ErrorID();
	if (check != 0)
		std::cout << "Document load failed.";
	XMLNode * pRoot = doc.FirstChild();
	if (pRoot == NULL)
		cout << "ERROR";
	XMLElement * pLeauge = doc.FirstChildElement();
	if (pLeauge == NULL)
		cout << "ERROR2";
	XMLElement * pSSElement = pLeauge->FirstChildElement();
	if (pSSElement == NULL)
		cout << "ERROR3";
	XMLElement * pGamesElement = pSSElement->FirstChildElement();
	if (pGamesElement == NULL)
		cout << "ERROR4";
	XMLElement * pGameElement = pGamesElement->FirstChildElement("game");
	if (pGameElement == NULL)
		cout << "ERROR5";
	XMLElement * pHomeElement = NULL;
	XMLElement * pAwayElement = NULL;
	XMLElement * pVenueElement = NULL;
	while (pGameElement != NULL && i < 10)
	{
		const char* status = pGameElement->Attribute("status");
		const char* schedule = pGameElement->Attribute("scheduled");
		if (!strcmp(status, "scheduled") && strcmp(schedule, buf) == 1)
		{
			pHomeElement = pGameElement->FirstChildElement("home");
			pAwayElement = pGameElement->FirstChildElement("away");
			pVenueElement = pGameElement->FirstChildElement("venue");
			const char* text = pHomeElement->Attribute("alias");
			const char* text1 = pAwayElement->Attribute("alias");
			const char* venue = pVenueElement->Attribute("city");
			//Text Styling
			setusercharsize(1, 2, 1, 2);
			settextstyle(4, HORIZ_DIR, 0);
			setbkcolor(BLACK);
			outtextxy(66, 223 + 37 * i, (char*)text);
			outtextxy(231, 223 + 37 * i, (char*)text1);
			outtextxy(437, 223 + 37 * i, (char*)venue);
			outtextxy(671, 223 + 37 * i, (char*)schedule);
			i++;
		}
		pGameElement=pGameElement->NextSiblingElement("game");
	}
}

#endif