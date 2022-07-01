//
//  HwActivity.h
//  Pods
//
//  Created by HuaWo on 2022/6/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class HwActivity
 @brief 运动数据模型[sport data models]
 */
@interface HwActivity : NSObject
/*! @brief
 索引[index]
 */
@property(nonatomic, assign) NSUInteger index;

/*! @brief
 时间点（秒级时间戳）[interval time]
 */
@property(nonatomic, assign) NSTimeInterval time;
/*! @brief
 步数[step]
 */
@property(nonatomic, assign) NSUInteger step;
/*! @brief
 卡路里[calorie]
 */
@property(nonatomic, assign) NSUInteger calorie;
/*! @brief
 静态卡路里[staticCalorie]
 */
@property(nonatomic, assign) NSUInteger staticCalorie;
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
@property(nonatomic, assign) NSUInteger avgBpm;

@end

NS_ASSUME_NONNULL_END
