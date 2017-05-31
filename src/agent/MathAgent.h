/**
* Copyright 2017 IBM Corp. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/


#ifndef SELF_MATH_AGENT_H
#define SELF_MATH_AGENT_H

#include "IAgent.h"
#include "blackboard/Calculate.h"

#include "SelfLib.h"

class SELF_API MathAgent : public IAgent
{
public:
	RTTI_DECL();

	MathAgent()
	{}

	enum MathOp
	{
		SUM,		// +
		SUBTRACT,	// -
		DIVIDE,		// /
		MULTIPLY,	// *

		LAST_EO
	};

	//! ISerializable interface
	virtual void Serialize(Json::Value & json);
	virtual void Deserialize(const Json::Value & json);

	//! IAgent interface
	virtual bool OnStart();
	virtual bool OnStop();

private:
	const char * MathOpText(MathOp a_Op);
	MathAgent::MathOp GetMathOp(const std::string & a_Op);
	void PopulateVectorFromData(const std::string & a_Data, const std::string & a_Key, std::vector<double> & a_Vector);
	double PerformArithmetic(const std::string & a_Arithmetic, std::vector<double> & a_Vector);

	//! Callbacks
	void OnCalculate(const ThingEvent & a_ThingEvent);

};

#endif // SELF_MATHAGENT_H
