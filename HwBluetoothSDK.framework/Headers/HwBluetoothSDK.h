/*!
 @header HwBluetoothCenter.h
 
 @author sujiang on 2018/5/23.
 @copyright  2021年 huawo. All rights reserved.
 */
#import "HwBluetoothCenter+Utils.h"
#import "HwBluetoothCenter+Sport.h"
#import "HwBluetoothCenter+Device.h"
#import "HwBluetoothCenter+User.h"
#import "HwBluetoothCenter+Ota.h"
#import "HwBluetoothCenter+Expand.h"
#import "HwBluetoothCenter+StatusSetting.h"
#import "HwBluetoothCenter+WorkoutTrack.h"
#import "HwBluetoothCenter+WatchFace.h"
#import "HwBluetoothCenter+Workout.h"
#import "HwBluetoothCenter+Customize.h"
#import "HwBluetoothCenter+Unit.h"
#import "HwCommonDefines.h"
#import "HwHeartrateFatigue.h"
#import "HwHeartrateAlarm.h"
#import "HwCustomWatchface.h"
#import "HwSedentaryReminder.h"
#import "HwLanguageUtil.h"
#import "HwUserInfo.h"
#import "HwSleep.h"
#import "HwWorldClockCity.h"

#define HwBluetoothSDK_Version @"3.2.7"

/**
 # BLE SDK
 ## Setup:
 Each API in the SDK, except for static methods, needs to be called through a single instance. Do not create an instance yourself. Otherwise, SDK status may be wrong.
 1. Init the SDK: [[HwBluetoothSDK sharedInstance] initSDK];
 2. When you no longer need to use the SDK, call 'destroySDK'.
 3. Get SDK version by call 'version'.
 
 We recommend initializing the SDK when the app is started, for example, in the method 'didFinishLaunchingWithOptions'
 and destroy the SDK when the app terminated.
 
 
 ## Connection:
 # The Bluetooth connection is only valid when the Bluetooth status is available (power on).
 ## Bluetooth Status:
 You can monitor Bluetooth status by 'addBluetoothStateChangedCallback'
 @example
 [[HwBluetoothSDK sharedInstance] addBluetoothStateChangedCallback:^(HwBluetoothState state) {
     if (state == HwBluetoothStateAvailable) {
        // Connect your watch.
     } else {
        
     }
 }];
 
 ## How to connect my watch?
 1. You can make a ble connection by calling 'connectWithBleName' to pass in the Bluetooth name of the watch.
 2. Or you can call 'connectWithDevice' with the device returned by 'scanDevicesWithCallback' API.
 3. You can monitor Bluetooth connection status by 'addBluetoothConnectionStateChangedCallback'
 4. 'connected' Get bluetooth connection status
 5. 'getPhoneConnectedDevices' Get the connected devices in the Bluetooth settings of the mobile phone.
 
 ## After connected, you can call any APIs to read/write data.
 
 */
@interface HwBluetoothSDK : NSObject

+ (HwBluetoothSDK *_Nonnull) sharedInstance;

#pragma mark - SDK init
/**
 Initialize the SDK. The SDK initializes some parameters and statuses and starts listening for status changes.
 */
- (void) initSDK;
/**
 Destroy recovered data and stop listening for status changes.
 */
- (void) destroySDK;

/**
 Get SDK version.
 */
- (NSString *_Nonnull) version;

#pragma mark - iPhone Bluetooth
/**
 
 */
- (void) addBluetoothStateChangedCallback:(HwBluetoothStateChangedCallback _Nonnull)callback;
/**
 
 */
- (void) removeBluetoothStateChangedCallback:(HwBluetoothStateChangedCallback _Nonnull)callback;

- (void) addBluetoothConnectionStateChangedCallback:(HwBluetoothConnectionStateChangedCallback _Nonnull)callback;
- (void) removeBluetoothConnectionStateChangedCallback:(HwBluetoothConnectionStateChangedCallback _Nonnull)callback;

- (BOOL) connected;

