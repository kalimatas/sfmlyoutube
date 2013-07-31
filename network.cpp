#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

int main(int argc, char **argv)
{
	enum Mode {
		Sending,
		Receiving
	} mode;

	sf::TcpSocket socket;
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	char connectionType;
	char buffer[2000];
	size_t received;
	string text = "Connected to: ";

	cout << "Enter (s) for server, Enter (c) for client" << endl;
	cin >> connectionType;

	// server mode
	if (connectionType == 's') {
		sf::TcpListener listener;
		listener.listen(2000);
		listener.accept(socket);
		text += "Server";
		mode = Sending;
	}

	// client mode
	else if (connectionType == 'c') {
		socket.connect(ip, 2000);
		text += "Client";
		mode = Receiving;
	}

	socket.send(text.c_str(), text.length() + 1);
	socket.receive(buffer, sizeof(buffer), received);

	cout << buffer << endl;

	bool done = false;
	while (!done) {
		if (mode == Sending) {
			getline(cin, text);
			socket.send(text.c_str(), text.length() + 1);
			mode = Receiving;
		}
		else if (mode == Receiving) {
			socket.receive(buffer, sizeof(buffer), received);
			if (received > 0) {
				cout << "Received: " << buffer << endl;
				mode = Sending;
			}
		}
	}

	//system("pause");

	return EXIT_SUCCESS;
}
