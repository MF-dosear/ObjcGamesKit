//
//  XGRole.h
//  X-SDK
//
//  Created by dosear on 2021/7/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XGRole : NSObject

/// 服务器名字
@property (nonatomic, copy) NSString *server_name;
/// 游戏区服
@property (nonatomic, copy) NSString *server_id;
/// 角色名
@property (nonatomic, copy) NSString *role_name;
/// 角色id
@property (nonatomic, copy) NSString *role_id;
/// 角色等级
@property (nonatomic, copy) NSString *role_level;
/// Vip等级
@property (nonatomic, copy) NSString *pay_level;

@end

NS_ASSUME_NONNULL_END