/*!
 @brief Scan the surrounding ble devices, and the returned results include the paired devices of the mobile phone
 
 @param callback Every time the device is scanned, it will be adjusted back
 @param second Scan timeout
 @param stopCallback Stop callback
 */
- (void) scanWithCallback:(HwSearchDevicesCallback _Nonnull)callback
                stopAfter:(NSTimeInterval)second
             stopCallback:(HwStopSearchingDevicesCallback _Nonnull)stopCallback;

/*!
 @brief Connect watch by Bluetooth name
 
 @param bleName name
 @param callback callback
 */
- (void) connectWithBleName:(NSString *_Nonnull)bleName
                   callback:(HwConnectCallback _Nonnull)callback;

- (void) connectWithBleName:(NSString *_Nonnull)bleName
                    timeout:(NSInteger)timeoutSeconds
                   callback:(HwConnectCallback _Nullable)callback;

- (void) connectWithDevice:(HwBluetoothDevice *_Nonnull)device
                  callback:(HwConnectCallback _Nullable)callback;


- (void) connectWithDevice:(HwBluetoothDevice *_Nonnull)device
                   timeout:(NSInteger)timeoutSeconds
                  callback:(HwConnectCallback _Nullable)callback;

/**
 Disconnect the watch's BLE. If the watch has been paired with the phone, the BLE cannot be disconnected after this method is called.
 */
- (void) disconnectWithCallback:(HwConnectCallback _Nullable)callback;

/**
 Get the paired and connected watchs on the phone
 */
- (NSArray<HwBluetoothDevice *> *_Nullable) getPhoneConnectedDevices;

/*!
 @brief Clear up device connection info
 */
- (void) removeConnectionCache;

/**
 Cancel all ble task in the queue
 */
- (void) cancelAllBluetoothTasks;

#pragma mark - 业务APIs
#pragma mark - 设备相关
#pragma mark - 手表基本信息 basic info about watch

/*! @brief
 Get the ID and unique identification of the device
 
 @param callback string callback
 
 */
- (void) getDeviceIdWithCallback:(HwStringCallback _Nullable)callback;

/*! @brief
 Get Mac address of the watch

 @param callback string callback

*/
- (void) getDeviceMacAddressWithCallback:(HwStringCallback _Nullable)callback;

/*! @brief
 Get firmware version.
 This API will return a string, similar to:
 V1.0.0R0.1T0.5H0.0B20.
 
 R0.1: the picture lib version is 0.1
 T0.5: the touch driver version is 0.5
 V1.0.0: the version of the firmware is 1.0.0
 B20: the build of the firmware is 20
 
 How to compare firmware version numbers:
 Step1: Compare the V version number;
 Step2: Compare the B build version;
 Step3: Compare the R version number.
 
 In general, the T version number is never updated, only for development.
 
 @param callback string
 */
- (void) getFirmwareVersionWithCallback:(HwStringCallback _Nullable)callback;

/*! @brief
 Get device type(Watch model)
 
 @param callback string
 
 */
- (void) getDeviceTypeWithCallback:(HwStringCallback _Nullable)callback;

/*! @brief
Start to bind with watch
 
 @param callback bool回调
 
 */
- (void) startBindDeviceWithCallback:(HwBoolCallback _Nullable)callback;


/*! @brief
 Start to bind with watch using QRCODE
 
 @param callback bool
 
 */
- (void) startQRBindDeviceWithCallback:(HwBoolCallback _Nullable)callback;

/*! @brief
 End binding
 
 @param callback bool
 
 */
- (void) endBindDeviceWithCallback:(HwBoolCallback _Nullable)callback;

/*! @brief
 Get bind state of device

 @param callback bindState
 
 */
- (void) getBindStateWithCallback:(void(^_Nonnull)(HwBindState bindState, NSError * _Nullable error))callback;

/*! @brief
 Set time to device
 
 @param time 时间
 @param callback bool回调
 
 */
- (void) setDeviceTime:(NSDate *_Nonnull)time
              callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 Get time from device
 
 @param callback HwDateCallback
 
 */
