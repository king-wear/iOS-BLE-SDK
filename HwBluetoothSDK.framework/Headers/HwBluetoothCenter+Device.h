/*!
 @header HwBluetoothCenter+Device.h
 
 @author sujiang on 2018/4/21.
 @copyright  2021年 huawo. All rights reserved.
 */
#import "HwBluetoothCenter.h"
#import "HwDeviceDefines.h"
#import "HwTimeFaceStyleModel.h"
#import "HwVibrationModel.h"
#import "HwDontDisturbModel.h"
#import "HwTimeZone.h"
#import "HwWeatherInfo.h"
#import "HwLocalizeTimeZone.h"
#import "HwMenstrual.h"
#import "HwContact.h"

#pragma mark - define

#pragma mark - class
/*!
 @brief 设备相关API接口 API of the device
 */
@interface HwBluetoothCenter (Device)

#pragma mark - 手表基本信息 basic info about watch

/*! @brief
 获取设备的ID get ID of the watch
 
 @param callback 字符串回调
 @return task
 */
- (HwBluetoothTask *_Nullable) getDeviceIdWithCallback:(HwStringCallback _Nullable)callback;

/*! @brief
获取设备的Mac地址 get Mac address of the watch

@param callback 字符串回调
@return task
*/
- (HwBluetoothTask *_Nullable) getDeviceMacAddressWithCallback:(HwStringCallback _Nullable)callback;

/*! @brief
 获取固件版本号 get firmware version no.
 
 @param callback string 回调
 @return task
 */
- (HwBluetoothTask *_Nullable) getFirmwareVersionWithCallback:(HwStringCallback _Nullable)callback;

/*! @brief
 获取设备信息 Get device info
 
 @param type 信息类型 info type
 @param callback 回调 callback
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) getDeviceInfoForType:(NSInteger)type
                                           callback:(HwStringCallback _Nullable)callback;

/*! @brief
 获取设备类型 get device type
 
 @param callback 字符串回调
 @return task
 */
- (HwBluetoothTask *_Nullable) getDeviceTypeWithCallback:(HwStringCallback _Nullable)callback;

/*! @brief
 开始绑定设备 starting to pairing with watch
 
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) startBindDeviceWithCallback:(HwBoolCallback _Nullable)callback;


/*! @brief
 开始以二维码方式 绑定设备 starting to pairing with watch using QRCODE
 
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) startQRBindDeviceWithCallback:(HwBoolCallback _Nullable)callback;


/*! @brief
 结束绑定设备 End pairing
 
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) endBindDeviceWithCallback:(HwBoolCallback _Nullable)callback;

/*! @brief
 获取设备的绑定状态 get bind state of device

 @param callback bindState
 @return task
 */
- (HwBluetoothTask *_Nullable) getBindStateWithCallback:(void(^_Nonnull)(HwBindState bindState, NSError * _Nullable error))callback;




/*! @brief
 设置设备时间 Set time format of watch
 
 @param is24H 是否24小时制 if time format is 24H
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) setDeviceTimeWith24H:(BOOL)is24H
                                           callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 设置时间到设备上 [set time to device]
 
 @param time 时间
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) setDeviceTime:(NSDate *_Nonnull)time
                                   callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 获取设备上的时间 [get time from device]
 
 @param callback 时间回调
 @return task
 */
- (HwBluetoothTask *_Nullable) getDeviceTimeWithCallback:(HwDateCallback _Nullable)callback;

/*! @brief
 重启设备 [reset watch]
 
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) restartDeviceWithCallback:(HwBoolCallback _Nullable)callback;

/**
 解绑指令 [unbind watch]，目的是为了让设备端断连BT(经典蓝牙)
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask * _Nullable) unbindDeviceWithCallback:(HwBoolCallback _Nullable)callback;
/**
 查询BT开关状态
 */
- (HwBluetoothTask * _Nullable)queryBtSwitchStatusWithCallback:(HwBoolCallback _Nullable)callback;
/**
 设置BT开关
 */
- (HwBluetoothTask * _Nullable)setBtSwitchStatus:(BOOL)status callback:(HwBoolCallback _Nullable)callback;

- (HwBluetoothTask *_Nullable) updateLocalizeTimeZones:(NSArray <HwLocalizeTimeZone *> *_Nonnull)localizeTimeZones  callback:(HwBoolCallback _Nullable)callback;
- (HwBluetoothTask *_Nullable) setLocalizeTimeZone:(HwLocalizeTimeZone *_Nonnull)timezone callback:(HwBoolCallback _Nullable)callback;
- (HwBluetoothTask *_Nullable) removeLocalizeTimezoneById:(NSInteger)Id
                                        callback:(HwBoolCallback _Nullable)callback;
