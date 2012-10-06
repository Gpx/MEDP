#ifndef MEDP_H
#define MEDP_H

#include "Arduino.h"
#include "PoombaEngines.h"

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
  static const char FORWARD_COMMAND_CHAR;
  static const char BACKWARD_COMMAND_CHAR;
  static const char LEFT_TURN_COMMAND_CHAR;
  static const char RIGHT_TURN_COMMAND_CHAR;
  static const char LEFT_TURN_TEST_COMMAND_CHAR;
  static const char RIGHT_TURN_TEST_COMMAND_CHAR;
  
  void executeCommand(String command);       /** Parse anche execute the command */
  void executeForward(String command);       /** Parse and execute F command */
  void executeBackward(String command);      /** Parse and execute B command */
  void executeTurnLeft(String command);      /** Parse and execute L command */
  void executeTurnRight(String command);     /** Parse and execute R command */
  void executeTurnTestLeft(String command);  /** Parse and execute l command and test rotation */
  void executeTurnTestRight(String command); /** Parse and execute r command and test rotation */

  /** Utility functions */
  String removeProtocolIdentifier(String message); /** Return the message without protocol identifier */
  int parseInt(String value);                      /** Parse a string into an int value */
};

#endif