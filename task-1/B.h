#pragma once

#include "Interfaces.h"

class B : public IB {
	public:
		B() {}
		B(int id_) : id(id_) {}

		void request() {
			cout << "Server recieved request" << endl;
		}

		void recieve(int message) {
			cout << "Recived message " << message << endl;
		}

		int get_id() { return id; }

	private:
		int id;
};
