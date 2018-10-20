#include "A.h"
#include "B.h"
#include "C.h"


void test_observer() {
	cout << "TEST OBSERVER BEHAVIOUR" << endl;

	A * observer_1 = new A("Laptop");
	A * observer_2 = new A("Smartphone");
	auto observable = C<Type::Observer>();

	observable.subscribe(observer_1);
	observable.subscribe(observer_2);

	observable.notify(1);

	observable.unsubcribe(observer_1);

	observable.notify(2);

	cout << endl;
}


void test_proxy() {
	cout << "TEST PROXY BEHAVIOUR" << endl;

	B * server = new B();
	auto proxy = new C<Type::Proxy>(server);
	A * client = new A(proxy);
	client->do_something();

	cout << endl;
}

void test_mediator() {
	cout << "TEST MEDIATOR BEHAVIOUR" << endl;

	auto mediator = new C<Type::Mediator>();
	A * client = new A(mediator);
	
	B * target_1 = new B(1);
	B * target_2 = new B(2);

	mediator->add(target_1);
	mediator->add(target_2);

	client->contact(1, 2);

	cout << endl;
}

int main() {
	test_observer();
	test_proxy();
	test_mediator();

	return 0;
}