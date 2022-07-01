//
//  HwLanguageUtil.h
//  Pods
//
//  Created by HuaWo on 2022/6/15.
//

#import <Foundation/Foundation.h>
#import "HwDeviceDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface HwLanguageUtil : NSObject

/**
 Returns the prefix of multilingual types that can be processed by the SDK. If not, returns English;
 Currently, the types of languages that can be processed are:
 1. Chinese
 2. English
 3. Arab
 4. Germany
 5. Greece
 6. Spanish
 7. Hebrew
 8. Italian
 9. Korean
 10. Dutch
 11. Polish
 12. Portuguese
 13. Russian
 14. Sweden
 15. Thai
 16. Czech
 17. Romania
 18. Hungary
 19. Hindi
 20. Vietnamese
 21. French
 22. Japanese
 */
+ (NSString *) phoneLanguagePrefix;

/**
 Default is English
 */
+ (HwLanguage) getPhoneLanguage;

@end

NS_ASSUME_NONNULL_END
