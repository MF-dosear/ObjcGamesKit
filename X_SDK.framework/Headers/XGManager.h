//
//  XGManager.h
//  X-SDK
//
//  Created by dosear on 2021/7/7.
//

#import <UIKit/UIKit.h>

#import "Singleton.h"

#import "XGConfig.h"
#import "XGBlock.h"
#import "XGOrder.h"
#import "XGRole.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XGShareMode) {
    XGShareModeWX,
    XGShareModeQQ
};

@interface XGManager : NSObject
singleton_interface(XGManager)

/// 内含崩溃预防 和 修复功能，请在didFinishLaunchingWithOptions方法最前调用
/// @param app application
/// @param options application
/// @param config launchOptions
+ (void)sdk_application:(UIApplication *)app didFinishWithOptions:(NSDictionary *)options config:(XGConfig *)config;

/// Appdelegate 内部实现
/// @param url url
+ (BOOL)sdk_handleOpenUrl:(NSURL *)url;

/// Appdelegate 内部实现
/// @param userActivity userActivity
+ (BOOL)sdk_handleOpenUniversalLink:(NSUserActivity *)userActivity;

/// 初始化
/// @param block 回调
+ (void)sdk_initWithBlock:(XGInitBack)block;

/// 登录
/// @param block 登录回调 flag = true 成功 username, uid, session
+ (void)sdk_loginWithBlock:(XGLoginBack)block;

/// 上传角色
/// @param role 角色信息
/// @param block 回调
+ (void)sdk_roleWithRole:(XGRole *)role block:(XGRoleBack)block;

/// 登出
+ (void)sdk_logout;

/// 登出回调
/// @param block 回调
+ (void)sdk_logoutWithBlock:(XGLogoutBack)block;

/// 支付
/// @param role 角色
/// @param order 订单信息
/// @param block 回调
+ (void)sdk_psyWithRole:(XGRole *)role order:(XGOrder *)order block:(XGPsyBack)block;

/// 打开链接
/// @param api 链接
+ (void)sdk_openApi:(NSString *)api;

/// 分享
/// @param mode 类型
/// @param title 标题
/// @param text 详细内容
/// @param url 链接
/// @param icon 缩略图
+ (void)sdk_shareWithMode:(XGShareMode)mode title:(NSString *)title text:(NSString *)text url:(NSString *)url icon:(UIImage *)icon;

/// 分享 文本
/// @param mode 类型
/// @param title 标题
/// @param text 详细内容
+ (void)sdk_shareWithMode:(XGShareMode)mode title:(NSString *)title text:(NSString *)text;

/// 分享 图片
/// @param mode 类型
/// @param data 图片数据源
+ (void)sdk_shareWithMode:(XGShareMode)mode data:(NSData *)data;



@end

NS_ASSUME_NONNULL_END
