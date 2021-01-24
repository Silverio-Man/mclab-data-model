//
// Created by Simone on 2019-08-18.
//

#include "Model/Literal.h"
#include "Model/Type.h"
#include "LiteralException.cpp"
#include <regex>

namespace Modeling {

	Literal::Literal(std::shared_ptr<Type> type, std::string val) : Expression(std::move(type)), value(std::move(val)) {
		std::regex realVal(R"(((\+|-)?[[:digit:]]+)(\.(([[:digit:]]+)?))?((e|E)((\+|-)?)[[:digit:]]+)?)");
		std::regex intVal(R"((\+|-)?[[:digit:]]+)");
		if (!((this->type->getName() == "Boolean" && (this->value == "true" || value == "false")) ||
			  (this->type->getName() == "Real" && regex_match(value, realVal)) ||
			  (this->type->getName() == "Integer" && regex_match(value, intVal))))
			throw LiteralException();
	}

	std::string Literal::getValue() {
		return value;
	}

}
