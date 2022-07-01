//
//  HwSocialSwitch.h
//  HwBluetoothSDK
//
//  Created by HuaWo on 2022/1/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, HwSocialSwitchType) {
    HwSocialSwitchTypeMissCalls = 0x00,
    HwSocialSwitchTypeMessage = 0x01,
    HwSocialSwitchTypeSocial = 0x02,
    HwSocialSwitchTypeEmail = 0x03,
    HwSocialSwitchTypeCalendar = 0x04,
    HwSocialSwitchTypeCalls = 0x05,
    HwSocialSwitchTypeCallsHangup = 0x06,//来电挂断
    HwSocialSwitchTypeWechat = 0x07,
    HwSocialSwitchTypeViber = 0x08,
    HwSocialSwitchTypeSnapchat = 0x09,
    HwSocialSwitchTypeWhatsApp = 0x0A,
    HwSocialSwitchTypeQQ = 0x0B,
    HwSocialSwitchTypeFacebook = 0x0C,
    HwSocialSwitchTypeHangouts = 0x0D,
    HwSocialSwitchTypeGmail = 0x0E,
    HwSocialSwitchTypeMessenger = 0x0F,
    HwSocialSwitchTypeInstagram = 0x10,
    HwSocialSwitchTypeTwitter = 0x11,
    HwSocialSwitchTypeLinkedin = 0x12,
    HwSocialSwitchTypeUber = 0x13,
    HwSocialSwitchTypeLine = 0x14,
    HwSocialSwitchTypeSkype = 0x15,
    HwSocialSwitchTypeBooking = 0x17,
    HwSocialSwitchTypeAirbnb = 0x18,
    HwSocialSwitchTypeFlipboard = 0x19,
    HwSocialSwitchTypeTelegram = 0x1A,
    HwSocialSwitchTypePandora = 0x1B,
    HwSocialSwitchTypeSpotify = 0x1C,
    HwSocialSwitchTypeDropbox = 0x1D,
    HwSocialSwitchTypeShazam = 0x1E,
    HwSocialSwitchTypeLyft = 0x1F,
    HwSocialSwitchTypeWaze = 0x20,
    HwSocialSwitchTypeSlack = 0x21,
    HwSocialSwitchTypeDeliveroo = 0x22,
    HwSocialSwitchTypePinterest = 0x23,
    HwSocialSwitchTypeNetflix = 0x24,
    HwSocialSwitchTypeYoutube = 0x25,
    HwSocialSwitchTypeGoogleMap = 0x26,
    HwSocialSwitchTypeAirFrance = 0x2A,
    HwSocialSwitchTypeBfmtv = 0x2B,
    HwSocialSwitchTypeBusinessInsider = 0x2C,
    HwSocialSwitchTypeCNNBreaking = 0x2D,
    HwSocialSwitchTypeIGeneration = 0x2E,
    HwSocialSwitchTypeLemonde = 0x2F,
    HwSocialSwitchTypeSpark = 0x30,
    HwSocialSwitchTypeOther = 0x31,//其他
    HwSocialSwitchTypeEspn = 0x32,
    HwSocialSwitchTypeVenmo = 0x33,
    HwSocialSwitchTypeCash = 0x34,
    HwSocialSwitchTypeTinder = 0x35,
    HwSocialSwitchTypeBumble = 0x36,
    HwSocialSwitchTypeBankOfAmericaMobile = 0x37,
    HwSocialSwitchTypeWellsFargoMobile = 0x38,
    HwSocialSwitchTypeOutlook = 0x39,
    HwSocialSwitchTypeLeFigaro = 0x3A,
    HwSocialSwitchTypeMorandiniBlog = 0x3B,
    HwSocialSwitchTypeIndiegogo = 0x3C,
    HwSocialSwitchTypeKickstarter = 0x3D,
    HwSocialSwitchTypeStripeDashboard = 0x3E,
    HwSocialSwitchTypeKLM = 0x3F,
    HwSocialSwitchTypeEasyJet = 0x40,
    HwSocialSwitchTypeSWISS = 0x41,
    HwSocialSwitchTypeLufthansa = 0x42,
    HwSocialSwitchTypeAmericanAirlines = 0x43,
    HwSocialSwitchTypeFlyDelta = 0x44,
    HwSocialSwitchTypeJetSmarter = 0x45,
    HwSocialSwitchTypeDiDi = 0x46,
    HwSocialSwitchTypeUberEats = 0x47,
    HwSocialSwitchTypeOpenTable = 0x48,
    HwSocialSwitchTypeMention = 0x49,
    HwSocialSwitchTypeSwissQuote = 0x4A,
    HwSocialSwitchTypeDiagralConnect = 0x4B,
    HwSocialSwitchTypeNest = 0x4C,
    HwSocialSwitchTypeNetatmoSecurity = 0x4D,
    HwSocialSwitchTypeUBSFinancial = 0x4E,
    HwSocialSwitchTypeN26MobileBank = 0x4F,
    HwSocialSwitchTypeKakaoTalk = 0x50,
    HwSocialSwitchTypeAmazon = 0x51,
    HwSocialSwitchTypeEbay = 0x52,
    HwSocialSwitchTypePaypal = 0x53,
    HwSocialSwitchTypeWeibo = 0x54,
    HwSocialSwitchTypeYelp = 0x55,
    HwSocialSwitchTypeGoogleDrive = 0x56,
    HwSocialSwitchTypeTikTok = 0x57,
    HwSocialSwitchTypeLetgo = 0x58,
    HwSocialSwitchTypeOfferUp = 0x59,
    HwSocialSwitchTypeStarbucks = 0x5A,
    HwSocialSwitchTypeTumblr = 0x5B,
    HwSocialSwitchTypeYolo = 0x5C,
    HwSocialSwitchTypeDingDing = 0x5D,
    HwSocialSwitchTypeAzar = 0x5E,
    HwSocialSwitchTypeBadoo = 0x5F,
    HwSocialSwitchTypeBigoLive = 0x60,
    HwSocialSwitchTypeDiscord = 0x61,
    HwSocialSwitchTypeHago = 0x62,
    HwSocialSwitchTypeHelo = 0x63,
    HwSocialSwitchTypeKik = 0x64,
    HwSocialSwitchTypeMomo = 0x65,
    HwSocialSwitchTypeQqSpace = 0x66,
    HwSocialSwitchTypeRedBook = 0x67,
    HwSocialSwitchTypeSharechat = 0x68,
    HwSocialSwitchTypeTantan = 0x69,
    HwSocialSwitchTypeTruecaller = 0x6A,
    HwSocialSwitchTypeUC = 0x6B,
    HwSocialSwitchTypeZepeto = 0x6C,
    HwSocialSwitchTypeCoronaWarnApp = 0x6D,
    HwSocialSwitchTypeHangout = 0x6E,
    HwSocialSwitchTypeGoogleplus = 0x6F,
    HwSocialSwitchTypeFlickr = 0x70,
    HwSocialSwitchTypeVK = 0x71,
    HwSocialSwitchTypeMax = 0xFF
};


@interface HwSocialSwitch : NSObject

@property(nonatomic, assign) BOOL S;
@property(nonatomic, assign) HwSocialSwitchType type;

- (HwSocialSwitch *) initWithType:(HwSocialSwitchType)type
                                s:(BOOL)s;

@end

NS_ASSUME_NONNULL_END
