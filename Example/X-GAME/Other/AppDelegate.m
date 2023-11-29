//
//  AppDelegate.m
//  X-GAME
//
//  Created by dosear on 2021/7/7.
//

#import "AppDelegate.h"
#import "X_GAME-Swift.h"
#import "XGameVC.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    XGConfig *config = [[XGConfig alloc] init];
    config.isDebug = true;
    config.app_id = @"9527";
    config.app_key = @"GH545FG5H45FG54H5";
    config.apple_id = @"1599832890";
    config.oneLogin = @"87af75cd9fb8b499fe300eef51e6834e";
    config.qq_appid = @"1105577320";
    config.wx_appid = @"wx821689c8c7bb9cd3";
    config.link = @"https://www.dosear.cn";
    config.link_suffix = @"sdk";
    
    [XGManager sdk_application:application didFinishWithOptions:launchOptions config:config];
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor blackColor];
    [self.window makeKeyAndVisible];
    
    XGameVC *vc = [[XGameVC alloc] initWithNibName:@"XGameVC" bundle:nil];
    
    // 加载动画
//    XGLaunchVC *lauch_vc = [[XGLaunchVC alloc] init];
//    lauch_vc.rootvc = vc;
    self.window.rootViewController = vc;
    
    return YES;
}

#pragma mark --分享
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options{

    return  [XGManager sdk_handleOpenUrl:url];
}

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler{

    return  [XGManager sdk_handleOpenUniversalLink:userActivity];
}

@end
