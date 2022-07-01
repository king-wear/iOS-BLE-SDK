//
//  HwWorkoutPoint.h
//  HwBluetoothSDK
//
//  Created by HuaWo on 2022/1/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HwWorkoutPoint : NSObject

@property (assign, nonatomic) long time;
@property (assign, nonatomic) long offsetTime;
@property (assign, nonatomic) NSInteger step;
@property (assign, nonatomic) NSInteger calories;
@property (assign, nonatomic) NSInteger distance;
@property (assign, nonatomic) NSInteger duration;
@property (assign, nonatomic) NSInteger bpm;

- (BOOL) isSuspended;
- (BOOL) isSuspendedEnd;

@end

NS_ASSUME_NONNULL_END
