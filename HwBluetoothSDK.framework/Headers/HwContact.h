//
//  HwContact.h
//  Pods
//
//  Created by HuaWo on 2022/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HwContact : NSObject

//索引
@property(nonatomic, assign) int contactIndex;
@property(nonatomic, copy) NSString *contactName;
@property(nonatomic, copy) NSString *contactPhone;

@end

NS_ASSUME_NONNULL_END
