//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "NicTests.h"
#include "TestApp.h"

Define_Module(NicTests);

void NicTests::planTestRun1()
{
	planTestModule("app0", "Receiving Host of pair A");
	planTestModule("app1", "Sending Host of pair A");
	planTestModule("app2", "Receiving Host of pair B");
	planTestModule("app3", "Sending Host of pair B");

	planTest("1.1", "A same channel but different time as B");
	planTest("1.2", "B same channel but different time as A");
	planTest("2.1", "A same channel same time as B");
	planTest("2.2", "B same channel same time as A");
	planTest("3", "Sender of B switches to different channel");
	planTest("4", "B different channel between sender and receiver");
	planTest("5", "Receiver of B switches to different channel");
	planTest("6", "B sender and receiver back to same channel");
	planTest("7.1", "A different channel same time as B");
	planTest("7.2", "B different channel same time as A");
}

void NicTests::testRun1(int stage, cMessage* msg)
{
	if(stage == 0) {
		getModule<TestApp>("app1")->testRun1(stage);
	} else if(stage == 1) {
		getModule<TestApp>("app3")->testRun1(stage);
	} else if(stage == 2) {
		getModule<TestApp>("app1")->testRun1(stage);
	} else if(stage == 3) {
		getModule<TestApp>("app3")->testRun1(stage);
	} else if(stage == 4) {
		getModule<TestApp>("app3")->testRun1(stage);
	} else if(stage == 5) {
		getModule<TestApp>("app2")->testRun1(stage);
		getModule<TestApp>("app3")->testRun1(stage);
	} else if(stage == 6) {
		getModule<TestApp>("app1")->testRun1(stage);
	} else if(stage == 7) {
		getModule<TestApp>("app3")->testRun1(stage);
	}
	//getModule<TestMacLayer>("mac0")->testRun1(stage, msg);
}





void NicTests::planTests(int run)
{
	//getModule<TestMacLayer>("mac0")->planTests(run);
    if(run == 1)
    {
        planTestRun1();
    }
    else
    	assertFalse("Unknown test run number: " + run, true);
}

void NicTests::runTests(int run, int stage, cMessage* msg)
{
	if(run == 1)
	{
		testRun1(stage, msg);
	}
	else
    	assertFalse("Unknown test run number: " + run, true);
}

