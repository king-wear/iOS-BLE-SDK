//
//  HwWorkout.h
//  HwBluetoothSDK
//
//  Created by HuaWo on 2022/1/17.
//

#import <Foundation/Foundation.h>
#import "HwTimeSection.h"

NS_ASSUME_NONNULL_BEGIN

/**
 运动类型枚举
 Sport type enum
 
 - HwWorkoutTypeOther: unknow
 - HwWorkoutTypeWalk: walking
 - HwWorkoutTypeRun: running
 - HwWorkoutTypeSitUp: sit and up
 - HwWorkoutTypeSwin: swin
 - HwWorkoutTypeRide: riding
 - HwWorkoutTypeClimbStairs: climb stairs
 - HwWorkoutTypeClimbMountains: climb mountain
 - HwWorkoutTypeStand: stand
 - HwWorkoutTypeSit: sit
 - HwWorkoutTypeRideIndoor: RideIndoor
 - HwWorkoutTypeWeights: Weights
 - HwWorkoutTypeAerobics: Aerobics
 - HwWorkoutTypeIndoorWalk: IndoorWalk
 - HwWorkoutTypeIndoorRun: IndoorRun
 - HwWorkoutTypeYoga: Yoga
 - HwWorkoutTypeStrengthTraining: StrengthTraining
 - HwWorkoutTypeElliptical: elliptical trainer
 - HwWorkoutTypeStairStepper: Stair Stepper
 - HwWorkoutTypeDance: Dance
 - HwWorkoutTypeBadminton: Badminton
 - HwWorkoutTypeBasketball: Basketball
 - HwWorkoutTypeFreeTraining: Free Training
 */
typedef NS_ENUM(NSInteger, HwWorkoutType)
{
    HwWorkoutTypeOther = 0,
    HwWorkoutTypeWalk = 1,
    HwWorkoutTypeRun = 2,
    HwWorkoutTypeSettingupExercise = 3,
    HwWorkoutTypeSwin = 4,
    HwWorkoutTypeRide = 5,
    HwWorkoutTypeClimbStairs = 6,
    HwWorkoutTypeClimbMountains = 7,
    HwWorkoutTypeStand = 8,
    HwWorkoutTypeSit = 9,
    HwWorkoutTypeRideIndoor = 10,
    HwWorkoutTypeWeights = 11,
    HwWorkoutTypeAerobics = 12,
    HwWorkoutTypeIndoorWalk = 13,
    HwWorkoutTypeIndoorRun = 14,
    HwWorkoutTypeYoga = 15,
    HwWorkoutTypeStrengthTraining = 16,
    HwWorkoutTypeElliptical = 17,
    HwWorkoutTypeStairStepper = 18,
    HwWorkoutTypeDance = 19,
    HwWorkoutTypeBadminton = 20,
    HwWorkoutTypeBasketball = 21,
    HwWorkoutTypeFreeTraining = 22,
    HwWorkoutTypeHiking = 23,  // 徒步
    HwWorkoutTypeOutdoorRun = 24, //野外跑,
    HwWorkoutTypeRowingMachine = 25,
    HwWorkoutTypeClimbing = 26,
    HwWorkoutTypeFootball = 27,
    HwWorkoutTypePingPong = 28,
    HwWorkoutTypeRugby = 29,
    HwWorkoutTypeTennis = 30,
    HwWorkoutTypeVolleyBall = 31,
    HwWorkoutTypeWrestling = 32,
    HwWorkoutTypeBoxing = 33,
    HwWorkoutTypePilates = 34,
    HwWorkoutTypeHiphop = 35,
    HwWorkoutTypeGolf = 36,
    HwWorkoutTypeSurfing = 37,
    HwWorkoutTypeGanoeing = 38,
    HwWorkoutTypeIceSkating = 39,
    HwWorkoutTypeTreadmill = 40,
    HwWorkoutTypeHunting = 41,
    HwWorkoutTypeFishing = 42,
    HwWorkoutTypeSkateboarding = 43,
    HwWorkoutTypeKarate = 44,
    HwWorkoutTypeRopeSkipping = 45,
    HwWorkoutTypeCricket = 46,
    HwWorkoutTypeStretching = 47,
    HwWorkoutTypeJudo = 48,
    HwWorkoutTypeMartialArt = 49,
    HwWorkoutTypeGymnastic = 50,//体操
    HwWorkoutTypeSitupExercise = 51,//仰卧起坐
    HwWorkoutTypeRaceWalking,
    HwWorkoutTypeMarathon,
    HwWorkoutTypeUnicycle,
    HwWorkoutTypeBmx,
    HwWorkoutTypeRollerSkating,
    HwWorkoutTypeAbRolling,
    HwWorkoutTypeWalkingMachine,
    HwWorkoutTypeHulaHoop,
    HwWorkoutTypeDarts,
    HwWorkoutTypeBaseball,
    HwWorkoutTypeBilliard,
    HwWorkoutTypeShuttlecock,
    HwWorkoutTypePolo,
    HwWorkoutTypeSquash,
    HwWorkoutTypeBowling,
    HwWorkoutTypeGymBall,
    HwWorkoutTypeHockey,
    HwWorkoutTypeBallet,
    HwWorkoutTypeQuickstep,
    HwWorkoutTypeJive,
    HwWorkoutTypeBellyDance,
    HwWorkoutTypeTango,
    HwWorkoutTypeSharping,
    HwWorkoutTypePoleDance,
    HwWorkoutTypeChaCha,
    HwWorkoutTypeRumba,
    HwWorkoutTypeJazz,
    HwWorkoutTypeSamba,
    HwWorkoutTypePasoDoble,
    HwWorkoutTypeWalta,
    HwWorkoutTypeMuayThai,
    HwWorkoutTypeTaekwondo,
    HwWorkoutTypefreeFight,
    HwWorkoutTypeSanda,
    HwWorkoutTypeJeetKuneDo,
    HwWorkoutTypeMma,
    HwWorkoutTypeKickboxing,
    HwWorkoutTypeTaiChi,
    HwWorkoutTypeSambo,
    HwWorkoutTypeMulanquan,
    HwWorkoutTypeSumo,
    HwWorkoutTypeAikido,
    HwWorkoutTypeFrisbee,
    HwWorkoutTypeGliding,
    HwWorkoutTypeTugOfWar,
    HwWorkoutTypeHotAirBalloon,
    HwWorkoutTypeParkour,
    HwWorkoutTypeCarRace,
    HwWorkoutTypeSailing,
    HwWorkoutTypeMotorcycleRace,
    HwWorkoutTypeExplore,
    HwWorkoutTypeMotorboat,
    HwWorkoutTypeDrift,
    HwWorkoutTypeRowing,
    HwWorkoutTypeBungee,
    HwWorkoutTypeParachuting,
    HwWorkoutTypeHorseRace
};


