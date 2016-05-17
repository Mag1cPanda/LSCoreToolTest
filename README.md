# LSCoreToolTest
核心功能库——工具类库


##工具类核心功能库（版本1.0）
包括`宏定义`、`通用工具`类和`通用第三方库`

##一、宏定义

索引：

```
/** 字体*/
#define Font(x) [UIFont systemFontOfSize:x]
#define BoldFont(x) [UIFont boldSystemFontOfSize:x]

/** 颜色*/
#define RGBColor(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBAColor(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define RGB16Color(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

/** 输出*/
#ifdef DEBUG
#define LSLog(...) NSLog(__VA_ARGS__)
#else
#define LSLog(...)
#endif

/** 获取硬件信息*/
#define SCREEN_W [UIScreen mainScreen].bounds.size.width
#define SCREEN_H [UIScreen mainScreen].bounds.size.height
#define LSCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])
#define CurrentSystemVersion [[[UIDevice currentDevice] systemVersion] floatValue]


/** 适配*/
#define iOS_7_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
#define iOS_8_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define iOS_9_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)

#define iPhone4_OR_4s    (SXSCREEN_H == 480)
#define iPhone5_OR_5c_OR_5s   (SXSCREEN_H == 568)
#define iPhone6_OR_6s   (SXSCREEN_H == 667)
#define iPhone6Plus_OR_6sPlus   (SXSCREEN_H == 736)
#define iPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

/** 弱指针*/
#define WeakSelf(weakSelf) __weak __typeof(&*self)weakSelf = self;

/** 加载本地文件*/
#define LoadImage(file,type) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]
#define LoadArray(file,type) [UIImage arrayWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]
#define LoadDict(file,type) [UIImage dictionaryWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]

/** 多线程GCD*/
#define GlobalGCD(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MainGCD(block) dispatch_async(dispatch_get_main_queue(),block)

//通知中心
#define LSNotificationCenter [NSNotificationCenter defaultCenter]

//UIApplication
#define LSApplication [UIApplication sharedApplication];

/** 数据存储*/
#define LSUserDefaults [NSUserDefaults standardUserDefaults]
#define LSCacheDir [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]
#define LSDocumentDir [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject]
#define LSTempDir NSTemporaryDirectory()

```

##二、通用工具类
方法列表

```
/** 字体*/
#define Font(x) [UIFont systemFontOfSize:x]
#define BoldFont(x) [UIFont boldSystemFontOfSize:x]

/** 颜色*/
#define RGBColor(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBAColor(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define RGB16Color(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

/** 输出*/
#ifdef DEBUG
#define LSLog(...) NSLog(__VA_ARGS__)
#else
#define LSLog(...)
#endif

/** 获取硬件信息*/
#define SCREEN_W [UIScreen mainScreen].bounds.size.width
#define SCREEN_H [UIScreen mainScreen].bounds.size.height
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])
#define CurrentSystemVersion [[[UIDevice currentDevice] systemVersion] floatValue]


/** 适配*/
#define iOS_7_OR_LATER    CurrentSystemVersion >= 7.0
#define iOS_8_OR_LATER    CurrentSystemVersion >= 8.0
#define iOS_9_OR_LATER    CurrentSystemVersion >= 9.0

#define iPhone4_OR_4s    (SCREEN_H == 480)
#define iPhone5_OR_5c_OR_5s   (SCREEN_H == 568)
#define iPhone6_OR_6s   (SCREEN_H == 667)
#define iPhone6Plus_OR_6sPlus   (SCREEN_H == 736)
#define iPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif


/** 弱指针*/
#define WeakSelf(weakSelf) __weak __typeof(&*self)weakSelf = self;

/** 加载本地文件*/
#define LoadImage(file,type) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]
#define LoadArray(file,type) [UIImage arrayWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]
#define LoadDict(file,type) [UIImage dictionaryWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]

/** 多线程GCD*/
#define GlobalGCD(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MainGCD(block) dispatch_async(dispatch_get_main_queue(),block)

//通知中心
#define LSNotificationCenter [NSNotificationCenter defaultCenter]

//UIApplication
#define LSApplication [UIApplication sharedApplication];

/** 数据存储*/
#define LSUserDefaults [NSUserDefaults standardUserDefaults]
#define LSCacheDir [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]
#define LSDocumentDir [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject]
#define LSTempDir NSTemporaryDirectory()

//由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)


//初始化单例类
#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)shared##classname \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [[self alloc] init]; \
} \
} \
\
return shared##classname; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
\
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
}
```

##三、通用第三方库
###代码添加约束

集成了[PureLayout](https://github.com/PureLayout/PureLayout)
使用方法详情可见[Demo](https://github.com/Mag1cPanda/ALTest-PureLayout-)


###刷新控件

集成了[MJRefresh](https://github.com/CoderMJLee/MJRefresh)
使用方法大家都会，这里就不介绍了


###图片下载

集成了[SDWebImage](https://github.com/rs/SDWebImage)
使用详情请参考github链接

