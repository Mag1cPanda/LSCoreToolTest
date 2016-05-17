# LSCoreToolTest
核心功能库——工具类库


##工具类核心功能库（版本1.0）
包括`宏定义`、`通用工具`类和常用`category（类别）`

##一、宏定义

索引：

```objc

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
#define WeakSelf(weakSelf) __weak __typeof(&*self)weakSelf = self

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
#define LSApplication [UIApplication sharedApplication]

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

##二、通用工具类
方法列表

```objc

#pragma mark 获取屏幕宽度
+(CGFloat)getUIScreenWidth;

#pragma mark 获取屏幕高度
+(CGFloat)getUIScreenHeight;

#pragma mark 系统版本
+(float)getVersion;

#pragma mark 状态栏高度
+(int)getStatusBarHeight;

#pragma mark 导航栏高度
+(CGFloat)getnavigationBarHeight:(UINavigationController *)nav;

#pragma mark 导航栏高度和状态栏的总高度
+(CGFloat)getStatusBarAndnavigationBarHeight:(UINavigationController *)nav;

#pragma mark 加密
+(NSString *)encryption:(NSString *)content mark:(int)mark;

#pragma mark 图片缩放
+(UIImage*) originImage:(UIImage *)image scaleToSize:(CGSize)size;

#pragma mark 图片的旋转
+ (UIImage *)image:(UIImage *)image rotation:(UIImageOrientation)orientation;

#pragma mark 根据格式获取当前时间
+(NSString *)getCurrentTimeByFormal:(NSString *)formal;

#pragma mark 获取图片的大小（单位为K）
+(NSNumber *)getImageBig:(UIImage *)image;

#pragma mark 获取设备名称
+(NSString *)getCurrentDeviceName;

#pragma mark 获取唯一表示符
+(NSString *)getIdentifierForVendor;

#pragma mark 返回key值
+(NSString *)getKey;

#pragma mark 将字典写入文件中
+(BOOL)DicWrite2File:(NSString *) dicPath fileName:(NSString *)fileName Dic:(NSDictionary *)dic;

#pragma mark 获取当前时间戳
+(long)getCurrentTime;

#pragma mark 判断一个字符串是否全部为数字
+ (BOOL)isPureInt:(NSString *)string;

#pragma mark 设置UITextField距离左边的距离
+(void)setTextFieldLeftPadding:(UITextField *)textField forWidth:(CGFloat)leftWidth;

#pragma mark - 车牌号正则验证
+ (BOOL)validateCarNo:(NSString *)carNo;

#pragma mark - 根据字符串计算size
+(CGSize)sr_DrawTextRectWithString:(NSString *)text Width:(CGFloat)width FondSize:(CGFloat)fontSize;
#pragma mark - 转json
+ (NSString*)objectToJson:(NSObject *)object;

#pragma mark - json字符串转字典
+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;

#pragma mark - 16进制颜色
+ (UIColor *)colorWithHexString:(NSString *)color;

//color:支持@“#123456”、 @“0X123456”、 @“123456”三种格式
+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

#pragma mark - NSUserDefaults方法
+(void)saveNSUserDefaultsForInteger:(NSInteger)value forKey:(NSString *)key;

+(void)saveNSUserDefaultsForFloat:(float)value forKey:(NSString *)key;

+(void)saveNSUserDefaultsForDouble:(double)value forKey:(NSString *)key;

+(void)saveNSUserDefaultsForBOOL:(BOOL)value forKey:(NSString *)key;

+(void)saveNSUserDefaultsForObject:(id)value forKey:(NSString *)key;

+(id)getDataForKey:(NSString *)key;

+(void)removeAllUserDefaults;  //移除所有本地用户信息

```

##三、常用类别
类别列表
```objc
"UIView+CornerRadius.h"
//通过xib给view添加圆角

"UIView+Frame.h"
"UIViewExt.h"
//通过更简便的方式去访问和设置view的frame

```