- (HwBluetoothTask *_Nullable) getLocalizeTimeZonesWithCallback:(void(^_Nullable)(NSArray<HwLocalizeTimeZone *> *timeZones, NSError *error))callback;

- (HwBluetoothTask *_Nullable) findDeviceWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - 手表设置 [watch setting]

/*! @brief
 重置设备 [reset watch]
 
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) resetDeviceWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - 亮度 [brightness]

/*! @brief
 设置手表的亮度 [set brightness of device]
 
 @param value 0 ～ 100
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) setBrightnessValue:(NSInteger)value callback:(HwBoolCallback _Nullable )callback;

/*! @brief
 获取手表的亮度 [get brightness of device]
 
 @param callback integer回调
 @return task
 */
- (HwBluetoothTask *_Nullable) getBrightnessValueWithCallback:(HwBCIntegerCallback _Nullable )callback;

#pragma mark - 语言 [language]

/*! @brief
 设置手表的语言类型 [set language of device]
 
 @param language 语言类型
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) setLanguage:(HwLanguage)language callback:(HwBoolCallback _Nullable )callback;

/*! @brief
 获取语言类型 [get language type]
 
 @param callback 语言类型回调
 @return task
 */
- (HwBluetoothTask *_Nullable) getLanguageWithCallback:(HwLanguageCallback _Nullable )callback;

#pragma mark - watch time face style





/*! @brief
 设置手表时间界面样式
 
 @param model 样式模型
 @param callback bool回调
 @return task
 */
- (HwBluetoothTask *_Nullable) setTimeFaceStyleWithModel:(HwTimeFaceStyleModel *_Nonnull)model
                                               callback:(HwBoolCallback _Nullable )callback;

/*! @brief
 设置时间界面样式，如果设备不支持那个样式，传入-1
 
 @param dateStyle 日期样式
 @param timeStyle 时间样式
 @param batteryStyle 电池样式
 @param lunarStyle 农历样式
 @param screenStyle 屏幕样式
 @param backgroundStyle 背景样式
 @param heartRateStyle 心率样式
 @param usernameStyle 用户名样式
 @param callback 成功与否的回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) setTimeFaceStyleWithDateStyle:(HwDateStyle)dateStyle
                                                   timeStyle:(HwTimeStyle)timeStyle
                                                batteryStyle:(HwBatteryStyle)batteryStyle
                                                  lunarStyle:(HwLunarStyle)lunarStyle
                                                 screenStyle:(HwScreenStyle)screenStyle
                                             backgroundStyle:(NSInteger)backgroundStyle
                                              heartRateStyle:(HwHeartRateStyle)heartRateStyle
                                               usernameStyle:(HwUsernameStyle)usernameStyle
                                                    callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 获取时间界面样式
 
 @param callback 样式回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) getTimeFaceStyleWithCallback:(HwTimeFaceStyleCallback _Nullable)callback;

#pragma mark - 自定义表盘 [custom watch face]

/*! @brief
 获取设备中，所有自定义表盘的crc值 [get all the crc value of customerized watch faces in the watch]
 
 @param callback NSArray<NSData *> * callback
 @return task
 */
- (HwBluetoothTask *_Nullable) getAllCustomWatchFaceCrcsWithCallback:(HwBCArrayCallback _Nullable )callback;

/*! @brief
 获取设备中，所有自定义表盘的Id [get all the ID of the customerized watch faces in the watch]
 
 @param callback NSArray<NSNumber *> * callback
 @return task
 */
- (HwBluetoothTask *_Nullable) getAllCustomWatchFaceIDsWithCallback:(HwBCArrayCallback _Nullable )callback;



/*! @brief
 获取自定义表盘在设备中的信息 [get customerized watch face information from device,such as index and address]
 索引、地址等
 
 @param crcData crc值（2位）
 @param callback 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) getCustomWatchFaceInfoByCrcData:(NSData *_Nonnull)crcData
                                                     callback:(HwCustomWatchFaceInfoCallback _Nullable )callback;

/*! @brief
 get a store address for picture on watch
 this method will callback an index and address allocated by watch for the picture on watch's disk
 
 @param ID picture's ID（2 bit）
 @param callback if index == 0x00, means watch had already stored the picture of this ID. don't need to OTA again
 @return bluetooth task
 */
