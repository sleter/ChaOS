#pragma once

class Interpreter {
public:
	int PID;
	int regA;
	int regB;
	int regC;
	int InstructionCounter;

Interpreter()
{
	PID = 0;
	regA = 0;
	regB = 0;
	regC = 0;
	InstructionCounter = 0;
}
  

};