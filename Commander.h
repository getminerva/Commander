//
// CASTLE Commander
//
// This is responsible for vetting and interacting with command strings.
//
// Written by Joshua Paul A. Chan
//

#ifndef Commander_h
#define Commander_h

#include "Arduino.h"

namespace castle {

	// Data types
	struct msg_t {
		char* msg_type;
		char* device_id;
		char* action;
		char* feature;
		char* val;
	};

	// Actor class
	class Commander {
		private:
			msg_t* _msgs;					// Holder for Messages
			String _rawCmd;
		public:
			// Constructors
			Commander();

			// Getters and Setters
			msg_t getRawCmd();

			bool isValidMsg(msg_t& msg);	// Checks if cmd has valid syntac (and some semantics, but will decouple those)
			bool hasValidMsg();				// uses isValidCmd and checks if cmd is done
			void recvChunk(String chunk); 	// Appends new transmission to cmd
			void sendMsg(msg_t msg);		// Sends a msg_t object
			void clearMsgs();				// Clears the msg array
			void clearMsg();				// Clears the last cmd
			void clearMsg(int n);			// Clear which message?

	};

	// Utility functions
	String strFromCharArray(uint8_t* buf, uint8_t buflen);
	String msgToString(msg_t msg);
};

#endif
