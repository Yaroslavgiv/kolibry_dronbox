<!-- kolibry_dronbox/

├── CMakeLists.txt           # Файл конфигурации CMake
├── src/                     # Исходный код
├── include/                 # Заголовочные файлы
└── main.cpp     -->

<!-- 
src/
├── communication/            // Модуль взаимодействия
│   ├── server_comm.cpp       // Взаимодействие с центральным сервером
│   ├── drone_comm.cpp        // Взаимодействие с дроном
│   ├── connection_manager.cpp // Управление модулями связи
├── mechanisms/               // Модуль управления механизмами
│   ├── actuator_control.cpp  // Управление актуаторами
│   ├── positioning.cpp       // Позиционирование дрона
├── sensors/                  // Модуль управления датчиками
│   ├── sensor_manager.cpp    // Работа с датчиками (температуры, движения, уровня заряда)
│   ├── diagnostics.cpp       // Диагностика датчиков
├── power/                    // Модуль управления зарядкой
│   ├── charging_manager.cpp  // Зарядка аккумуляторов
│   ├── battery_handler.cpp   // Управление батареями
├── lighting/                 // Модуль управления подсветкой
│   ├── lighting_control.cpp  // Управление подсветкой
├── monitoring/               // Модуль мониторинга
│   ├── telemetry.cpp         // Сбор и передача телеметрии
│   ├── equipment_monitor.cpp // Мониторинг состояния оборудования
├── utils/                    // Утилиты
│   ├── config_loader.cpp     // Загрузка конфигурации
│   ├── logger.cpp            // Логирование
│   ├── error_handler.cpp     // Обработка ошибок
└── main.cpp                  // Основной файл запуска
-->