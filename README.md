# iOS-BLE-SDK

## Installation

### Requirements
iOS 9.0+

## Usage
Each API in the SDK, except for static methods, needs to be called through a single instance ``` [HwBluetoothSDK sharedInstance] ```. Do not create an instance yourself. Otherwise, SDK status may be wrong.
### Setup SDK
1. Init the SDK: ``` [[HwBluetoothSDK sharedInstance] initSDK] ```<br>
**It should be called when APP did finish launching.**
2. When you no longer need to use the SDK, call ```[[HwBluetoothSDK sharedInstance] destroySDK] ```<br>
**It should be called when you will never use SDK to do anything, for example, when APP will be terminated.**
3. Get SDK version by call ```[[HwBluetoothSDK sharedInstance] version]```.

### Connection

It is very important to note that scanning and connection can only be performed when HwBluetoothState is HwBluetoothStateAvailable.
You can monitor the changes of HwBluetoothState through ```addBluetoothStateChangedCallback```

1. You can make a ble connection by calling ```connectWithBleName``` to pass in the Bluetooth name of the watch.
2. Or you can call 'connectWithDevice' with the device returned by ```scanWithCallback``` API.
3. You can monitor Bluetooth connection status by ```addBluetoothConnectionStateChangedCallback```.
4. ```connected``` Get bluetooth connection status.
5. ```getPhoneConnectedDevices``` Get the connected devices in the Bluetooth settings of the mobile phone.

After connected, you can call any APIs to read/write data.

### Bind the Watch
Each customer has its own binding process, and our SDK also allows customers to define their own binding process, as follows:
* ```startBindDeviceWithCallback```/```startQRBindDeviceWithCallback``` start to bind watch, you can do anything before calling this API.
```startQRBindDeviceWithCallback```: Bind watch by QR code.<br>
```startBindDeviceWithCallback```: Bind watch by scanning results.
* ```endBindDeviceWithCallback``` end binding watch. you can do anything before calling this API.

We provide the reference binding process as follows:
1. Get watch basic info, such as ID/Firmware Version/Type.
2. Start binding.
3. Set watch basic info, such as user's height/weight/age, set watch's time.
4. End binding.

### Health Data
There are many pieces of health data, so when obtaining health data, you need to obtain the number first. Of course, this number only needs to be called once each time.

* ```getHealthDataCountWithCallback```, it will callback all health data count.
* ```getActivities```, get step/calorie/distance/duration health data.
* ```getSleeps```, get sleep data.
* ```getHeartrates```, get heart rate data.
* ```getHeartrateFatigues```, get stress & spo2 data.
* ```deleteXXXX```, after obtaining each kind of health data, the data in the watch should be deleted in time (this will not affect the display on the watch)

### Settings
The APIs of all setting methods start with set. You can find them through the header file or consult us directly.

### Workout

### Watchface

