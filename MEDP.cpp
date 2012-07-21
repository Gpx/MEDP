#include "MEDP.h"

const char MEDP::PROTOCOL_DIVIDER_CHAR = '#';
const char MEDP::COMMANDS_DIVIDER_CHAR = '&';

void MEDP::setup() {
  Serial.begin(9600); // Used to debug the application
}

void MEDP::execute(String message) {
  message = removeProtocolIdentifier(message);

  int start = 0;
  int end = 0;
  while (end != -1) {
    end = message.indexOf(MEDP::COMMANDS_DIVIDER_CHAR, ++start);
    String command;
    if (end != -1) {
      command = message.substring(start, end);
    } else {
      command = message.substring(start);
    }
    start = end;

    //TODO interpret command and execute action
    Serial.println(command);
  }
}

String MEDP::removeProtocolIdentifier(String message) {
  int dividerPosition = message.indexOf(MEDP::PROTOCOL_DIVIDER_CHAR);
  return message.substring(dividerPosition);
}