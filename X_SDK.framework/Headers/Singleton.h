//
//  Singleton.h
//  CSSSDK
//
//  Created by CSS on 2020/8/10.
//  Copyright © 2021 Paul. All rights reserved.
//

#define singleton_interface(className) +(instancetype)shared##className;

//  .m文件
//ARC情况下
#if __has_feature(objc_arc)
#define singleton_implementation(className)\
static id instance; \
+ (instancetype)allocWithZone:(struct _NSZone *)zone{\
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        instance = [super allocWithZone:zone]; \
    }); \
    return instance; \
} \
+ (instancetype)shared##className { \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        instance = [[self alloc] init]; \
    }); \
    return instance; \
} \
- (id)copyWithZone:(NSZone *)zone { \
    return instance; \
}
#else
//MRC模式下
#define singleton_implementation(className)\
static id instance;\
+ (instancetype)allocWithZone:(struct _NSZone *)zone{ \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        instance = [super allocWithZone:zone]; \
    }); \
    return instance; \
} \
+ (instancetype)shared##className { \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        instance = [[self alloc] init]; \
    }); \
    return instance; \
} \
- (id)copyWithZone:(NSZone *)zone { \
    return instance; \
} \
- (oneway void)release {} \
- (instancetype)retain {return instance;} \
- (instancetype)autorelease {return instance;} \
- (NSUInteger)retainCount {return ULONG_MAX;}

#endif
