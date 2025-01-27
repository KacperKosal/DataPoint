#include "../Headers/Time.hpp"

Time::Time(const int hour, const int minute) {
    _hour = hour;
    _minute = minute;
}


int Time::GetHour() const {
    return _hour;
}

int Time::GetMinute() const {
    return _minute;
}

bool Time::operator<(const Time& other) const {
    if (_hour != other._hour) return _hour < other._hour;
    return _minute < other._minute;
}

bool Time::operator>(const Time& other) const {
    if (_hour != other._hour) return _hour > other._hour;
    return _minute > other._minute;
}