- (void) getDeviceTimeWithCallback:(HwDateCallback _Nullable)callback;

/*! @brief
 Restart the watch
 
 @param callback bool
 
 */
- (void) restartDeviceWithCallback:(HwBoolCallback _Nullable)callback;

/**
 Unbind the watch
 @param callback bool回调
 */
- (void) unbindDeviceWithCallback:(HwBoolCallback _Nullable)callback;

/**
 查询BT开关状态
 */
- (void)getBtSwitchWithCallback:(HwBoolCallback _Nullable)callback;

/**
 设置BT开关
 */
- (void)setBtSwitch:(BOOL)on callback:(HwBoolCallback _Nullable)callback;

/**
 Find watch
 */
- (void) findDeviceWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - World clock
- (void) setWorldClockCities:(NSArray<HwWorldClockCity *> *_Nonnull)cities
                    callback:(HwBoolCallback _Nullable)callback;
- (void) addWorldClockCity:(HwWorldClockCity *_Nonnull)city
                  callback:(HwBoolCallback _Nullable)callback;
- (void) getWorldClockCitiesWithCallback:(void(^_Nonnull)(NSArray<HwWorldClockCity *> *_Nullable cities, NSError * _Nullable error))callback;
- (void) delWorldClockCityById:(NSInteger)Id
                      callback:(HwBoolCallback _Nullable)callback;

#pragma mark - 手表设置 [watch setting]

/*! @brief
 Reset the watch. After resetting, the watch will restart and return to the factory settings.
 
 @param callback bool
 
 */
- (void) resetDeviceWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - 亮度 [brightness]

/*! @brief
 Set the watch screen brightness. The brightness value range is 1 to 5. The larger the value, the brighter the screen.
 
 @param value 0 ～ 100
 @param callback bool
 
 */
- (void) setBrightnessValue:(NSInteger)value callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 Get the watch screen brightness. The brightness value range is 1 to 5. The larger the value, the brighter the screen.
 
 @param callback integer
 
 */
- (void) getBrightnessValueWithCallback:(HwBCIntegerCallback _Nullable )callback;

#pragma mark - 语言 [language]

/*! @brief
 设置手表的语言类型 [set language of device]
 
 @param language 语言类型
 @param callback bool回调
 
 */
- (void) setLanguage:(HwLanguage)language callback:(HwBoolCallback _Nullable )callback;

/*! @brief
 获取语言类型 [get language type]
 
 @param callback 语言类型回调
 
 */
- (void) getLanguageWithCallback:(HwLanguageCallback _Nullable )callback;

#pragma mark - watch time face style

- (void) setCurrentWatchfaceByIndex:(NSInteger)index
                           callback:(HwBoolCallback _Nullable )callback;
- (void) getCurrentWatchfaceIndexWithCallback:(HwBCIntegerCallback _Nullable)callback;

#pragma mark - 自定义表盘 [custom watch face]
- (void) otaCustomWatchface:(HwCustomWatchface *_Nonnull)customWatchface
           progressCallback:(void(^_Nullable)(float f))progressCallback
             finishCallback:(void(^_Nullable)(BOOL b, NSError * _Nullable error))finishCallback;

- (void) otaOnlineWatchface:(NSData *_Nonnull)binData
           progressCallback:(void(^_Nullable)(float f))progressCallback
             finishCallback:(void(^_Nullable)(BOOL b, NSError * _Nullable error))finishCallback;

#pragma mark - weather

- (void) setWeatherInfoWithCity:(NSString *_Nonnull)city
                    weatherInfo:(HwWeatherInfo *_Nonnull)weatherInfo
                       forecast:(NSArray<HwWeatherInfo *> *_Nullable)forecasts
                       callback:(HwBoolCallback _Nullable)callback;

- (void) getWeatherUnitWithCallback:(void(^_Nullable)(HwWeatherUnit unit, NSError * _Nullable error))callback;

- (void) setWeatherUnit:(HwWeatherUnit)unit
               callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 获取系统的语言类型（非蓝牙指令）[get system language]
 
 @return 语言类型
 */
