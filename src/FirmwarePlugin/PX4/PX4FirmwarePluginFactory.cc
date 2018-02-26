/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


/// @file
///     @author Don Gagne <don@thegagnes.com>

#include "PX4FirmwarePluginFactory.h"
#include "PX4/PX4FirmwarePlugin.h"
PX4FirmwarePluginFactory PX4FirmwarePluginFactory;

PX4FirmwarePluginFactory::PX4FirmwarePluginFactory(void)
	: _pluginInstance(NULL)
{

}

QList<MAV_AUTOPILOT> PX4FirmwarePluginFactory::supportedFirmwareTypes(void) const
{
	QList<MAV_AUTOPILOT> list;

	list.append(MAV_AUTOPILOT_PX4);
	return list;
}

FirmwarePlugin *PX4FirmwarePluginFactory::firmwarePluginForAutopilot(MAV_AUTOPILOT autopilotType, MAV_TYPE vehicleType)
{
	Q_UNUSED(vehicleType);

	if (autopilotType == MAV_AUTOPILOT_PX4)
	{
		if (!_pluginInstance)
		{
			_pluginInstance = new PX4FirmwarePlugin;
		}

		return _pluginInstance;
	}

	return NULL;
}
