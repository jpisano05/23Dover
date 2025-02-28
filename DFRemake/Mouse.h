// Mouse Header

#include "Object.h"
#include "EventCollision.h"

class Mouse : public df::Object {
private:
	void out();
	void step();
public:
	Mouse();
	~Mouse();
	int eventHandler(const df::Event* p_e) override;
};