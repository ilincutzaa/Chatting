#pragma once
#include <vector>

class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer() = default;
};

class Subject {
private:
	std::vector<Observer*> observers;
public:
	void registerObserver(Observer* obs) {
		observers.push_back(obs);
	}
	void unregisterObserver(Observer* obs) {
		auto it = std::find(observers.begin(), observers.end(), obs);
		if (it != observers.end())
			observers.erase(it);
	}
	void notify() {
		for (auto o : observers)
			o->update();
	}
};