//
// CASTLE Commander.cpp
//
// Written by Joshua Paul A. Chan

#include "Arduino.h"
#include "Commander.h"

namespace castle {

	//// Commander class
	// Constructors
	Commander::Commander() {
		_rawCmd = "";
	}

	// Getters and Setters
	String Commander::getRawCmd() {
		return _rawCmd;
	}

	bool Commander::isValidMsg(msg_t& s) {
		// TODO: REDO
		Serial.print("Testing: ");
	    Serial.println(s);

	    // Pre-format
	    s.toLowerCase();
	    s.trim();

	    // Must be prefaced with "cmd::"
	    if (!s.startsWith("cmd::")) {
	        Serial.println("Test 1 failed.");
	        return false;
	    }
	    s = s.substring(5);

	    //  Serial.println(s);

	    // Action must be 'get', 'set' or 'do'
	    if (!s.startsWith("get::") &&  !s.startsWith("set::") && !s.startsWith("do::")) {
	        Serial.println("Test 2 failed.");
	        return false;
	    }
	    int action_pos = s.indexOf(':') + 1;
	    s = s.substring(action_pos + 1);

	    // Serial.println(s);

	    // Can only have feature 'power' or 'brightness'
	    if (!s.startsWith("power") && !s.startsWith("brightness")) {
	        Serial.println("Test 3 failed.");
	        return false;
	    }
	    int pos = s.indexOf(':') + 1;
	    s = s.substring(pos + 1);

	    // Serial.println(s);

	    // Value should only exist on set
		// TODO
	    // Value should be between 0-100 (percentage)
		// TODO

	    Serial.println("Tests passed.");

	    return true;
	}

	bool Commander::hasValidCmd() {
		if ((isValidCmd(_rawCmd)) and (_rawCmd.endsWith("::end"))) {
			return true;
		}
		return false;
	}

	void Commander::recvChunk(String msg) {
		_rawCmd += msg;
	}

	void Commander::clearMsgs() {
		// TODO
	}

	void Commander::clearMsg() {
		_rawCmd = "";
	}

	void Commander::clearMsg(int n) {
		// TODO
	}

	//// Utility functions

	// Takes a char array and spits out a string
	String strFromCharArray(uint8_t* buf, uint8_t buflen) {
		String res = "";
		for (int i = 0; i < buflen; ++i) {
			res += ((char)buf[i]);
		}
		return res;
	}

	// Takes a msg_t struct and turns it into a string
	String strFromMsg(msg_t& msg) {

	};
};
