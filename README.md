



## SDK对接文档地址：http://www.dosear.cn/sdk/sdk_mark.html
## SDK介绍：http://www.dosear.cn/sdk/sdk_function.html
## 过审手游：http://www.dosear.cn/api/web/auditeds

## 对接示例

### 1、资源下载

* Git：https://github.com/MF-dosear/X-Demo.git

### 2、资源文件

* sdk_demo 是sdk demo示例
  * X_SDK.framework 为游戏SDK
  * 其他为demo文件
  * 点击 'X-GAME.xcworkspace' 打开工程测试

![1644917983620](https://user-images.githubusercontent.com/20237339/217759668-5842a3ca-4cc2-4280-bd98-0ce100e4d334.jpg)

  
### 3、SDK导入

* 将sdk添加到xcode工程

![1644918508405](assets/1644918508405.jpg)

* 修改SDK配置

![1644917463108](assets/1644917463108.jpg)

* Build Settings 下搜索 Other Linker Flags，添加 -ObjC
![1644918727771](assets/1644918727771.jpg)



### 4、添加对接代码

* 头文件导入 ‘#import <X_SDK/X_SDK.h>’

```swift
#import <X_SDK/X_SDK.h>
```

* AppDelegate中didFinishLaunchingWithOptions方法内实现以下部分

```swift

    // 内含崩溃预防 和 修复功能，请在didFinishLaunchingWithOptions方法最前调用
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
    
```

* AppDelegate内分享方法实现

```swift
#pragma mark --分享
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options{

    return  [XGManager sdk_handleOpenUrl:url];
}

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler{

    return  [XGManager sdk_handleOpenUniversalLink:userActivity];
}
```

* 初始化

```swift
    [XGManager sdk_initWithBlock:^(BOOL flag) {
        
        if (flag) {
            // 初始化成功，登录

        }
    }];
```

* 登录

```swift
    __weak typeof(self) weakself = self;
    [XGManager sdk_loginWithBlock:^(BOOL flag, NSString * _Nonnull username, NSString * _Nonnull uid, NSString * _Nonnull token) {
        
        if (flag) {

            // 登录成功，开始游戏
        
        }
    }];
```

* 角色上报

```swift
    XGRole *role = [[XGRole alloc] init];
    role.role_id = @"9527";
    role.role_name = @"罗小黑不吹";
    role.role_level = @"10";
    
    role.pay_level = @"1";
    role.server_id = @"10245";
    role.server_name = @"国际服";
    
    [XGManager sdk_roleWithRole:role block:^(BOOL flag) {
        // 上报结果
    }];
```

* 登出or切换账号
```swift
    // 切换账号
    [XGManager sdk_logout];
```

* 登出回调
```swift
    // 登出回调
    [XGManager sdk_logoutWithBlock:^(BOOL flag) {
        
    }];
```

* 支付

```swift
    XGRole *role = [[XGRole alloc] init];
    role.role_id = @"9527";
    role.role_name = @"罗小黑不吹";
    role.role_level = @"10";
    
    role.pay_level = @"1";
    role.server_id = @"10245";
    role.server_name = @"国际服";
    
    XGOrder *order = [[XGOrder alloc] init];
    order.cp_order_id = [NSString stringWithFormat:@"%.0f",[[NSDate date] timeIntervalSince1970]];
    order.price = @"1";
    order.good_id = @"dosear.goods.gold10";
    order.good_name = @"10点券";
    order.extends = @"extends";
    order.notify = @"";
    
    [XGManager sdk_psyWithRole:role order:order block:^(BOOL flag) {
        
        
    }];
```

* 分享

```swift

    [XGManager sdk_shareWithMode:XGShareModeQQ title:@"分享标题" text:@"分享内容" url:@"https://www.baidu.com" icon:[UIImage imageNamed:@"icon"]];

```

* 方法总结

```swift

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

```
