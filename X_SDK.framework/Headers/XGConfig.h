//
//  XGConfig.h
//  X-SDK
//
//  Created by dosear on 2021/7/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XGConfig : NSObject

/// 是否打印SDK的log，默认flase
@property (nonatomic, assign) BOOL isDebug;

/// 苹果id
@property (nonatomic, copy) NSString *apple_id;

/// 游戏id
@property (nonatomic, copy) NSString *app_id;

/// 游戏key
@property (nonatomic, copy) NSString *app_key;

/// qq appid
@property (nonatomic, copy) NSString *qq_appid;

/// wx appid
@property (nonatomic, copy) NSString *wx_appid;

/// 通用链接
@property (nonatomic, copy) NSString *link;

/// 通用链接后缀
@property (nonatomic, copy) NSString *link_suffix;

/// 一键登录
@property (nonatomic, copy) NSString *oneLogin;

@end

NS_ASSUME_NONNULL_END
