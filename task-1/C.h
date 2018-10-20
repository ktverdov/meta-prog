#pragma once

enum class Type { Observer, Proxy, Mediator };

template<Type T> class C {};

template<>
class C<Type::Observer> : public IObservable {
	public:
	    void subscribe(IObserver * const subscriber) {
	        subscribers.insert(subscriber);
	    }
	        
	    void unsubcribe(IObserver * const subscriber) {
	        subscribers.erase(subscriber);
	    }
	        
	    void notify(int message) {
	        for(auto subscriber : subscribers)
	            subscriber->handle(message);
	    }

	private:
		set<IObserver*> subscribers;

};

template<>
class C<Type::Proxy> : public IServer {
	public:
		C(IServer * server_) {
			server = server_;
		}

		void request() {
			cout << "Proxy processed request" << endl;
			server->request();
		} 
		
	private:
		IServer * server;
};


template<>
class C<Type::Mediator> {

};
