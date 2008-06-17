#ifndef TESTGLOBALS_H_
#define TESTGLOBALS_H_

#include <TestModule.h>
#include <AirFrame.h>

enum {
	TEST_MACPKT = 12121
};

class AssertAirFrame:public AssertMessage {
protected:
	int state;
	AirFrame* pointer;
	simtime_t arrival;
public:
	AssertAirFrame(std::string msg,int state, simtime_t arrival, AirFrame* frame = 0, TestModule* cModule = 0, int cState = 0):
		AssertMessage(msg, cModule, cState), pointer(frame), arrival(arrival), state(state) {}
		
	/**
	 * Returns true if the passed message is the message
	 * expected by this AssertMessage.
	 * Has to be implemented by every subclass.
	 */
	virtual bool isMessage(cMessage* msg) {
		AirFrame* frame = dynamic_cast<AirFrame*>(msg);
		return frame != 0 && (frame == pointer || pointer == 0) && arrival == msg->arrivalTime() &&frame->getState() == state;
	}
};

#endif /*TESTGLOBALS_H_*/