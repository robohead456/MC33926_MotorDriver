/**
 * @file MC33926_MotorDriver.h
 * @brief Class for controling a MC33926 Motor Driver
 * @author Michael Sidler
 */

/* 
 * This class is designed to work with a MC33926 breakout from Pololu
 *   https://www.pololu.com/product/1213
 * 
 * The wiring is as follows: 
 *   D1   = TIED LOW WITH JUMPER
 *   D2   = pin_EN
 *   IN1  = pin_PWM1
 *   IN2  = pin_PWM2
 *   FB   = pin_FB
 *   EN   = TIED HIGH WITH JUMPER
 *   GND  = MOTOR GROUND AND DIGITAL GROUND
 *   VDD  = 3.3/5V DIGITAL POWER
 * 
 */

#pragma once

#include <Arduino.h>
#include "Motor.h"

class MC33926_MotorDriver : public Motor{
    public:
        MC33926_MotorDriver(uint32_t pin_EN, uint32_t pin_PWM1, uint32_t pin_PWM2, uint32_t pin_FB, float Vin, float deadzone);

        virtual void setVoltage(float voltage) final;
        virtual void enable() final;
        virtual void disable() final;
        virtual float readCurrent() final;
        virtual float getLastVoltage() final;

    private:
        const float MV_PER_A = 525.0f;
        float Vin;
        float deadzone;
        float lastVoltage;
        uint32_t pin_EN;
        uint32_t pin_PWM1;
        uint32_t pin_PWM2;
        uint32_t pin_FB;
        
};