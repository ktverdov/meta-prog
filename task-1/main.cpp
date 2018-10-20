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

}

int main() {
	test_observer();
	test_proxy();
	test_mediator();

	return 0;
}