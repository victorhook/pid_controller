#ifndef PID_H
#define PID_H

#include <limits>
#define OUTPUT_MIN_VALUE std::numeric_limits<float>::min()
#define OUTPUT_MAX_VALUE std::numeric_limits<float>::max()


class PidController {

    private:
        float Kp;
        float Ki;
        float Kd;
        float proportinal;
        float integral;
        float derivative;
        float last_error;
        float dt;
        float setPoint;
        float outputMin;
        float outputMax;

        float limit(const float output) const;

    public:
        PidController(float Kp, float Ki, float Kd, float setPoint,
                      float outputMin=OUTPUT_MIN_VALUE, 
                      float outputMax=OUTPUT_MAX_VALUE);
        ~PidController();
        float update(float value);
};


#endif /* PID_H */
