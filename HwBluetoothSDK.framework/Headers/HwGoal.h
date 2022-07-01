//
//  HwGoal.h
//  HwBluetoothSDK
//
//  Created by HuaWo on 2022/2/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class HwGoal
 @brief 目标数据模型 [target data models]
 */
@interface HwGoal : NSObject

/*! @brief
 步数（步）[steps(step)]
 */
@property(nonatomic, assign) NSInteger step;            // 步数[steps]
/*! @brief
 距离（米）[Distance(meter)]
 */
@property(nonatomic, assign) NSInteger distance;        // 距离[Distance]
/*! @brief
 卡路里（卡）[Calorie]
 */
@property(nonatomic, assign) NSInteger calorie;         // 卡[calorie]
/*! @brief
 睡眠（分钟）[sleep]
 */
@property(nonatomic, assign) NSInteger sleep;           // 分种[minute]
/*! @brief
 运动时间（分钟）[movement time]
 */
@property(nonatomic, assign) NSInteger duration;        // 分种[minute]

@end

NS_ASSUME_NONNULL_END
