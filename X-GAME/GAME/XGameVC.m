//
//  ViewController.m
//  X-GAME
//
//  Created by dosear on 2021/7/7.
//

#import "XGameVC.h"

#import "EgretWebViewLib.h"

@interface XGameVC ()<WKScriptMessageHandler>

@property (weak, nonatomic) IBOutlet UIButton *loginBtn;

@property (weak, nonatomic) IBOutlet UIButton *psyBtn;

@property (weak, nonatomic) IBOutlet UIButton *logoutBtn;

@property (weak, nonatomic) IBOutlet UIButton *shareBtn;

@property (weak, nonatomic) IBOutlet UIButton *fontBtn;

@property (weak, nonatomic) IBOutlet UIImageView *imgView;

@property (assign, nonatomic) BOOL isAddScript;

@end

@implementation XGameVC

- (WKWebView *)webView{
    if (_webView == nil) {
        
        for (UIView *view in self.view.subviews) {
            if ([view isKindOfClass:[WKWebView class]]) {
                _webView = (WKWebView *)view;
                break;
            }
        }
    }
    return _webView;
}

- (BOOL)prefersStatusBarHidden{
    return true;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 初始化
    [EgretWebViewLib initialize:@"/egretGame/preload/"];
    
    NSString *x_bk = @"";
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    if (orientation == UIInterfaceOrientationPortrait || orientation == UIInterfaceOrientationPortraitUpsideDown) {
        
        x_bk = @"h-back";
    }else if (orientation == UIInterfaceOrientationLandscapeLeft || orientation == UIInterfaceOrientationLandscapeRight){
        
        x_bk = @"v-back";
    }
    self.imgView.image = [UIImage imageNamed:x_bk];
    
    // 初始化
    [self sdk_init];
}

/// 初始化
- (void)sdk_init{
    
    // 初始化
//    __weak typeof(self) weakself = self;
    
    
    [XGManager sdk_initWithBlock:^(BOOL flag) {
        
        if (flag) {
            [self sdk_login];
        }
    }];
    
    // 登出回调
    [XGManager sdk_logoutWithBlock:^(BOOL flag) {
        
    }];
}

/// 登录
- (void)sdk_login{
    
    __weak typeof(self) weakself = self;
    [XGManager sdk_loginWithBlock:^(BOOL flag, NSString * _Nonnull username, NSString * _Nonnull uid, NSString * _Nonnull token) {
        
        if (flag) {

            // 开始游戏
            [EgretWebViewLib startLocalServerFromResource];
            [EgretWebViewLib startGame:@"game/index.html" Host:@"http://locahost" SuperView:self.view];
            
            [self.view addSubview:self.psyBtn];
            [self.view addSubview:self.logoutBtn];
            [self.view addSubview:self.shareBtn];
            [self.view addSubview:self.loginBtn];
            [self.view addSubview:self.fontBtn];
            
//            [self.psyBtn removeFromSuperview];
//            [self.logoutBtn removeFromSuperview];
//            [self.shareBtn removeFromSuperview];
//            [self.loginBtn removeFromSuperview];
//            [self.fontBtn removeFromSuperview];
            
            // 上报角色
            [weakself sdk_role];
            
            // 添加事件
            if (weakself.isAddScript == false) {
                
                [weakself.webView.configuration.userContentController addScriptMessageHandler:weakself name:@"toPay"];
                weakself.isAddScript = true;
            }
        }
    }];
}

/// 角色上传
- (void)sdk_role{
    
    XGRole *role = [[XGRole alloc] init];
    role.role_id = @"9527";
    role.role_name = @"罗小黑不吹";
    role.role_level = @"10";
    
    role.pay_level = @"1";
    role.server_id = @"10245";
    role.server_name = @"国际服";
    
    [XGManager sdk_roleWithRole:role block:^(BOOL flag) {
        
    }];
}

- (IBAction)loginAction:(id)sender {
    [self sdk_login];
}

/// 支付
/// @param sender btn
- (IBAction)psyAction:(id)sender {
    
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
}

/// 切换账号
/// @param sender btn
- (IBAction)logoutAction:(id)sender {
    [XGManager sdk_logout];
}

/// 分享0
/// @param sender btn
- (IBAction)shareAction:(id)sender {
    [XGManager sdk_shareWithMode:XGShareModeQQ title:@"分享标题" text:@"分享内容" url:@"https://www.baidu.com" icon:[UIImage imageNamed:@"icon"]];
}

/// 角色上报
- (IBAction)fontAction:(id)sender {
//    [XGManager sdk_fonts];
    [self sdk_role];
}

#pragma mark - WKScriptMessageHandler
- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message{
    
    if ([message.name isEqualToString:@"toPay"]) {
        
        [self psyAction:nil];
    }
}

@end
