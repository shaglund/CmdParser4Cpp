// Copyright (c) 2016 Per Malmberg
// Licensed under MIT, see LICENSE file. 

#pragma once
#include "IParseResult.h"

using namespace com::codezeal::commandline;

class SystemOutputParseResult : public IParseResult
{
public:
	SystemOutputParseResult();
	~SystemOutputParseResult();

	std::string GetParseResult() override;

	void UnknownArguments( const std::vector<std::string>& leftovers ) override;
	void NotEnoughParameters( const std::string& argument, int minParameterCount ) override;
	void FailedToParseArgument( const std::string& argument ) override;
	void ArgumentSpecifiedMultipleTimes( const std::string& argument ) override;
	void MissingMandatoryArgument( const std::string& argument ) override;
	void NoSuchArgumentDefined( const std::string& argument, const std::string& dependsOn ) override;
	void MissingDependentArgument( const std::string& argument, const std::string& dependsOn ) override;
	void NoSuchMutuallyExclusiveArgumentDefined( const std::string& argument, const std::string& missing ) override;
	void ArgumentsAreMutuallyExclusive( const std::string& argument, const std::string& blocker ) override;
private:
	std::vector<std::string> myLines;
};