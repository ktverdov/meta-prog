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

class IB : public IServer {
	public:
		virtual void recieve(int message) = 0;
		virtual int get_id() = 0;
};

class IMediator {
	public:
		virtual void add(IB * target) = 0;
		virtual void contact(int message, int id) = 0;
};