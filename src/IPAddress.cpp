#include "IPAddress.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_IPS = 7;
static string ipAddress;
static string ipAddressManual;

IPAddress::IPAddress() {

}

void IPAddress::Menu() {

	char option;
	char pingAgain;

	cout << "PING APPLICATION" << endl;
	cout << "\nPress [1] to start ping from file list\n"
			<< "Press [2] to start ping manually\n\n"
			<< "Enter your choice:\n";

	cin >> option;
	cout << endl;
	switch (option) {
	case '1':
		PingIPAddress();
		break;
	case '2':
		PingIPAddressManually();
		break;
	default:
		cout << "Wrong option, please try again: " << endl << endl;
	}

	cout << "Do you want to ping again?" << endl;
	cout << "Press [Y]es or [N]o" << endl;
	cin >> pingAgain;

	if (pingAgain == 'Y' || pingAgain == 'y') {
		system("cls");
		Menu();
	} else {
		system("exit");
	}

}
void IPAddress::PingIPAddress() {

	ifstream ipList("IpList.txt");

	if (ipList.is_open()) {
		while (ipList.good()) {

			for (int i = 0; i < MAX_IPS; i++) {

				IPWebsites(i);

				getline(ipList, ipAddress);
				cout << ipAddress << endl;
				system(("ping " + ipAddress).c_str());

				cout << endl << endl;

			}
		}

		ipList.close();
	} else
		cout << "Unable to open file";

	cout << "The address with the lowest ping is:\nTODO" << endl << endl;

}

void IPAddress::PingIPAddressManually() {


	cout << "Enter IP address or website:" << endl;

	cin >> ipAddressManual;

	system(("ping " + ipAddressManual).c_str());

	cout << endl;

}
void IPAddress::IPWebsites(int &i) {

	cout << "Ping";

	switch (i) {

	case 0:
		cout << " Google.com IP: ";
		break;
	case 1:
		cout << " Nike.com IP: ";
		break;
	case 2:
		cout << " Globallogic.com.ua IP: ";
		break;
	case 3:
		cout << " Facebook.com IP: ";
		break;
	case 4:
		cout << " Wikipedia.org IP: ";
		break;
	case 5:
		cout << " Yahoo.com IP: ";
		break;
	case 6:
		cout << " Youtube.com IP: ";
		break;
	}
}

IPAddress::~IPAddress() {

}

