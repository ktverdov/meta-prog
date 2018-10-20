#pragma once

#include "Interfaces.h"

class A : public IObserver {
	public:
		A(string name_) : name(name_) {}
		
		A(IServer * proxy_) {
			proxy = proxy_;
		}

		void handle(int message) {
        	cout << name << " recieve message: " << message << endl;
		}

		void do_something() {
			cout << "client is doing some job" << endl;
			proxy->request();
		}

	private:
		IServer * proxy;
		string name;
};