- (HwLanguage) getSystemLanguageValue;

#pragma mark - 手机匹配弹框操作
//查询匹配的状态
- (void) getPairStateWithCallback:(HwBoolCallback _Nullable)callback;
//设置
- (void) requestDeviceToPairWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - 获取BT连接状态
- (void) getBtConnectionStateWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - power
/*! @brief
 获取设备电量 [get device battery volumn]
 
 @param callback 回调0-100
 
 */
- (void) getBatteryWithCallback:(HwBCIntegerCallback _Nullable)callback;

/*! @brief
 Get the timeout time of device screen lightening.
 The value of the callback is in seconds.
 
 @param callback 回调
 
 */
- (void) getScreenOnDurationWithCallback:(HwBCIntegerCallback _Nullable)callback;

/**
 Set the timeout time of device screen lightening.
 We recommend the timeout length of 5 seconds, 10 seconds, 15 seconds, 30 seconds, 45 seconds and 60 seconds.
 
 @param second second
 @param callback callback
 */
- (void) setScreenOnDuration:(NSInteger)second
                    callback:(HwBoolCallback _Nullable)callback;


#pragma mark - 设置生理周期(0x33)
/// 设置生理周期
/// @param periods 想要传递的周期
/// @param callback 回调
- (void)setMenstrualPeriods:(NSArray<HwMenstrual *> *_Nonnull)periods
                   callback:(HwBoolCallback _Nullable)callback;
#pragma mark - 设置生理期(0x32)
- (void)setNewMenstrualPeriods:(NSArray<HwMenstrual *> *_Nonnull)periods
                      callback:(HwBoolCallback _Nullable)callback;


#pragma mark - 设备屏锁密码
/**
 Set device's passcode
 */
- (void) setDevicePasscode:(NSString *_Nonnull)passcode
                  callback:(HwBoolCallback _Nullable)callback;

/**
 Delete watch's passcode
 */
- (void) delDevicePasscodeWithCallback:(HwBoolCallback _Nullable)callback;

/**
 Get watch's passcode
 */
- (void) getDevicePasscodeWithCallback:(HwStringCallback _Nullable)callback;

#pragma mark - 设备数据
/**
 Delete all activity/sleep/heartrate/hrv data on watch
 */
- (void) deleteDeviceDataWithCallback:(HwBoolCallback _Nullable)callback;

/**
 Set contacts to watch
 */
- (void) setContacts:(NSArray<HwContact *> *_Nullable)contacts
            callback:(HwBoolCallback _Nullable)callback;


#pragma mark - 运动相关APIs
#pragma mark - goal 目标[goal]
/*! @brief
 设置目标值[set goal value]
 
 @param type 类型[type]
 @param goal 目标值[gole]
 @param callback 回调[callback]
 
 */
- (void) setGoalWithType:(HwGoalType)type
                    goal:(NSInteger)goal
                callback:(HwBoolCallback _Nullable )callback;

/*! @brief
 获取目标值[gain goal value]
 
 @param callback 数据模型回调[data models callback]
 
 */
- (void) getGoalWithCallback:(HwGoalInfoCallback _Nullable )callback;


#pragma mark - Health data
/*! @brief
 Get the number of health data in the watch,
 including: number of activity data, number of heart rate data, number of sleep data, number of blood oxygen data, number of pressure data
 */
- (void) getHealthDataCountWithCallback:(HwHealthDataCountCallback _Nullable)callback;

/*! @brief
 Get the activity data (steps, calories, distance and exercise duration) of the health data in the watch, the number of activity data to be passed in is returned by the interface 'getHealthDataCountWithCallback'.
 
 @param activityCount number of activity data, returned by API 'getHealthDataCountWithCallback'
 */
- (void) getActivities:(NSUInteger)activityCount callback:(HwActivitiesCallback _Nullable)callback;

/*! @brief
 Delete the activity data.
 After getting the data, it should be called once to ensure that there is not too much data left in the watch. The next time getting the data, it will not obtain the old data, so as to improve the speed of getting the data. 
 */
