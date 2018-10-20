#pragma once

#include "Interfaces.h"

class A : public IObserver {
	public:
		A(string name_) : name(name_) {}
		
		A(IServer * proxy_) {
			proxy = proxy_;
		}

		A(IMediator * m_) {
			mediator = m_;			
		}

		void handle(int message) override {
        	cout << name << " recieve message: " << message << endl;
		}

		void contact(int message, int id) {
			mediator->contact(message, id);
		}

		void do_something() {
			cout << "client is doing some job" << endl;
			proxy->request();
		}

	private:
		IMediator * mediator;
		IServer * proxy;
		string name;
};