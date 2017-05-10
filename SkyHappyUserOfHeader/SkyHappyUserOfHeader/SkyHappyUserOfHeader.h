//
//  SkyHappyUserOfHeader.h
//  LRMacroDefinition
//
//  Created by fangd@silviscene.com on 2016/12/15.
//  Copyright © 2016年 scorpio. All rights reserved.
//

#ifndef SkyHappyUserOfHeader_h
#define SkyHappyUserOfHeader_h


//1.获取屏幕宽度与高度
//#define SCREEN_WIDTH   [UIScreen mainScreen].bounds.size.width
//#define SCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height


//需要横屏或者竖屏，获取屏幕宽度与高度
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上

#define SCREEN_WIDTH ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.width)
#define SCREENH_HEIGHT ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.height)
#define SCREEN_SIZE ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale):[UIScreen mainScreen].bounds.size)
#else
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_SIZE [UIScreen mainScreen].bounds.size
#endif

//2.获取通知中心
#define skyNotificationCenter [NSNotificationCenter defaultCenter]

//3.设置颜色
// 颜色
#define skyRGBColor(r, g, b)    [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define skyRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
// 十六进制颜色
#define skyColorWithHex(rgbValue) \
  [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 \
  green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 \
  blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:1.0]
// 随机颜色
#define skyRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]
// clear背景颜色
#define skyClearColor [UIColor clearColor]
// 浅灰颜色
#define skyGrayColor  kRGBColor(220, 220, 220)
// 背景色
#define skyBACKGROUNDCOLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]

//4.加载本地文件
// 图片
#define skyLoadImage(file,type) [UIImageimageWithContentsOfFile:[[NSBundlemainBundle]pathForResource:fileofType:type]]
// 数组
#define skyLoadArray(file,type) [UIImagearrayWithContentsOfFile:[[NSBundlemainBundle]pathForResource:fileofType:type]]
// 字典
#define skyLoadDict(file,type) [UIImagedictionaryWithContentsOfFile:[[NSBundlemainBundle]pathForResource:fileofType:type]]

//5.自定义高效率的 NSLog(开发的时候打印，但是发布的时候不打印的NSLog)
#ifdef DEBUG
#define SLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define SLog(...)
#endif

//6.弱引用(block循环引用)
#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

//7.设置 view 圆角和边框
#define skyViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

//8.由角度转换弧度 由弧度转换角度
#define skyDegreesToRadian(x) (M_PI * (x) / 180.0)
#define skyRadianToDegrees(radian) (radian*180.0)/(M_PI)

//9.字符串是否为空
#define skyStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || ([str length] < 1) ? (YES) : (NO))

//10.数组是否为空
#define skyArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)

//11.获取图片资源
#define skyGetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
//12.获取当前语言
#define skyCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//13.屏幕尺寸
// 状态栏占用高度
#define skyStateBarHeight          20.f
// 状态栏底部y坐标
#define skyOffsetStateBarHeight    ((DEVICE_OS_VERSION_VALUE >= 7.0)? StateBarHeight : 0.f)
// 顶部状态栏占用高度
#define skyTopNavBarHeight         44.f
// 顶部导航栏底部y坐标
#define skyOffsetTopNavBarHeight   (OffsetStateBarHeight + TopNavBarHeight)
// 底部tabbar占用高度
#define skyBottomTabBarHeight      49.f
// 屏幕可操作高度
#define skyMainHeight              ((DEVICE_OS_VERSION_VALUE >= 7.0)? SCREENH_HEIGHT : (SCREENH_HEIGHT - StateBarHeight))
// 屏幕可操作宽度
#define skyMainWidth               SCREEN_WIDTH
// 去除上下导航栏剩余中间视图高度
#define skyContentHeight           (skyMainHeight -skyOffsetTopNavBarHeight -skyBottomTabBarHeight)

//14.判断当前的iPhone设备/系统版本
//判断是否为iPhone
#define sky_IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

//判断是否为iPad
#define sky_IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//判断是否为ipod
#define sky_IS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

// 判断是否为 iPhone 5SE
#define sky_iPhone5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f

// 判断是否为iPhone 6/6s/7
#define sky_iPhone6_6s_7 [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f

// 判断是否为iPhone 6Plus/6sPlus/7Plus
#define sky_iPhone6Plus_6sPlus_7Plus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

//获取系统版本
//这个方法不是特别靠谱
#define sky_IOS_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
//建议使用这个方法
#define sky_IOS_SYSTEM_VERSION_STRING [[UIDevice currentDevice] systemVersion]
//判断 iOS 8 或更高的系统版本
#define IOS_VERSION_8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=8.0)? (YES):(NO))

//15.判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

//16.沙盒目录文件
// NSUserDefaults 实例化
#define skyUserDefaults [NSUserDefaults standardUserDefaults]
//获取temp
#define skyPathTemp NSTemporaryDirectory()

//获取沙盒 Document
#define skyPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

//获取沙盒 Cache
#define skyPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//17.GCD 的宏定义
//GCD - 一次性执行
#define sky_DISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

//GCD - 在Main线程上运行
#define sky_DISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

//GCD - 开启异步线程
#define sky_DISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);

#endif /* SkyHappyUserOfHeader_h */
