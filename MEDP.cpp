#include "MEDP.h"

const char MEDP::PROTOCOL_DIVIDER_CHAR = '#';
const char MEDP::COMMANDS_DIVIDER_CHAR = '&';
const char MEDP::FORWARD_COMMAND_CHAR = 'F';
const char MEDP::BACKWARD_COMMAND_CHAR = 'B';
const char MEDP::LEFT_TURN_COMMAND_CHAR = 'L';
const char MEDP::RIGHT_TURN_COMMAND_CHAR = 'R';

void MEDP::setup() {
  Serial.begin(9600); // Used to debug the application
}

void MEDP::execute(String message) {
  message = removeProtocolIdentifier(message);

  /**
    This while loop splits the message and
    extract every single instruction
  */
  int start = 0;
  int end = 0;
  while (end != -1) {
    end = message.indexOf(MEDP::COMMANDS_DIVIDER_CHAR, ++start);
    String command;
    command = (end != -1) ? message.substring(start, end) : message.substring(start);
    start = end;

    executeCommand(command);
  }
}

void MEDP::executeCommand(String command) {
  char commandIdentifier = command[0];

  if (commandIdentifier == MEDP::FORWARD_COMMAND_CHAR) {
    executeForward(command);
  } else if (commandIdentifier == MEDP::BACKWARD_COMMAND_CHAR) {
    executeBackward(command);
  } else if (commandIdentifier == MEDP::LEFT_TURN_COMMAND_CHAR) {
    executeTurnLeft(command);
  } else if (commandIdentifier == MEDP::RIGHT_TURN_COMMAND_CHAR) {
    executeTurnRight(command);
  }
}

void MEDP::executeForward(String command){
  int movementSize = parseInt(command.substring(1));

  PoombaEngines pe;
  pe.moveForward(movementSize);
}

void MEDP::executeBackward(String command){
  int movementSize = parseInt(command.substring(1));

  PoombaEngines pe;
  pe.moveBackward(movementSize);
}

void MEDP::executeTurnLeft(String command){
  int rotationDegrees = parseInt(command.substring(1));

  PoombaEngines pe;
  pe.turnLeft(rotationDegrees);
}

void MEDP::executeTurnRight(String command){
  int rotationDegrees = parseInt(command.substring(1));

  PoombaEngines pe;
  pe.turnRight(rotationDegrees);
}

String MEDP::removeProtocolIdentifier(String message) {
  int dividerPosition = message.indexOf(MEDP::PROTOCOL_DIVIDER_CHAR);
  return message.substring(dividerPosition);
}

int MEDP::parseInt(String value) {
  char charValue[value.length()+1];
  value.toCharArray(charValue, sizeof(charValue));
  return atoi(charValue);
}