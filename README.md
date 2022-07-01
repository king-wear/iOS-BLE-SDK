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
