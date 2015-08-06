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

	class Commander {
		protected:
			String _rawCmd;
		public:
			// Constructors
			Commander();

			// Getters and Setters
			String getRawCmd();

			bool isValidCmd(String& cmd);	// Checks if cmd has valid syntac (and some semantics, but will decouple those)
			bool hasValidCmd();				// uses isValidCmd and checks if cmd is done
			void recvCmd(String msg); 		// Appends new transmission to cmd
			void clearCmd();				// Clears cmd
	};

	// Utility functions
	String strFromCharArray(uint8_t* buf, uint8_t buflen);
};

#endif
