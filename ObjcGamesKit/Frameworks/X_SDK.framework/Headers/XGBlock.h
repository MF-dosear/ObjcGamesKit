//
//  XGBlock.h
//  X-SDK
//
//  Created by dosear on 2021/7/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^XGInitBack)(BOOL flag);    // 初始化
typedef void(^XGLoginBack)(BOOL flag, NSString *username, NSString *uid, NSString *token);   // 登录
typedef void(^XGRoleBack)(BOOL flag);    // 角色上报
typedef void(^XGLogoutBack)(BOOL flag);  // 切换账号
typedef void(^XGPsyBack)(BOOL flag);     // 支付

@interface XGBlock : NSObject

/// 初始化
@property (nonatomic, copy) XGInitBack   init_block;
/// 登录
@property (nonatomic, copy) XGLoginBack  login_block;
///// 角色上报
//@property (nonatomic, copy) XGRoleBack   role_block;
/// 切换账号
@property (nonatomic, copy) XGLogoutBack logout_block;
/// 支付
@property (nonatomic, copy) XGPsyBack    psy_block;

@end

NS_ASSUME_NONNULL_END
