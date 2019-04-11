# Project Introduction

This project demonstrates how to integrate Grove PWM Driver with MangOH
## Hardware requirement
  1. Grove-16-Channel_PWM_Driver-PCA9685: http://wiki.seeedstudio.com/Grove-16-Channel_PWM_Driver-PCA9685/
  2. Grove Pi Connector: https://www.seeedstudio.com/GrovePi-p-2241.html
  3. Mangoh Red: http://mangoh.io

## Setup
  1. Connect mangoh, Grove Pi and PWM Driver as bellow
  2. Install app 'pwmDriverService':
        1. https://github.com/nxthongbk/pwmDriverService:
        1. This app will provide api to control pwm driver
  
  3. Install apps: 
        1. `pwmConfigureToDatahub`: set angle, limitation, period to datahub
        1. `pwmControlServo`:  get notification from datahub when data is changed and control servo motor 
