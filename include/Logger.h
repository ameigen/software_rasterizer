#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <ctime>
#include "LoggerParams.h"

class Logger
{

    public:
        Logger()
        {
            log(INFO,
                "Logger successfully created!");
            log(DEBUG,
                "Logger successfully created!");
            log(WARNING,
                "Logger successfully created!");
            log(ERROR,
                "Logger successfully created!");
        }
        ~Logger(){};

        template <class... Args>
        void log(LogLevel logLevel, Args... args)
        {
            bool canLog = false;
            auto chronoTime = std::chrono::system_clock::now();
            std::time_t time = std::chrono::system_clock::to_time_t(chronoTime);
            switch(logLevel)
            {
                case INFO:
                    if (_logLevel >= INFO)
                    {
                        std::cout << "\x1b[" << _infoColor.foreground << "m\x1b[" <<  _infoColor.background << 'm' << "INFO\t| [" <<  strtok(std::ctime(&time), "\n") << "] ";
                        canLog = true;
                    }
                    break;
                case DEBUG:
                    if (_logLevel >= DEBUG)
                    {
                        std::cout << "\x1b[" << _debugColor.foreground << "m\x1b[" << _debugColor.background << 'm' << "DEBUG\t| ["  << strtok(std::ctime(&time), "\n") << "] ";
                        canLog = true;
                    }
                    break;
                case WARNING:
                    if (_logLevel >= WARNING)
                    {
                        std::cout << "\x1b[" << _warningColor.foreground << "m\x1b[" << _warningColor.background << 'm' << "WARNING\t| ["  << strtok(std::ctime(&time), "\n") << "] ";
                        canLog = true;
                    }
                    break;
                case ERROR:
                    if (_logLevel >= ERROR)
                    {
                        std::cout << "\x1b[" << _errorColor.foreground << "m\x1b[" << _errorColor.background << 'm' << "ERROR\t| ["  << strtok(std::ctime(&time), "\n") << "] ";
                        canLog = true;
                    }
                    break;
            }
            if (canLog)
                (std::cout << ... << args) << "\x1B[0m\n";
        }

        void setLogLevel(int level)
        {
            _logLevel = level;
        }

        void setLogColors(LogLevel logLevel, LogColors foreground, LogColors background)
        {
            switch(logLevel)
            {
                case INFO:
                    _infoColor.background = background;
                    _infoColor.foreground = foreground;
                    break;
                case DEBUG:
                    _debugColor.background = background;
                    _debugColor.foreground = foreground;
                    break;
                case WARNING:
                    _warningColor.background = background;
                    _warningColor.foreground = foreground;
                    break;
                case ERROR:
                    _errorColor.background = background;
                    _errorColor.foreground = foreground;
                    break;
            }
        }

    private:
        int _logLevel            = 1;
        TextColor _infoColor     = {WHITE_TEXT, BLACK_BACKGROUND};
        TextColor _debugColor    = {GREEN_TEXT, BLACK_BACKGROUND};
        TextColor _warningColor  = {YELLOW_TEXT, BLACK_BACKGROUND};
        TextColor _errorColor    = {RED_TEXT, BLACK_BACKGROUND};

};