- (HwBluetoothTask *_Nullable) getCustomWatchFaceInfoByID:(NSUInteger)ID
                                                callback:(HwCustomWatchFaceInfoCallback _Nullable )callback;

+ (NSData *_Nonnull) createOnlineWatchFaceDataAddress:(NSData *_Nonnull)address
                                      picData:(NSData *_Nonnull)picData;

+ (NSData *_Nonnull) createWatchFaceOtaDataWithIndex:(NSInteger)index
                                     address:(NSData *_Nonnull)address
                                     picData:(NSData *_Nonnull)picData
                                     crcData:(NSData *_Nonnull)crcData;

/*! @brief
 根据ID，删除设备中自定义的表盘信息 [delete watch face according to ID]
 
 @param ID ID
 @param callback 回调
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) deleteCustomWatchFacePicWithID:(NSUInteger)ID
                                                     callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 根据crc值，删除设备中自定义的表盘信息 [delete watch face according to crc value]
 crc 2 bit length
 
 @param crcData crc值
 @param callback 回调
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) deleteCustomWatchFacePicWithCrc:(NSData *_Nonnull)crcData
                                                      callback:(HwBoolCallback _Nullable)callback;
/*! @brief
 根据crc值，删除设备中自定义的表盘信息 [delete watch face according to crc value]
 crc 4 bit length
 
 @param crcData crc值
 @param callback 回调
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) deleteCustomWatchFacePicWithCrc4:(NSData *_Nonnull)crcData
                                                       callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 删除所有自定义表盘 [delete all the watch faces ]
 
 @param callback 成功与否回调
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) deleteAllCustomWatchFacePicWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - 震动 [vibration]


/*! @brief
 获取设备上的震动类型 [get vibration type from device]
 
 @param callback 回到
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) getVibrationWithCallback:(HwVibrationArrayCallback _Nullable)callback;

/*! @brief
 设置震动类型 [set vibration type]
 
 @param vibration 震动数据模型
 @param callback 回调
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) setVibration:(HwVibrationModel *_Nonnull)vibration
                                   callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 设置震动类型 [set vibration type]
 
 @param type 类型
 @param state 状态
 @param callback 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) setVibrationType:(HwVibrationType)type
                                          state:(HwVibrationState)state
                                       callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 获取震动强度 [get vibration intensity]
 
 @param callback 震动强度回调
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) getVibrationStrengthWithCallback:(HwBCIntegerCallback _Nullable)callback;

/*! @brief
 设置震动强度 [set vibration intensity]
 
 @param strength 强度
 @param callback 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) setVibrationStrength:(NSInteger)strength
                                  callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 设置震动类型的震动强度
 
 @param type 类型
 @param callback 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) setVibrationStrengthWithType:(HwVibrationStrengthType)type
                                                   callback:(HwBoolCallback _Nullable)callback;

#pragma mark - weather

- (HwBluetoothTask *_Nullable) setWeatherInfoWithCity:(NSString *_Nonnull)city
                                          weatherInfo:(HwWeatherInfo *_Nonnull)weatherInfo
                                             forecast:(NSArray<HwWeatherInfo *> *_Nullable)forecasts
                                             callback:(HwBoolCallback _Nullable)callback;

- (HwBluetoothTask *_Nullable) getWeatherUnitWithCallback:(void(^_Nullable)(HwWeatherUnit unit, NSError * _Nullable error))callback;

- (HwBluetoothTask *_Nullable) setWeatherUnit:(HwWeatherUnit)unit
                                     callback:(HwBoolCallback _Nullable)callback;

#pragma mark - timezone（时区设置）


/*! @brief
 获取设备时间区 [get timezone infor of device]
 
 @param callback 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) getTimezoneWithCallback:(HwTimezoneCallback _Nullable)callback;
- (HwBluetoothTask *_Nullable) setTimezone:(HwTimeZone *_Nonnull)timezone
                                  callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 设置设备时间区 [set timezone of device]
 
 @param area 时间区 timezone
 @param hour 小时
 @param min 分钟
 @param city 城市
 @param callback 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) setTimezoneArea:(HwTimezoneArea)area
                                          hour:(NSInteger)hour
                                           min:(NSInteger)min
                                          city:(NSString *_Nonnull)city
                                      callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 获取系统的语言类型（非蓝牙指令）[get system language]
 
 @return 语言类型
 */
- (HwLanguage) getSystemLanguageType;

