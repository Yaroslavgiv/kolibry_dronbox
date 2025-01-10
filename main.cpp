#include <iostream>
#include "config_loader.cpp"
#include "logger.cpp"
#include "error_handler.cpp"
#include "telemetry.cpp"
#include "equipment_monitor.cpp"
#include "lighting_control.cpp"
#include "charging_manager.cpp"
#include "battery_handler.cpp"

int main() {
    try {
        // Initialize components
        ConfigLoader configLoader("config.json");
        configLoader.loadConfig();

        Logger logger("app.log");
        logger.log("Application initialized");

        Telemetry telemetry;
        telemetry.collectData();
        telemetry.sendData();

        EquipmentMonitor equipmentMonitor;
        equipmentMonitor.monitorStatus();

        LightingControl lighting(1);
        lighting.turnOn();
        lighting.setBrightness(75);
        lighting.turnOff();

        ChargingManager chargingManager;
        chargingManager.startCharging();
        chargingManager.stopCharging();

        BatteryHandler batteryHandler;
        batteryHandler.checkBatteryLevel();
        batteryHandler.replaceBattery();
    } catch (const std::exception& e) {
        ErrorHandler::handleError(e.what());
    }

    return 0;
}