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

#include "button.h"

using namespace trik::robotModel::real::parts;
using namespace kitBase::robotModel;

Button::Button(const DeviceInfo &info, const PortInfo &port
		, utils::TcpRobotCommunicator &tcpRobotCommunicator)
	: robotParts::Button(info, port), mRobotCommunicator(tcpRobotCommunicator)
{
	connect(&mRobotCommunicator, &utils::TcpRobotCommunicator::newScalarSensorData
			, this, &Button::onIncomingData);
}

void Button::read()
{
	mRobotCommunicator.requestData("button:" + port().name());
}

void Button::onIncomingData(const QString &portName, int value)
{
	if (portName == port().name()) {
		emit newData(value);
	}
}
