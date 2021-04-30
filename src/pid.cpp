#include "pid.h"


PidController::PidController(float Kp, float Ki, float Kd, float setPoint,
                             float outputMin=OUTPUT_MIN_VALUE, 
                             float outputMax=OUTPUT_MAX_VALUE) 
    : Kp(Kp), Ki(Ki), Kd(Kd), setPoint(setPoint), outputMin(outputMin),
      outputMax(outputMax)
{
    dt = 0.1;
    last_error = 0;
}

PidController::~PidController() 
{
    
}

float PidController::update(float value) 
{
    float error = setPoint - value;

    // P
    proportinal = Kp * error;

    // I
    integral += Ki * integral * error;

    // D
    derivative = Kd * ( (error - last_error) / dt );

    // Sum output
    float output = proportinal + integral + derivative;

    // Ensure the output value is within the limits.
    output = limit(output);

    return output;
}

float PidController::limit(const float output) const
{
    if (output <= outputMin)
        return outputMin;
    else if (output >= outputMax)
        return outputMax;
    return output;
}