#pragma mark - 手机匹配弹框操作
//查询匹配的状态
- (HwBluetoothTask *_Nullable)getPairStateWithCallback:(HwBoolCallback  _Nullable)callback;
//设置
- (HwBluetoothTask *_Nullable)requestDeviceToPairWithCallback:(HwBoolCallback  _Nullable)callback;

#pragma mark - 获取BT连接状态
- (HwBluetoothTask *_Nullable)getBtConnectionStateWithCallback:(HwBoolCallback  _Nullable)callback;

#pragma mark - power

/*! @brief
 获取设备电量 [get device battery volumn]
 
 @param callback 回调0-100
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) getBatteryWithCallback:(HwBCIntegerCallback _Nullable)callback;
#pragma mark - power state

/*! @brief
 获取设备电量的状态 - 目前针对的x11设备 后续进行补录
 
 @param callback 回调 0 1 2 3
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) getBatteryStateWithCallback:(HwBCIntegerCallback _Nullable)callback;

#pragma mark - volumn

/*! @brief
 获取设备的音量 [get device voice volumn]
 
 @param callback 音量回调0-100
 @return 任务
 */
- (HwBluetoothTask *_Nullable) getVolumnWithCallback:(HwBCIntegerCallback _Nullable)callback;

/*! @brief
 设置设备的音量 [set device voice volumn]
 
 @param volumn 音量0-100
 @param callback 成功与否的回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) setVolumn:(NSInteger)volumn callback:(HwBoolCallback _Nullable)callback;

#pragma mark - 工作模式 [work mode]


// zetime 不支持
- (HwBluetoothTask *_Nullable) getWorkModeWithCallback:(HwWorkModeCallback _Nullable)callback;
- (HwBluetoothTask *_Nullable) setWorkMode:(HwDeviceWorkMode)mode
                                  callback:(HwBoolCallback _Nullable)callback;


#pragma mark - 亮屏时间 [screen timeout durartion]
// 获取设备亮屏时间（1-20秒）
// zetime不支持
- (HwBluetoothTask *_Nullable) getScreenOnTimeWithCallback:(HwBCIntegerCallback _Nullable)callback;
- (HwBluetoothTask *_Nullable) setScreenOnTime:(NSInteger)second
                                      callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 获取设备灭屏时间，单位为 秒 [get screen timeout durartion]
 
 @param callback 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) getScreenOffTimeWithCallback:(HwBCIntegerCallback _Nullable)callback;

/**
 设置设备灭屏时间 [set screen timeout durartion]
 
 @param second 秒
 @param callback 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) setScreenOffTime:(NSInteger)second
                                       callback:(HwBoolCallback _Nullable)callback;

#pragma mark - 设置贪睡时间间隔 [set snooze durartion]
/*! @brief
 设置贪睡时间（分钟）[set snooze durartion(minutes)]
 
 @param value 多少分钟 [how many minutes]
 @param callback 成功与否 [success or not]
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) setSnoozeValue:(NSInteger)value
                            callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 获取设备设置的贪睡时间（分钟）[get snooze durartion(minutes)]
 
 @param callback 整型回调
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) getSnoozeValueWithCallback:(HwBCIntegerCallback _Nullable)callback;


#pragma mark - 设置事件时间提醒间隔 [set Even Remind interval]
/*! @brief
获取设备事件时间提醒间隔（秒）[get Even Remind interval(second)]
@prram evenType HwEvenRemindType
@param callback 整型回调
@return 任务 task
*/
- (HwBluetoothTask *_Nullable) getEvenRemindIntervalByType:(HwEvenRemindType)evenType
                                     withCallback:(HwBCIntegerCallback _Nullable)callback;
/*! @brief
设置设备事件时间提醒间隔（秒）[set Even Remind interval(second)]
@prram evenType HwEvenRemindType
@prram span 间隔时间（s）
@param callback 整型回调
@return 任务 task
*/
- (HwBluetoothTask *_Nullable) setEvenRemindIntervalByType:(HwEvenRemindType)evenType
                                                 WithSpan:(NSInteger)span
                                                 callback:(HwBoolCallback _Nullable)callback;

#pragma mark - 勿打扰模式
- (HwBluetoothTask *_Nullable) getDontDisturbWithCallback:(HwDontDisturbCallback _Nullable)callback;
- (HwBluetoothTask *_Nullable) setDontDisturbModel:(HwDontDisturbModel *_Nonnull)model
                                 callback:(HwBoolCallback _Nullable)callback;