- (void) deleteActivitiesWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - sleep

typedef void (^HwSleepsCallback)(NSArray<HwSleep *> * _Nullable sleeps, NSError *_Nullable error);
/*! @brief
 Get the sleep data of the health data in the watch, the number of sleep point data to be passed in is returned by the interface 'getHealthDataCountWithCallback'.
 
 @param sleepPointCount number of sleep point data, returned by API 'getHealthDataCountWithCallback'
 */
- (void) getSleeps:(NSUInteger)sleepPointCount callback:(HwSleepsCallback _Nonnull)callback;

/*! @brief
 Delete the sleep data.
 After getting the data, it should be called once to ensure that there is not too much data left in the watch. The next time getting the data, it will not obtain the old data, so as to improve the speed of getting the data.
 
 */
- (void) deleteSleepsWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - SedentaryReminder
typedef void (^HwSedentaryReminderCallback)(HwSedentaryReminder *_Nullable reminder, NSError *_Nullable error);

/*! @brief
 Get sedentary reminder config to the device
 
 @param callback callback
 */
- (void) getSedentaryReminderWithCallback:(HwSedentaryReminderCallback _Nonnull)callback;

/**
 * Set sedentary reminder config to the device
 *
 * @param reminder SedentaryReminder config
 * @param callback BoolCallback
 */
- (void) setSedentaryReminder:(HwSedentaryReminder *_Nonnull)reminder
                     callback:(HwBoolCallback _Nullable)callback;


#pragma mark - hearRate
/*! @brief
 Get the heart rate data of the health data in the watch, the number of sleep point data to be passed in is returned by the interface 'getHealthDataCountWithCallback'.
 
 @param count number of heart rate data, returned by API 'getHealthDataCountWithCallback'
 */
- (void) getHeartrates:(NSUInteger)count callback:(HwHeartRateInfoArrayCallback _Nullable)callback;

/*! @brief
 Delete the heart rate data.
 After getting the data, it should be called once to ensure that there is not too much data left in the watch. The next time getting the data, it will not obtain the old data, so as to improve the speed of getting the data.
 */
- (void) deleteHeartratesWithCallback:(HwBoolCallback _Nullable)callback;

typedef void (^HwHeartrateFatiguesCallback)(NSArray<HwHeartrateFatigue *> *_Nullable heartrateFatigues, NSError *_Nullable error);
/**
 根据心率疲劳度个数获取设备中的心率疲劳度详情[get the heartrate fatigue detail based on the heartrate fatigue numbers]
 
 @param count 心率疲劳度个数[heartrate fatigue numbers]
 @param callback 详情回调[detail callback]
 */
- (void) getHeartrateFatigues:(NSUInteger)count callback:(HwHeartrateFatiguesCallback _Nullable)callback;

/**
 删除心率疲劳度详情[delete heartrate fatigue detail]
 
 @param callback 成功与否回调[callback successfully or not]
 */
- (void) deleteHeartrateFatiguesWithCallback:(HwBoolCallback _Nullable)callback;

/*! @brief
 设置手表自动检测心率时间间隔[set the time span of the heartrate auto-check]
 
 @param interval 每隔多少分钟产生一笔心率数据，有效值有：0、5、10、15、30、45、60[how often a new heartrate will be produced, effective value: 0 ,5,10,15,30,45,60]
 其中0表示关闭['0' is off]
 @param callback 回调[callback]
 */
- (void) setHeartrateMonitoringInterval:(int)interval
                               callback:(HwBoolCallback _Nullable)callback;

/*! @brief
 Heart rate monitoring interval
 回调中的整型单位是分种[unit of callback is minute]
 @param callback 回调(NSInteger, NSError)
 */
- (void) getHeartrateMonitoringIntervalWithCallback:(HwBCIntegerCallback _Nullable)callback;

typedef void (^HwHeartrateAlarmCallback)(HwHeartrateAlarm *_Nullable hrAlarm, NSError *_Nullable error);
/*! @brief
 Get the heart rate alarm configuration of the watch
 
 @param callback 回调[callback]
 
 */
