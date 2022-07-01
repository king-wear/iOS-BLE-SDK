//
//  HwBluetoothDeviceRequestManager.h
//  HwBluetooth
//
//  Created by SuJiang on 2018/4/7.
//  Copyright © 2021年 huawo. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Camera
typedef NS_ENUM(NSInteger, HwCameraEvent)
{
    HwCameraEventShot = 0x00,
    HwCameraEventExit = 0x01,
    HwCameraEventEnter = 0x02,
    HwCameraEventDelayShot = 0x03
};
typedef void (^HwCameraEventCallback)(HwCameraEvent event);
typedef void (^HwCameraDelayEventCallback)(HwCameraEvent event,NSInteger delay, NSInteger photoNum);

#pragma mark - Search iPhone
typedef NS_ENUM(NSInteger, HwSearchPhoneState)
{
    HwSearchPhoneStateSearching = 0x00,
    HwSearchPhoneStateStop = 0x01
};

typedef void (^HwSearchPhoneCallback)(HwSearchPhoneState state);


/**
 设备通知手表事件 (Device notify APP event)

 - HwDeviceEventCalibrationHourPointer: 设备正在进行时针校准 device is collating hour hand
 - HwDeviceEventCalibrationMinutePointer: 设备正在进行分针校准 device is collating minute hand
 - HwDeviceEventExitCalibration: 设备退出了较时   device quit calibration
 - HwDeviceEventUploadData: 设备请求APP上传数据到 strava device ask APP to upload data to Strava
 */
typedef NS_ENUM(NSInteger, HwDeviceEvent)
{
    HwDeviceEventCalibrationHourPointer = 0x03,
    HwDeviceEventCalibrationMinutePointer = 0x04,
    HwDeviceEventExitCalibration = 0x05,
    HwDeviceEventUploadData = 0x06,
    HwDeviceEventSyncWeather = 0x07,
    HwDeviceEventSyncAgps = 0x08,
    HwDeviceEventHeartRateMonitorFailed = 0x09
};

typedef void (^HwDeviceEventCallback)(HwDeviceEvent type);
typedef void (^HwDeviceControlCallback)(BOOL success);

// 设备配对状态通知回调
typedef void (^HwDevicePairStateCallback)(BOOL success);

/*!
 蓝牙任务管理类
 */
@interface HwBluetoothDeviceRequestManager : NSObject

+ (HwBluetoothDeviceRequestManager *_Nonnull)sharedInstance;

- (void) addCameraEventCallback:(HwCameraEventCallback _Nonnull)callback;
- (void) removeCameraEventCallback:(HwCameraEventCallback _Nonnull)callback;
- (void) removeAllCameraEventCallbacks;

- (void) addCameraDelayEventCallback:(HwCameraDelayEventCallback _Nonnull)callback;
- (void) removeCameraDelayEventCallback:(HwCameraDelayEventCallback _Nonnull)callback;
- (void) removeAllCameraDelayEventCallbacks;

- (void) addSearchPhoneCallback:(HwSearchPhoneCallback _Nonnull)callback;
- (void) removeSearchPhoneCallback:(HwSearchPhoneCallback _Nonnull)callback;
- (void) removeAllSearchPhoneCallbacks;

- (void) addDeviceEventCallback:(HwDeviceEventCallback _Nonnull)callback;
- (void) removeDeviceEventCallback:(HwDeviceEventCallback _Nonnull)callback;
- (void) removeAllDeviceEventCallbacks;

- (void) addDeviceControlCallback:(HwDeviceControlCallback _Nonnull)callback;
- (void) removeDeviceControlCallback:(HwDeviceControlCallback _Nonnull)callback;
- (void) removeAllDeviceControlCallbacks;

- (void) addDevicePairStateCallback:(HwDevicePairStateCallback _Nonnull)callback;
- (void) removeDevicePairStateCallback:(HwDevicePairStateCallback _Nonnull)callback;
- (void) removeAllDevicePairStateCallbacks;

- (void) deviceDataComeFromHeartRate:(NSData *_Nullable)data;
- (void) deviceDatasComeFrom8004:(NSData *_Nullable)data;

@end
