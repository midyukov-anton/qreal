/* Copyright 2007-2015 QReal Research Group
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#pragma once

#include "simpleVisitedRuleBase.h"

namespace generatorBase {
namespace semantics {

/// This rule is applied to blocks with simple semantics when it is connected to the
/// visited node. Creates infinite cycle starting from that node.
class SimpleVisitedOneZoneRule : public SimpleVisitedRuleBase
{
public:
	SimpleVisitedOneZoneRule(SemanticTree *tree, const qReal::Id &id, const LinkInfo &next);

	virtual bool apply();
};

}
}
