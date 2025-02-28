// Mouse Header

#include "Object.h"
#include "EventCollision.h"

class Mouse : public df::Object {
private:
	int health;

	void out();
	void step();
public:
	Mouse();
	~Mouse();
	int eventHandler(const df::Event* p_e) override;

	//Setter/getter for health
	void setHealth(int newHealth);
	int getHealth();
};