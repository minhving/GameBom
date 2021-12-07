#include "GameBomb.h"
void printExecutionTime(ClockTime start_time, ClockTime end_time)
{
    auto execution_time_ns = duration_cast<nanoseconds>(end_time - start_time).count();
    auto execution_time_ms = duration_cast<microseconds>(end_time - start_time).count();
    auto execution_time_sec = duration_cast<seconds>(end_time - start_time).count();
    auto execution_time_min = duration_cast<minutes>(end_time - start_time).count();
    auto execution_time_hour = duration_cast<hours>(end_time - start_time).count();

    cout << "\nTime played: ";
    if (execution_time_hour > 0)
        cout << "" << execution_time_hour << " Hours, ";
    if (execution_time_min > 0)
        cout << "" << execution_time_min % 60 << " Minutes, ";
    if (execution_time_sec > 0)
        cout << "" << execution_time_sec % 60 << " Seconds, ";
  
}