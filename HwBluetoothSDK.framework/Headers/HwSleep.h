//
//  HwSleep.h
//  Pods
//
//  Created by HuaWo on 2022/6/22.
//

#import <Foundation/Foundation.h>
#import "HwSleepPoint.h"

NS_ASSUME_NONNULL_BEGIN

@interface HwSleep : NSObject

@property(nonatomic, assign) NSTimeInterval startTime;
@property(nonatomic, assign) NSTimeInterval endTime;

@property(nonatomic, assign) NSUInteger awakeDuration;
@property(nonatomic, assign) NSUInteger lightDuration;
@property(nonatomic, assign) NSUInteger deepDuration;
@property(nonatomic, assign) NSUInteger remDuration;
@property(nonatomic, assign) NSUInteger totalDuration;
@property(nonatomic, assign) NSUInteger awakeCount;
@property(nonatomic, copy) NSArray<HwSleepPoint *> *sleepPoints;

+ (NSArray<HwSleep *> *) fromSleepPoints:(NSArray<HwSleepPoint *> *)sleepPoints;

@end

NS_ASSUME_NONNULL_END
