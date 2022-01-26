#pragma once
#include <iostream>
#include <array>

#define COMMANDS_NUMBER 5
#define REGISTER_NUMBERS 16

std::array<long int, REGISTER_NUMBERS> REGISTERS;
inline long int AND(long int aOper1, long int aOper2) { return aOper1 & aOper2; }
inline long int SUB(long int sOper1, long int sOper2) { return sOper1 - sOper2; }
long int (*operations[2])(long int, long int) = { AND, SUB };


class Command
{
protected:
	int operandRegister;
	int functionIndex;
public:
	Command(const int& oR, const int& fI) : operandRegister(oR), functionIndex(fI) {}
	virtual ~Command() = default;
};

class CommandRtoRAM : public Command 
{
private:
	long int* operandRam;
public:
	CommandRtoRAM(const int& oR, const int& fI, long int* oRam) : Command(oR, fI), operandRam(oRam) {}
	~CommandRtoRAM() = default;
	void operator() () {
		long int result = operations[functionIndex](operandRegister, *operandRam);
		*operandRam = result;
	}
	friend std::ostream& operator << (std::ostream& out, const CommandRtoRAM& commandRtoRAM);
};

std::ostream& operator << (std::ostream& out, const CommandRtoRAM& commandRtoRAM) {
	out << "First Operand Register: " << commandRtoRAM.operandRegister << std::endl;
	out << "Second Operand RAM: " << *(commandRtoRAM.operandRam) << std::endl;
}

class CommandRtoR : public Command
{
private:
	int secOperandRegister;
public:
	CommandRtoR(const int& oR, const int& fI, const int& secOR) : Command(oR, fI), secOperandRegister(secOR) {}
	~CommandRtoR() = default;
	void operator() () {
		long int result = operations[functionIndex](operandRegister, secOperandRegister);
		secOperandRegister = result;
	}
	friend std::ostream& operator << (std::ostream& out, const CommandRtoR& commandRtoR);
};

std::ostream& operator << (std::ostream& out, const CommandRtoR& commandRtoR) {
	out << "First Operand Register: " << commandRtoR.operandRegister << std::endl;
	out << "Second Operand Register: " << commandRtoR.secOperandRegister << std::endl;
}

class CommandSet
{
private:
	std::array<Command*, COMMANDS_NUMBER> set_;
public:
	CommandSet() : set_() {}
	~CommandSet() {
		for (int i = 0; i < set_.size(); i++) {
			delete set_[i];
		}
	}
	CommandSet& operator += (Command*& command) {
		set_[set_.size()] = command;
		return *this;
	}
};