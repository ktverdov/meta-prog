#pragma once

enum class Type { Observer, Proxy, Mediator };

template<Type T> class C {};

template<>
class C<Type::Observer> : public IObservable {
	public:
	    void subscribe(IObserver * const subscriber) override {
	        subscribers.insert(subscriber);
	    }
	        
	    void unsubcribe(IObserver * const subscriber) override {
	        subscribers.erase(subscriber);
	    }
	        
	    void notify(int message) override {
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

		void request() override {
			cout << "Proxy processed request" << endl;
			server->request();
		} 
		
	private:
		IServer * server;
};


template<>
class C<Type::Mediator> : public IMediator {
	public:
		void add(IB * target) override {
			targets.emplace_back(target);
		}

		void contact(int message, int id) override {
			for (auto target : targets)
				if ( target->get_id() == id ) {
					cout << "Mediator found the desired object of B class" << endl;
					target->recieve(message);
				}
		}

	private:
		vector<IB*> targets;
};
