//
//  HwBluetoothDevice.h
//  HwBluetooth
//
//  Created by SuJiang on 2018/4/12.
//  Copyright © 2021年 huawo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "HwBluetoothCallback.h"

// ================== main ======================
extern NSString *HwBDMainServiceUUID;
extern NSString *HwBD8001CharacteristicMainWriteUUID;
extern NSString *HwBD8002CharacteristicNotificationUUID;

// ================== meida ====================
extern NSString *HwBDMediaServiceUUID;
extern NSString *HwBD8003CharacteristicMainWriteUUID;
extern NSString *HwBD8004CharacteristicNotificationUUID;
extern NSString *HwBDVoiceCharacteristicUUID;

// ================== heart ====================
extern NSString *HwBD_StandardHeartRateServiceUUID;
extern NSString *HwBD_StandardHeartRateCharacteristicUUID;

// ================== OTA ====================
extern NSString *HwBD_OTAServiceUUID;
extern NSString *HwBD_OTACharacteristicNotificationUUID;
extern NSString *HwBD_OTACharacteristicWriteUUID;
extern NSString *HwBD_OTADUFVersion;

// userInfo : {data:NSData}
extern NSString *HwBD_8001DidUpdateValueNotification;
extern NSString *HwBD_8002DidUpdateValueNotification;
extern NSString *HwBD_8003DidUpdateValueNotification;
extern NSString *HwBD_8004DidUpdateValueNotification;
extern NSString *HwBD_8006DidUpdateValueNotification;
extern NSString *HwBD_DidUpdateValueNotification;
extern NSString *HwBD_DidUpdateValueLoggerNotification;
extern NSString *HwBD_DidWriteValueLoggerNotification;

// 心率值来的通知
// userInfo : bpm:NSNumber
extern NSString *HwBD_HeartRateDidUpdateValueNotification;

extern const NSString *HwBluetoothDeviceRSSIUpdateNotification;
//extern NSString *HwBluetoothDevice


@class HwBluetoothConfig;
@class HwBluetoothData;
@class HwBluetoothDevice;

@protocol HwBluetoothDeviceDelegate<NSObject>
@optional
- (void) bluetoothDeviceWriteBackData:(NSData *)data fromCharacteristicUUID:(NSString *)uuid;
- (void) bluetoothDevice:(HwBluetoothDevice *)bluetoothDevice didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic;

@end

@interface HwBluetoothDevice : NSObject

@property(nonatomic, weak) id<HwBluetoothDeviceDelegate> delegate;
@property(nonatomic, assign, readonly) BOOL connected;

@property(nonatomic, strong, readonly) NSNumber *rssi;
@property(nonatomic, strong, readonly) CBPeripheral *peripheral;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, id> *advertisementData;
@property(nonatomic, copy, readonly) NSString *name;
@property(nonatomic, copy, readonly) NSString *macAddress;
@property(nonatomic, strong) HwBluetoothConfig *config;

// 如果peripheral的名字为null。返回也为nil
+ (HwBluetoothDevice *) deviceWithPeripheral:(CBPeripheral *)peripheral
                                        rssi:(NSNumber *)rssi
                           advertisementData:(NSDictionary<NSString *, id> *)advertisementData;


/**
 如果peripheral的名字为null。返回也为nil
 
 @param peripheral p
 @param rssi r
 @return device
 */
- (HwBluetoothDevice *) initWithPeripheral:(CBPeripheral *)peripheral
                                      rssi:(NSNumber *)rssi
                         advertisementData:(NSDictionary<NSString *, id> *)advertisementData;


#pragma mark - public methods
- (void) getReadyWithCallback:(HwDeviceRWReadyCallback)callback;

- (void) writeDataModel:(HwBluetoothData *)data;

- (void) writeData:(NSData *)data toCharactertic:(NSString *)charactericUUID;

- (void) dataModel:(HwBluetoothData *)data failedWithError:(NSError *)error;

- (BOOL) hasService:(NSString *)serviceUUID;
- (BOOL) hasCharacteristic:(NSString *)characteristicUUID;
- (BOOL) writeData:(NSData *)data toCharacteristic:(NSString *)characteristicUUID;
- (BOOL) readDataForCharacteristic:(NSString *)characteristicUUID;

#pragma mark - ota
- (void) writeDataToOTANotificationCharacteristic:(NSData *)data;
- (void) writeDataToOTAWriteCharacteristic:(NSData *)data;

#pragma mark - utils
- (NSUInteger) MTU;

- (void) disconnect;

@end
