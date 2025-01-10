cmake_minimum_required(VERSION 3.10)
project(CommunicationProject)

# Установить стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Указать путь к заголовочным файлам
include_directories(include)

# Добавить исходные файлы
set(SOURCES
    src/server_comm.cpp
    src/drone_comm.cpp
    src/connection_manager.cpp
    main.cpp
)

# Добавить библиотеки OpenSSL
find_package(OpenSSL REQUIRED)

# Создать исполняемый файл
add_executable(communication_project ${SOURCES})

# Связать библиотеки
target_link_libraries(communication_project OpenSSL::SSL OpenSSL::Crypto ws2_32)