- (HwBluetoothTask *_Nullable) setDontDisturbState:(BOOL)state
                                startHour:(NSInteger)startHour
                                 startMin:(NSInteger)startMin
                                  endHour:(NSInteger)endHour
                                   endMin:(NSInteger)endMin
                                 callback:(HwBoolCallback _Nullable)callback;

#pragma mark - 寻找设备

/*! @brief
 开始寻找设备 [start searching device]
 
 @param callback 成功与否回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) searchDeviceWithCallback:(HwBoolCallback _Nullable)callback;

/*! @brief
 停止寻找设备 [stop searching device]
 
 @param callback 成功与否回调
 @return 任务 task
 */
- (HwBluetoothTask *_Nullable) stopSearchingDeviceWithCallback:(HwBoolCallback _Nullable)callback;


#pragma mark - 联系人
/*!
 发送一个联系人到设备端，如果当前只需要发送一条，用type = HwContactTypeOnlyOne
 phone 一定不能空
 
 @param phone 手机号码，不能空
 @param name 名称
 @param group 分组 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I'...
 @param type 类型，是第一个、中间的、最后一个，还是只有一个
 @param callback 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) sendContactWithPhone:(NSString *_Nullable)phone
                                              name:(NSString *_Nullable)name
                                             group:(unichar)group
                                              type:(HwContactType)type
                                          callback:(HwBoolCallback _Nullable)callback;

/*!
 发送联系人列表到设备端
 这里只是循环调用 sendContactWithPhone:name:group:type:callback
 具体的解释，可以参考它的注释
 
 @param contacts 联系人列表，数据结构：{@"name":@"xxxx", @"phone":@"xxxxxxxx", @"group":@"X"}
 @param callback bool 回调
 @return 任务
 */
- (HwBluetoothTask *_Nullable) sendContacts:(NSArray<NSDictionary *> *_Nonnull)contacts
                                   callback:(HwBCAddressBookCallback _Nullable)callback;


#pragma mark - 定义按键功能
- (HwBluetoothTask *_Nullable) setWatchButtonAction:(HwButtonAction)action
                                           forEvent:(HwButtonEvent)event
                                           callback:(HwBoolCallback _Nullable)callback;

- (HwBluetoothTask *_Nullable) setWatchButtonActions:(NSArray *_Nonnull)actions
                                             events:(NSArray *_Nullable)events
                                           callback:(HwBoolCallback _Nullable)callback;

- (HwBluetoothTask *_Nullable) getWatchButtonActionEventsWithCallback:(HwWatchButtonCallback _Nullable)callback;

#pragma mark - 操作设备

/// 主动点亮设备屏幕。可以设置点亮的持续时间，如果设备在点亮期间没有收到灭屏指令，持续时间一到就会灭屏。
/// @param seconds 点亮屏幕持续时间（长度只有两个字节，注意取值范围）
/// @param callback 回调
- (HwBluetoothTask *_Nullable) lightUpWatchScreenWithDuration:(unsigned short)seconds
                                                     callback:(HwBoolCallback _Nullable)callback;


#pragma mark - 机芯刻度通知内容

#pragma mark - 设置生理周期(0x33)
/// 设置生理周期
/// @param periods 想要传递的周期
/// @param callback 回调
- (HwBluetoothTask *_Nullable)setMenstrualPeriods:(NSArray<HwMenstrual *> *_Nonnull)periods
                                         callback:(HwBoolCallback _Nullable)callback;
#pragma mark - 设置生理期(0x32)
- (HwBluetoothTask *_Nullable)setNewMenstrualPeriods:(NSArray<HwMenstrual *> *_Nonnull)periods
                                            callback:(HwBoolCallback _Nullable)callback;




#pragma mark - 设备屏锁密码
- (HwBluetoothTask *_Nullable) setDevicePasscode:(NSString *_Nonnull)passcode
                                        callback:(HwBoolCallback _Nullable)callback;

- (HwBluetoothTask *_Nullable) clearDevicePasscodeWithCallback:(HwBoolCallback _Nullable)callback;

- (HwBluetoothTask *_Nullable) getDevicePasscodeWithCallback:(HwStringCallback _Nullable)callback;

#pragma mark - 设备数据
- (HwBluetoothTask *_Nullable) clearDeviceDataWithCallback:(HwBoolCallback _Nullable)callback;


- (HwBluetoothTask *) setContactWithContacts:(NSArray<HwContact *> *)contacts
                                    callback:(HwBoolCallback)callback;

@end


