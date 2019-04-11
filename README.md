# Project Introduction

This project demonstrates how to integrate Grove PWM Driver with MangOH
## Hardware requirement
  1. Grove-16-Channel_PWM_Driver-PCA9685: http://wiki.seeedstudio.com/Grove-16-Channel_PWM_Driver-PCA9685/
  2. Grove Pi Connector: https://www.seeedstudio.com/GrovePi-p-2241.html
  3. Mangoh Red: http://mangoh.io

## Setup
  1. Connect mangoh, Grove Pi and PWM Driver as bellow
  2. Install app PWMDriverService:https://github.com/nxthongbk/pwmDriverService
  This app will provide api to control pwm driver
  3. Install apps: 
  pwmConfigureToDatahub: set angle, limitation, period to datahub
  pwmControlServo:  Get notification when data is changed in datahub and control servo motor 
