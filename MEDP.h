#ifndef MEDP_H
#define MEDP_H

#include "Arduino.h"

/**
Class to parse a MEDP message
*/
class MEDP
{
public:
  void setup();                 /** Setup serial pins to debug */
  void execute(String message); /** Parse the message and action engines */

private:
  /** Protocol constants declarations */
  static const char PROTOCOL_DIVIDER_CHAR;
  static const char COMMANDS_DIVIDER_CHAR;

  String removeProtocolIdentifier(String message); /** Return the message without protocol identifier */
};

#endif