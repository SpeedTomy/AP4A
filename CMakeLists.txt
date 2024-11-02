cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)


add_executable(untitled main.cpp Server.cpp
        TemperatureSensor.cpp
        Sensor.cpp
        Scheduler.cpp
        Data.h
        HumiditySensor.cpp
        SoundSensor.cpp
        SoundSensor.h
        LightSensor.cpp
        LightSensor.h)
