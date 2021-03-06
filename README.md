![simplinnovation](https://4.bp.blogspot.com/-f7YxPyqHAzY/WJ6VnkvE0SI/AAAAAAAADTQ/0tDQPTrVrtMAFT-q-1-3ktUQT5Il9FGdQCLcB/s350/simpLINnovation1a.png)

# MKR1000 & Arduino IoT Cloud (Beta)

__Video 1:__ _MKR1000 & Arduino IoT Cloud_, uploaded on Feb 18, 2019

[![Video Lintang MKR1000 IoT Cloud](https://img.youtube.com/vi/x0Jfc1bsxnU/0.jpg)](https://www.youtube.com/watch?v=x0Jfc1bsxnU)

__Video 2:__ _Arduino MKR1000, IoT Cloud & Its Cloud Remote App_, uploaded on Oct 5, 2020

[![Video Lintang MKR1000 IoT Cloud](https://img.youtube.com/vi/IriMoidDG8E/0.jpg)](https://www.youtube.com/watch?v=IriMoidDG8E)

#

## Hardware

- In this tutorial I'll use __Arduino MKR 1000__. You can use any Arduino boards that are compatible with the Arduino IoT Cloud, for example:
    - MKR WiFi 1010
    - MKR 1000
    - MKR NB 1500
    - MKR GSM 1400
    - MKR WAN 1300
    - Nano 33 IoT
    - Portenta H7
- _1x_ LED light
- _1x_ Potentiometer
- _1x_ DHT11 sensor
- _1x_ Breadboard
- Some jumper wires

#

## Tutorial

1. Connect all parts to Arduino MKR1000 as the following diagram:

    ![schema](./img/aSchema.png)

2. Signup/login to [arduino.cc](https://www.arduino.cc/) then go to Arduino IoT Cloud page ([create.arduino.cc/iot](https://create.arduino.cc/iot/)). 

3. Go to __Devices__ menu to configure your IoT device. First click _Add Device_ button then you will be noticed to download & install __Arduino Create Agent__. After that you will be asked to connect your IoT device to your computer. Arduino Create Agent will scan your device then inform you about your IoT device type & connected port. Simply click _Configure_ button, wait till finish & your device is ready to go.

    ![device](./img/bDevice.png)

4. Go to __Things__ menu to create your _Thing_ (project) with all respected _Properties_ (sensor/actuator). In this tutorial I create a _Thing_ called `Simplinnovation` with 3 properties: `led`, `pot` and `temp`.

    ![thing](./img/cThing.png)

5. Click _Edit Sketch_ button to code your IoT device using __Arduino Web Editor__. On _Secret_ tab, insert SSID (WiFi name) & its password, that will be used by your IoT device to connect to the internet. Then write these lines on `.ino` file tab:

    ![editor](./img/dEditor.png)

    ```arduino
    #include "thingProperties.h"
    #include "DHT.h"

    #define DHTPIN 5
    #define LEDPIN 4
    #define DHTTYPE DHT11
    DHT dht(DHTPIN, DHTTYPE);

    void setup() {
        setDebugMessageLevel(2);
        Serial.begin(9600);
        delay(1500); 
        initProperties();
        ArduinoCloud.begin(ArduinoIoTPreferredConnection);
        led = false;
        dht.begin();
    }

    void loop() {
        ArduinoCloud.update();
        pot = analogRead(A0);
        temp = dht.readTemperature();
    }

    void onLedChange() {
        digitalWrite(LEDPIN, led);
    }
    ```

    Verify & upload the sketch to your device.

6. After done uploading, on Arduino Web Editor click _Go To IoT Cloud_ button to create a dashboard. Click __Dashboard__ menu then create your own dashboard to monitor & control your device through the internet. In this tutorial, I create a _switch widget_ to control LED & 2 _value widgets_ to monitor my DHT11 & potentiometer value. To actvate your dashboard, click _Use Dashboard_ button.

    ![dashboard](./img/eDashboard.png)

7. Now you can control & monitor your device via Arduino IoT Cloud Dashboard. You can also use its __IoT Cloud Remote App__ to control & monitor your device on smartphone. Download it from [__Google Play Store__](https://play.google.com/store/apps/details?id=cc.arduino.cloudiot) (Android) or [__Apple App Store__](https://apps.apple.com/us/app/id1514358431) (iOS). Enjoy!

#

#### 🍔 Lintang Wisesa

<br>

<a href="mailto: lintangwisesa@ymail.com">
  <img align="left" style="margin-right:10px" alt="lintang ymail" width="22px" src="https://camo.githubusercontent.com/b6e5ff081d7552ec05656de193794847e14d47ad/68747470733a2f2f732e79696d672e636f6d2f63762f61706976322f6d79632f6d61696c2f4d61696c5f694f535f6170705f69636f6e2e706e67" />
</a>

<a href="https://web.facebook.com/lintangbagus/">
  <img align="left" style="margin-right:10px" alt="lintang facebook" width="22px" src="https://camo.githubusercontent.com/a461898d72dd9f4c8c526dfcca9dfdc8a8c69605/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f7468756d622f352f35312f46616365626f6f6b5f665f6c6f676f5f253238323031392532392e7376672f3130323470782d46616365626f6f6b5f665f6c6f676f5f253238323031392532392e7376672e706e67" />
</a>

<a href="https://twitter.com/Lintang_Wisesa">
  <img style="margin-right:10px" align="left" alt="lintang twitter" width="24px" src="https://camo.githubusercontent.com/b6943877f3d8a1269974b9f820388403ee2b1978/68747470733a2f2f332e62702e626c6f6773706f742e636f6d2f2d4e786f754d6d7a32624f592f54385f61633937636573492f41414141414141414767302f65337659315f62646e62452f73313630302f547769747465722b6c6f676f2b323031322e706e67" />
</a>

<a href="https://www.youtube.com/user/lintangbagus">
  <img style="margin-right:10px" align="left" alt="lintang youtube" width="29px" src="https://www.pinclipart.com/picdir/big/55-557137_a-quiet-drifter-takes-a-janitorial-job-at.png" />
</a>

<a href="https://www.linkedin.com/in/lintangwisesa/">
  <img style="margin-right:10px" align="left" alt="lintang linkedin" width="24px" src="https://camo.githubusercontent.com/0d70d8c72e2f45755511d6799489dc49d0e325f0/68747470733a2f2f692e70696e696d672e636f6d2f6f726967696e616c732f63652f30392f33632f63653039336337323134616433353762623636356366643266363661386236622e706e67" />
</a>

<a href="https://github.com/LintangWisesa">
  <img style="margin-right:10px" align="left" alt="lintang github" width="23px" src="https://camo.githubusercontent.com/11406e7ae7d4716fcc586cddf450451576d71bef/68747470733a2f2f696d6167652e666c617469636f6e2e636f6d2f69636f6e732f7376672f32352f32353233312e737667" />
</a>

<a href="https://www.hackster.io/lintangwisesa">
  <img style="margin-right:10px" align="left" alt="lintang hackster" width="23px" src="https://user-images.githubusercontent.com/10383395/49821324-358fa080-fda0-11e8-8b00-def2a67fc598.png" />
</a>

<a href="https://lintangwisesa.github.io/me/">
  <img style="margin-right:10px" align="left" alt="lintang bio" width="24px" src="https://avatars2.githubusercontent.com/u/30064213?s=460&u=6640a1c3d5c1892283e1c273006755de8d32fa59&v=4" />
</a>