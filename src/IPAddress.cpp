#include "IPAddress.h"

#include <iostream>
#include <fstream>
#include <cstring>
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
			<< "Press [2] to start ping manually\n\n" << "Enter your choice:\n";

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

	PingResult();

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
				system(("ping -n 5 " + ipAddress).c_str());
				system(("ping -n 5 " + ipAddress + ">> PingResult.txt" ).c_str());
				cout << endl << endl;

			}
		}

		ipList.close();

	} else
		cout << "Unable to open file";

}

void IPAddress::PingIPAddressManually() {

	cout << "Enter IP address or website:" << endl;

	cin >> ipAddressManual;

	system(("ping -n 5 " + ipAddressManual).c_str());
	system(("ping -n 5 " + ipAddressManual + "> PingResult.txt").c_str());
	cout << endl;

}

void IPAddress::PingResult() {

	cout << "IP Address with lowest ping is: " << endl << endl;

	ifstream pingResult("PingResult.txt");

	const char* delimiter = "m"; // TODO console is Russian, icons instead of words
	const int maxChars = 512;
	const int maxTokens = 20;
	int zero = 0;
	if (!pingResult.good()) {

		cout << "Open file error" << endl;
	}

	while (!pingResult.eof()) {

		char buff[maxChars];
		pingResult.getline(buff, maxChars);

		const char* token[maxTokens] = { };

		token[zero] = strtok(buff, delimiter);

		if (token[zero]) {
			for (int i = 0; i < maxTokens; i++) {

				token[i] = strtok(0, delimiter);
				if (!token[i])
					break;

				cout << token[i] << endl;
			}
		}
	}
	cout << endl << endl;
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

