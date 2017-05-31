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


#ifndef SELF_WORLD_AGENT_H
#define SELF_WORLD_AGENT_H

#include "IAgent.h"
#include "blackboard/IThing.h"
#include "SelfLib.h"

//! Model of Self agent -- this agent synchronizes data about this embodiment between the blackboard and the knowledge graph.
class SELF_API SelfAgent : public IAgent
{
public:
	RTTI_DECL();

	//! Construction
	SelfAgent();

	//! ISerializable interface
	void Serialize( Json::Value & json );
	void Deserialize( const Json::Value & json );

	//! IAgent interface
	virtual bool OnStart();
	virtual bool OnStop();

private:
};

#endif //SELF_OTHERS_AGENT_H
