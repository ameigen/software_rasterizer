#pragma once
enum LogLevel
{
    INFO = 0,
    DEBUG = 1,
    WARNING = 2,
    ERROR = 3,
};

enum LogColors
{
    RESET_COLOR,
    BLACK_TEXT = 30,
    RED_TEXT,
    GREEN_TEXT,
    YELLOW_TEXT,
    BLUE_TEXT,
    MAGENTA_TEXT,
    CYAN_TEXT,
    WHITE_TEXT,

    BLACK_BACKGROUND = 40,
    RED_BACKGROUND,
    GREEN_BACKGROUND,
    YELLOW_BACKGROUND,
    BLUE_BACKGROUND,
    MAGENTA_BACKGROUND,
    CYAN_BACKGROUND,
    WHITE_BACKGROUND,
};

struct TextColor
{
    public:
        TextColor(LogColors foreground, LogColors background)
                : foreground(foreground), background(background) {}
        LogColors foreground, background;
};
