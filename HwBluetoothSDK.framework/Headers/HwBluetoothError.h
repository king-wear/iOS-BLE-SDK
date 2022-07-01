/*!
 @header HwBluetoothError.h
 
 @author sujiang on 2018/4/13.
 @copyright  2021年 huawo. All rights reserved.
 */
#ifndef HwBluetoothError_h
#define HwBluetoothError_h

#import <Foundation/Foundation.h>

static NSString *const HwConnectionErrorDomain = @"HwConnectionErrorDomain";
static NSString *const HwSearchDevicesErrorDomain = @"HwSearchDevicesErrorDomain";
static NSString *const HwDisconnectDeviceErrorDomain = @"HwDisconnectDeviceErrorDomain";
static NSString *const HwDataErrorDomain = @"HwDataErrorDomain";
static NSString *const HwRequestErrorDomain = @"HwRequestErrorDomain";
static NSString *const HwDeviceErrorDomain = @"HwDeviceErrorDomain";


#pragma mark - CODE

/*!
 蓝牙SDK错误码
 
 - HwBCCodeBLEUnavailable: 蓝牙不可用
 - HwBCCodeRequestTimeout: 蓝牙任务超时
 - HwBCCodeRequestFailed: 蓝牙任务请求失败
 - HwBCCodeConnectTimeout: 连接超时
 - HwBCCodeSearchTimeout: 搜索超时
 - HwBCCodeDisconnectTimeout: 断连超时
 - HwBCCodeInvalidDevice: 连接不存在的设备
 - HwBCCodeDataFormatError: 设备回传数据解析错误
 - HwBCCodeParamsError: 请求参数错误
 - HwBCCodePowerLowError: 设备电量过低错误
 - HwBCCodeDeviceUnsuport: 设备不支持
 - HwBCCodeOtaError: ota出错
 */
typedef NS_ENUM(NSInteger, HwBCCode)
{
    HwBCCodeBLEUnavailable = 9,      // 设备不可用，蓝牙未打开
    HwBCCodeBLEDisconnected = 13,
    HwBCCodeBLEConnecting = 12,   // 正在连接
    HwBCCodeBLEException = 11,      // 蓝牙异常，手机系统bug，导致无法扫描出外设服务和特征
    HwBCCodeRequestTimeout = 14,
    HwBCCodeRequestFailed = 15,
    HwBCCodeConnectTimeout = 20,
    HwBCCodeSearchTimeout = 21,
    HwBCCodeDisconnectTimeout = 22,
    HwBCCodeInvalidDevice = 27,
    HwBCCodeConnectRepeat = 28,
    HwBCCodeConnectOverrided = 29,
    HwBCCodeDataFormatError = 30,
    HwBCCodeParamsError = 31,
    HwBCCodeTaskCancelError = 32,
    HwBCCodePowerLowError = 60,
    HwBCCodeDeviceUnsuport = 256,
    HwBCCodeOtaError = 90,
    HwBCCodeRequestOverrided = 100  // 请求被覆盖
};

#endif /* HwBluetoothCMDDefine_h */
