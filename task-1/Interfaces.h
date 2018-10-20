#pragma once

#include <iostream>

#include <vector>
#include <string>
#include <set>

using namespace std;

class IObserver {
	public:
		virtual void handle(int message) = 0;
};

class IObservable {
	public:
		virtual void subscribe(IObserver * const subscriber) = 0;
		virtual void unsubcribe(IObserver * const subscriber) = 0;
		virtual void notify(int message) = 0;
};

class IServer {
	public:
		virtual void request() = 0;
};

// class AbstractBObserver {
// 	public:
// 		virtual void change(int new_state) = 0;
// };