- (void) getHeartrateAlarmWithCallback:(HwHeartrateAlarmCallback _Nullable)callback;


/*! @brief
 Set the heart rate alarm configuration of the watch
 @param hrAlarm config
 @param callback callback
 */
- (void) setHeartrateAlarm:(HwHeartrateAlarm *_Nonnull)hrAlarm
                  callback:(HwBoolCallback _Nullable)callback;


/*! @brief
 Get automatic stress monitoring switch
 @param callback callback
 
 */
- (void) getStressMonitorEnableWithCallback:(HwBoolCallback _Nullable)callback;

/*! @brief
 Set automatic stress monitoring switch
 
 @param on switch status
 @param callback callback
 */
- (void) setStressMonitorEnable:(BOOL)on
                       callback:(HwBoolCallback _Nullable)callback;


#pragma mark - 用户相关API接口[API port]
#pragma mark - 用户信息[user's information]
/*! @brief
 设置个人信息[set personal details]
 
 gender 性别 0 --> 男、1 --> 女[gender]
 age 年龄（设备上默认的单位：岁）[age]
 height 身高（设备上默认的单位：cm）[height(default unit is cm)]
 weight 体重（设备上默认的单位：0.1KG）[weight(default unit is kg)]
 */
- (void) setUserInfo:(HwUserInfo *_Nonnull)userInfo
            callback:(HwBoolCallback _Nullable)callback;

#pragma mark - 用户习惯[user's habit]
/*! @brief
 获取用户带手表的习惯（左右手）[get user's habit of wearing watches]
 
 @param callback 回调[callback]
 */
- (void) getUserHandHabitWithCallback:(HwBCHandHabitCallback _Nonnull)callback;

/*! @brief
 设置用户带手表习惯[set user's habit of wearing watches]
 
 @param handHabit 左右手[handHabit]
 @param callback 回调[callback]
 */
- (void) setUserHandHabit:(HwHandHabit)handHabit
                 callback:(HwBoolCallback _Nullable)callback;

- (void) getHandwashingConfigWithCallback:(HwHandwashingConfigCallback _Nonnull)callback;

- (void) setHandwashingConfig:(HwHandwashingConfig *_Nonnull)config
                     callback:(HwBoolCallback _Nullable)callback;


- (void) getDrinkWaterConfigWithCallback:(HwDrinkWaterConfigCallback _Nonnull)callback;

- (void) setDrinkWaterConfig:(HwDrinkWaterConfig *_Nonnull)config
                    callback:(HwBoolCallback _Nullable)callback;

#pragma mark - Workout APIs
- (void) getWorkoutsWithCallback:(HwWorkoutsCallback _Nullable)callback;

/*! @brief
 删除运动记录[delete sport record]
 
 @param callback 回调[call back]
 */
- (void) deleteWorkoutsWithCallback:(HwBoolCallback _Nullable )callback;

#pragma mark - 状态设置 APIs
- (void) getFeatureSwitchesWithCallback:(HwFeatureSwitchCallback _Nonnull)callback;

- (void) setFeatureSwitchWithType:(HwFeatureSwitchType)type
                                S:(BOOL)S
                         callback:(HwBoolCallback _Nullable)callback;

- (void) getFeatureSwitchStateOfType:(HwFeatureSwitchType)type
                            callback:(HwBoolCallback _Nullable)callback;
// 如果没有传，默认是关闭[if it is not spread, default is off]
- (void) setAllFeatureSwitches:(NSArray<HwFeatureSwitch *> *_Nonnull)models
                      callback:(HwBoolCallback _Nullable)callback;

#pragma mark - social switch
- (void) getSocialSwitchesWithCallback:(HwSocialSwitchesCallback _Nonnull)callback;

- (void) setSocialSwitchWithType:(HwSocialSwitchType)type
                               S:(BOOL)S
                        callback:(HwBoolCallback _Nullable)callback;

