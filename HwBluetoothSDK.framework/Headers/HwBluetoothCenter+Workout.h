//
//  HwBluetoothCenter+Workout.h
//  CocoaLumberjack
//
//  Created by sujiang on 2020/8/14.
//

#import "HwBluetoothCenter.h"
#import "HwWorkoutPoint.h"
#import "HwWorkout.h"

typedef void (^HwWorkoutCountCallback)(NSUInteger count, NSError *_Nullable error);
typedef void (^HwWorkoutsCallback)(NSArray<HwWorkout *> * _Nullable workouts, NSError * _Nullable error);
typedef void (^HwWorkoutPointsCallback)(NSArray<HwWorkoutPoint *> * _Nullable workoutPoints, NSError * _Nullable error);

@interface HwBluetoothCenter (Workout)


/*! @brief
 获取设备中的运动记录个数[gain the sport record number of the device]
 
 @param callback 运动记录个数回调[sport record number callback]
 @return 任务[task]
 */
- (HwBluetoothTask *_Nullable) getWorkoutCountWithCallback:(HwWorkoutCountCallback _Nullable )callback;

- (HwBluetoothTask *_Nullable) getWorkoutsWithCount:(NSUInteger)count callback:(HwWorkoutsCallback _Nullable)callback;

/*! @brief
 运动记录信息[sport record]
 
 @param callback 运动记录回调[HwWorkoutPoint callback]
 */
- (void) getWorkoutPointsWithCallback:(HwWorkoutPointsCallback _Nullable)callback;


/*! @brief
 删除运动记录[delete sport record]
 
 @param callback 回调[call back]
 @return 任务[task]
 */
- (HwBluetoothTask *_Nullable) deleteWorkoutWithCallback:(HwBoolCallback _Nullable )callback;

@end

