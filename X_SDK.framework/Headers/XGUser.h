//
//  XGUser.h
//  X-SDK
//
//  Created by Paul on 2021/12/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XGUser : NSObject

/// 用户名
@property (nonatomic, copy) NSString *username;

/// 用户uid
@property (nonatomic, copy) NSString *uid;

/// 用户session
@property (nonatomic, copy) NSString *session;

/// token
@property (nonatomic, copy) NSString *token;

/// phone
@property (nonatomic, copy) NSString *phone;

/// sdk版本
@property (nonatomic, copy) NSString *sdk_version;

/// 真实姓名
@property (nonatomic, copy) NSString *name;

/// 身份证
@property (nonatomic, copy) NSString *id_card;

/// brithday 出生年月
@property (nonatomic, copy) NSString *brithday;

/// 性别 0、未知 1、男 2、女
@property (nonatomic, assign) NSInteger sex;

@end

NS_ASSUME_NONNULL_END