@class HwWorkoutPoint;
@interface HwWorkout : NSObject

/*! @brief
 索引[index]
 */
@property(nonatomic, assign) NSUInteger index;


/*! @brief
 时间点（毫秒级时间戳）[interval time, milli seconds]
 */
@property(nonatomic, assign) long startTime;

/*! @brief
 时间点（毫秒级时间戳）[interval time, milli seconds]
 */
@property(nonatomic, assign) long endTime;

/*! @brief
 Record the workout pause period
 */
@property(nonatomic, copy) NSArray *pausedTimeSections;

/*! @brief
 运动类型[workout type]
 */
@property(nonatomic, assign) HwWorkoutType type;

/*! @brief
 步数[step]
 */
@property(nonatomic, assign) NSUInteger step;
/*! @brief
 卡路里[calorie]
 */
@property(nonatomic, assign) NSUInteger calorie;
/*! @brief
 距离[distance]
 */
@property(nonatomic, assign) NSUInteger distance;
/*! @brief
 运动时间[integer duration]
 */
@property(nonatomic, assign) NSUInteger duration;

/*! @brief
 average heartRate bpm for this moment
 */
@property(nonatomic, assign) NSUInteger bpm;

@property(nonatomic, assign) NSUInteger maxBpm;
@property(nonatomic, assign) NSUInteger minBpm;

@property(nonatomic, assign) NSUInteger pace;            // 秒/千米
@property(nonatomic, assign) NSUInteger speed;           // 千米/小时
@property(nonatomic, assign) NSUInteger lapDuration;      // 一圈要多少分钟

//多运动
@property(nonatomic, assign) NSUInteger warmUpTime;   //多运动的
@property(nonatomic, assign) NSUInteger burningDuration;
@property(nonatomic, assign) NSUInteger aerobicDuration;
@property(nonatomic, assign) NSUInteger anaerobicDuration;
@property(nonatomic, assign) NSUInteger limitDuration;

@property(nonatomic, strong) NSArray<HwWorkoutPoint *> *workoutPoints;

- (HwWorkout *) initWithData:(NSData *)data;


@end

NS_ASSUME_NONNULL_END