- (void) setSocialSwitch:(HwSocialSwitch *_Nonnull)ss
                callback:(HwBoolCallback _Nullable)callback;

- (void) setSocialSwitches:(NSArray<HwSocialSwitch *> *_Nonnull)models
                  callback:(HwBoolCallback _Nullable)callback;

- (void) setSocialApps:(NSArray<HwSocialApp *> *_Nonnull)socialApps
      progressCallback:(HwBCFloatCallback _Nonnull)progressCallback
        finishCallback:(HwBoolCallback _Nonnull)finishCallback;

- (void) getSocialAppsWithCallback:(HwSocialAppsCallback _Nonnull)callback;

#pragma mark - Reminder
- (void) getRemindersWithCallback:(HwRemindersCallback _Nonnull)callback;
- (void) getAvailableReminderIdWithCallback:(HwBCIntegerCallback _Nonnull)callback;

- (void) addReminder:(HwReminder *_Nonnull)reminder
            callback:(HwBoolCallback _Nullable)callback;

- (void) updateReminder:(HwReminder *_Nonnull)reminder
               callback:(HwBoolCallback _Nullable)callback;

- (void) deleteReminderByID:(NSUInteger)Id
                   callback:(HwBoolCallback _Nullable)callback;

- (void) deleteRemindersWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - Alarms
- (void) getAlarmsWithCallback:(HwAlarmsCallback _Nonnull)callback;
- (void) getAvailableAlarmIdWithCallback:(HwBCIntegerCallback _Nonnull)callback;

- (void) addAlarm:(HwAlarm *_Nonnull)alarm
         callback:(HwBoolCallback _Nullable)callback;

- (void) updateAlarm:(HwAlarm *_Nonnull)alarm
            callback:(HwBoolCallback _Nullable)callback;

- (void) deleteAlarmByID:(NSUInteger)Id
                callback:(HwBoolCallback _Nullable)callback;

- (void) deleteAlarmsWithCallback:(HwBoolCallback _Nullable)callback;

#pragma mark - Events
/**
 After clicking on the watch to find my phone, the watch will send instructions to the app. After receiving the instructions, the app will respond to the watch with 'acceptedFindMyPhoneRequest', which has received the instructions, and then carry out its own business operations
 */
- (void) addFindMyPhoneCallback:(HwSearchPhoneCallback _Nonnull)callback;
- (void) removeFindMyPhoneCallback:(HwSearchPhoneCallback _Nonnull)callback;
- (void) removeAllFindMyPhoneCallbacks;
- (void) acceptedFindMyPhoneRequest;

/**
 The equipment regularly sends events to the app, which can be processed or ignored by the app, depending on the specific requirements
 
 @param callback 回调
 */
- (void) addDeviceEventCallback:(HwDeviceEventCallback _Nonnull)callback;
- (void) removeDeviceEventCallback:(HwDeviceEventCallback _Nonnull)callback;
- (void) removeAllDeviceEventCallbacks;

typedef void (^HwBtConnectionStateCallback)(BOOL connected);
/**
 In BLE and BT single-chip watches, the iPhone (ios13 or later) will automatically connect to BT after being paired with BLE.
 Due to the bug of the iPhone itself, sometimes the BT connection fails. At this time, the firmware will notify the app. From the product point of view, the app needs to prompt the user to go to the Bluetooth settings of the mobile phone and click the name of the paired watch.
 */
- (void) addBtConnectionStateCallback:(HwBtConnectionStateCallback _Nonnull)callback;
- (void) removeBtConnectionStateCallback:(HwBtConnectionStateCallback _Nonnull)callback;
- (void) removeAllBtConnectionStateCallbacks;

/**
 If the pairing request between the watch and the mobile phone is initiated by the mobile phone, the device will notify the app after the pairing is completed
 */
- (void) addDevicePairStateCallback:(HwDevicePairStateCallback _Nonnull)callback;
- (void) removeDevicePairStateCallback:(HwDevicePairStateCallback _Nonnull)callback;
- (void) removeAllDevicePairStateCallbacks;


@end


