#pragma once

#include "Interfaces.h"

class B : public IServer {
	public:
		void request() {
			cout << "Server recieved request" << endl;
		}
};

// class BObserver : public AbstractBObserver {
// 	public:
// 		BObserver(int state_) { state = state_; }

// 		void change(int new_state) {
// 			state = new_state;
// 		}

// 	private:
// 		int state;
// };