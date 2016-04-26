//
//  LSEasyMacro.h
//  LSCoreTool
//
//  Created by Mag1cPanda on 16/4/25.
//  Copyright © 2016年 Mag1cPanda. All rights reserved.
//

#ifndef LSEasyMacro_h
#define LSEasyMacro_h

#endif /* LSEasyMacro_h */

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