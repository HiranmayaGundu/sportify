// My actaul XML Program.
//THIS IS NOT INTENDED TO BE SECURE, i.e., I wll NOT be using exceptions, though they are defined thanks to 
//tinyxml2's great work, as the rest of the program does not have exceptions.
#if defined( _MSC_VER )
#if !defined( _CRT_SECURE_NO_WARNINGS )
#define _CRT_SECURE_NO_WARNINGS		// This file is not intended to be secure.
#endif
#endif

#include "tinyxml2.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace tinyxml2;
#include<iostream>
using namespace std;
int main()
{
	//static const char* xml = "<?xml version="1.0" encoding="UTF - 8"?>"
	int i = 0;
	XMLDocument doc;
	doc.LoadFile("resultNBA.xml");
	int check;
	check = doc.ErrorID();
	if (check != 0)
	{
		std::cout << "Document load failed. Aborting program.";
		system("pause");
		system("exit");
	}
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
	while (pGameElement != NULL && i < 11)
	{
		pHomeElement = pGameElement->FirstChildElement("home");
		pAwayElement = pGameElement->FirstChildElement("away");
		i++;
		const char* text = pHomeElement->Attribute("name");
		const char* text1 = pAwayElement->Attribute("name");
		cout << text << " vs " << text1;
		system("pause");

		pGameElement=pGameElement->NextSiblingElement("game");
		if (pGameElement == nullptr)cout << "Error";
	}
		
	system("pause");
}
