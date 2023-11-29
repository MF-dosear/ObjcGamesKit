//
//  XGOrder.h
//  X-SDK
//
//  Created by dosear on 2021/7/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XGOrder : NSObject

/// cp方产生的订单(必传)
@property (nonatomic, copy) NSString *cp_order_id;
/// 支付需要的价格单位(元)(必传)
@property (nonatomic, copy) NSString *price;
/// 商品号(必传)
@property (nonatomic, copy) NSString *good_id;
/// 商品名称
@property (nonatomic, copy) NSString *good_name;
/// 拓展字段
@property (nonatomic, copy) NSString *extends;
/// 回调地址
@property (nonatomic, copy) NSString *notify;

@end

NS_ASSUME_NONNULL_END
