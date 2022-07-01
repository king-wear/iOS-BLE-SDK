//
//  HwHeartrateFatigues.h
//  Pods
//
//  Created by HuaWo on 2022/6/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HwHeartrateFatigue : NSObject

@property(nonatomic, assign) NSInteger hIndex;
@property(nonatomic, assign) long time;
@property(nonatomic, assign) NSInteger fatigue; ///<心率疲劳值(心率变异性)
@property(nonatomic, assign) NSInteger stress; ///<压力值>
@property(nonatomic, assign) NSInteger bloodOxygen;

@end

NS_ASSUME_NONNULL_END
